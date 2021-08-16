#include "bnDreamSwordCardAction.h"
#include "bnCardAction.h"
#include "bnSpriteProxyNode.h"
#include "bnTextureResourceManager.h"
#include "bnAudioResourceManager.h"
#include "bnBasicSword.h"
#include "bnSwordEffect.h"

DreamSwordCardAction::DreamSwordCardAction(Character& actor, int damage) : SwordCardAction(actor, damage) {
  DreamSwordCardAction::damage = damage;
}

DreamSwordCardAction::~DreamSwordCardAction()
{
}

void DreamSwordCardAction::OnSpawnHitbox(Entity::ID_t userId)
{
  auto& actor = GetActor();
  auto field = actor.GetField();

  int step = actor.GetFacing() == Direction::left ? -1 : 1;
  int step2 = actor.GetFacing() == Direction::left ? -2 : 2;
  auto tiles = std::vector{
    actor.GetTile()->Offset(step, 0),
    actor.GetTile()->Offset(step, 1),
    actor.GetTile()->Offset(step, -1),
    actor.GetTile()->Offset(step2, 0),
    actor.GetTile()->Offset(step2, 1),
    actor.GetTile()->Offset(step2, -1)

  };

  SwordEffect* e = new SwordEffect;

  if (step == -1) {
    e->setScale(-2.f, 2.f);
  }

  e->SetAnimation("DREAM");
  field->AddEntity(*e, *tiles[0]);

  BasicSword* b = new BasicSword(actor.GetTeam(), damage);
  auto props = b->GetHitboxProperties();
  props.aggressor = userId;
  b->SetHitboxProperties(props);

  Audio().Play(AudioType::DREAMSWORD);
  field->AddEntity(*b, *tiles[0]);

  b = new BasicSword(actor.GetTeam(), damage);
  b->SetHitboxProperties(props);
  field->AddEntity(*b, *tiles[1]);

  b = new BasicSword(actor.GetTeam(), damage);
  b->SetHitboxProperties(props);
  field->AddEntity(*b, *tiles[2]);

  b = new BasicSword(actor.GetTeam(), damage);
  field->AddEntity(*b, *tiles[3]);

  b = new BasicSword(actor.GetTeam(), damage);
  b->SetHitboxProperties(props);
  field->AddEntity(*b, *tiles[4]);

  b = new BasicSword(actor.GetTeam(), damage);
  b->SetHitboxProperties(props);
  field->AddEntity(*b, *tiles[5]);
}