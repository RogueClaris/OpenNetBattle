#include "bnBunny.h"
#include "bnBunnyIdleState.h"
#include "bnBunnyAttackState.h"
#include "bnBunnyMoveState.h"
#include "bnExplodeState.h"
#include "bnTile.h"
#include "bnField.h"
#include "bnWave.h"
#include "bnTextureResourceManager.h"
#include "bnAudioResourceManager.h"
#include "bnDefenseVirusBody.h"
#include "bnGame.h"

#define RESOURCE_PATH "resources/mobs/bunny/bunny.animation"

Bunny::Bunny(Rank _rank) :  
  AI<Bunny>(this), 
  Character(_rank) {
  SetTeam(Team::blue);
  setTexture(Textures().GetTexture(TextureType::MOB_BUNNY_ATLAS));
  setScale(2.f, 2.f);
  SetHealth(health);
  
  //Components setup and load
  animation = CreateComponent<AnimationComponent>(this);
  animation->SetPath(RESOURCE_PATH);
  animation->Load();
  switch (GetRank()) {
  case Rank::_1:
      SetName("Bunny");
      animation->SetAnimation("IDLE_1");
      health = 40;
      break;
  case Rank::_2:
      SetName("TuffBunny");
      animation->SetAnimation("IDLE_2");
      health = 90;
      break;
  case Rank::_3:
      SetName("MegaBunny");
      animation->SetAnimation("IDLE_3");
      health = 150;
      break;
  default:
      SetName("DEBUG");
      animation->SetAnimation("IDLE_3");
      health = 1;
      break;
  }

  setScale(2.f, 2.f);

  SetHealth(health);

  animation->OnUpdate(0);

  virusBody = new DefenseVirusBody();
  AddDefenseRule(virusBody);
  SetHeight(getSprite().getGlobalBounds().height);
}

Bunny::~Bunny() {
  delete virusBody;
}

void Bunny::OnDelete() {
  RemoveDefenseRule(virusBody);
  ChangeState<ExplodeState<Bunny>>();
}

void Bunny::OnUpdate(double _elapsed) {
  AI<Bunny>::Update(_elapsed);
}

const float Bunny::GetHeight() const {
  return 22.f;
}