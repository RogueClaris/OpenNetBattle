#include "bnCube.h"
#include "bnRockDebris.h"
#include "bnParticlePoof.h"
#include "bnTile.h"
#include "bnDefenseObstacleBody.h"
#include "bnTextureResourceManager.h"
#include "bnShaderResourceManager.h"
#include "bnAudioResourceManager.h"

const int Cube::numOfAllowedCubesOnField = 2;

Cube::Cube(Field* _field) : 
  killLater(false), 
  pushedByDrag(false), 
  animation(nullptr),
  Obstacle(Team::unknown), 
  InstanceCountingTrait<Cube>() {
  setTexture(LOAD_TEXTURE(MISC_CUBE));
  setScale(2.f, 2.f);
  SetFloatShoe(false);
  SetName("Cube");
  //SetTeam(Team::unknown);

  SetHealth(200);
  timer = 30;

  previousDirection = Direction::none;

  defense = new DefenseObstacleBody();
  AddDefenseRule(defense);

  auto props = GetHitboxProperties();
  props.flags |= Hit::impact | Hit::breaking;
  props.damage = 200;
  SetHitboxProperties(props);

  auto impact = [this]() {
    Audio().Play(AudioType::HURT);
  };

  // breaking prop is insta-kill
  auto breaking = [this]() {
    SetHealth(0);
  };


  auto drag = [this]() {
    pushedByDrag = true;
  };

  RegisterStatusCallback(Hit::impact, impact);
  RegisterStatusCallback(Hit::breaking, breaking);
  RegisterStatusCallback(Hit::drag, drag);
}

Cube::~Cube() {
}

bool Cube::CanMoveTo(Battle::Tile * next)
{
  if (next && next->IsWalkable()) {
    if (next->ContainsEntityType<Obstacle>()) {
      bool stop = false;

      auto allEntities = next->FindEntities([&stop, this](Entity* e) -> bool {
        if (this == e) return false;

        Cube* isCube = dynamic_cast<Cube*>(e);

        if (isCube && isCube->GetElement() == Element::ice && GetElement() == Element::ice) {
          Direction dir = GetDirection();
          isCube->Slide(GetTile() + dir, frames(12), frames(0));
          stop = true;
        }
        else if (isCube) {
          stop = true;
        }

        return false;
      });

      if (stop) {
        SetDirection(Direction::none);
        previousDirection = Direction::none;
        pushedByDrag = false;
        return false;
      }
    }

    return true;
  }

  SetDirection(Direction::none);
  previousDirection = Direction::none;
  return false;
}

void Cube::OnUpdate(double _elapsed) {
  // We couldn't spawn correctly
  if (animation->GetAnimationString() == "APPEAR") return;

  if (killLater) {
    Delete();
  }

  // May have just finished sliding
  tile->AffectEntities(this);

  // Keep momentum
  if (!IsSliding() && pushedByDrag) {
    Slide(GetTile() + GetDirection(), frames(12), frames(0));
  }

  if (timer <= 0 ) {
    Delete();
  }

  timer -= _elapsed;
}

// Triggered by health == 0
void Cube::OnDelete() {
  RemoveDefenseRule(defense);
  delete defense;

  if (animation->GetAnimationString() != "APPEAR") {
    int intensity = rand() % 2;
    intensity += 1;

    auto left = (GetElement() == Element::ice) ? RockDebris::Type::LEFT_ICE : RockDebris::Type::LEFT;
    GetField()->AddEntity(*new RockDebris(left, (double)intensity), *GetTile());


    intensity = rand() % 3;
    intensity += 1;
    auto right = (GetElement() == Element::ice) ? RockDebris::Type::RIGHT_ICE : RockDebris::Type::RIGHT;
    GetField()->AddEntity(*new RockDebris(right, (double)intensity), *GetTile());

    auto poof = new ParticlePoof();
    GetField()->AddEntity(*poof, *GetTile());

    Audio().Play(AudioType::PANEL_CRACK);
  }

  Remove();
}

void Cube::OnBattleStop()
{
  Delete();
}

const float Cube::GetHeight() const
{
  return 64.0f;
}

void Cube::Attack(Character* other) {
  if (animation->GetAnimationString() == "APPEAR") return;

  Obstacle* isObstacle = dynamic_cast<Obstacle*>(other);

  if (isObstacle) {
    // breaking prop is insta-kill
    auto props = isObstacle->GetHitboxProperties();
    if ((props.flags & Hit::breaking) == Hit::breaking) {
      return;
    }

    isObstacle->Hit(GetHitboxProperties());
    return;
  }

  Character* isCharacter = dynamic_cast<Character*>(other);

  if (isCharacter && isCharacter != this) {
    killLater = true;
    isCharacter->Hit(GetHitboxProperties());
  }
}

const bool Cube::DidSpawnCorrectly() const
{
  return !killLater;
}

const bool Cube::IsFinishedSpawning() const
{
  return finishedSpawn;
}

void Cube::SetAnimation(std::string animation)
{
  this->animation->SetAnimation(animation);
}

void Cube::OnSpawn(Battle::Tile & start)
{
  animation = CreateComponent<AnimationComponent>(this);
  animation->SetPath("resources/mobs/cube/cube.animation");
  animation->Load();

  animation->OnUpdate(0);

  auto onFinish = [this, &start]() {
    if (start.GetState() == TileState::ice) {
      animation->SetAnimation("ICE");
      SetElement(Element::ice);
      finishedSpawn = true;
    }
    else {
      animation->SetAnimation("NORMAL");
      finishedSpawn = true;
    }
  };

  if (!start.IsWalkable() || start.IsReservedByCharacter({ GetID() })) {
    animation->SetAnimation("APPEAR", 0, [this]() { finishedSpawn = true; });
    killLater = true;
  }
  else {
    animation->SetAnimation("APPEAR", 0, onFinish);

    // delete other cubes present
    std::vector<Cube*> otherCubes;

    field->FindEntities([&otherCubes](Entity* in) mutable {
      if (Cube* o = dynamic_cast<Cube*>(in)) {
        otherCubes.push_back(o);
      }
      return false;
      });

    if (GetCountedSize() > Cube::numOfAllowedCubesOnField) {
      for (auto* cube : otherCubes) {
        if (cube->IsLast()) {
          cube->ToggleTimeFreeze(false);
          cube->Delete(); // Trigger death and deletion
        }
      }
    }
  }
}
