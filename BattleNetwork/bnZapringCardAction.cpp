#include "bnZapringCardAction.h"
#include "bnCardAction.h"
#include "bnSpriteProxyNode.h"
#include "bnTextureResourceManager.h"
#include "bnAudioResourceManager.h"
#include "bnZapring.h"
#include "bnField.h"

#define NODE_PATH "resources/spells/buster_zapring.png"
#define NODE_ANIM "resources/spells/buster_zapring.animation"

#define FRAME1 { 1, 0.05 }
#define FRAME2 { 1, 0.05 }
#define FRAME3 { 1, 0.05 }

#define FRAMES FRAME1, FRAME2, FRAME3

ZapringCardAction::ZapringCardAction(Character& actor, int damage) :
  attachmentAnim(NODE_ANIM), zapring(nullptr),
  CardAction(actor, "PLAYER_SHOOTING") {
  ZapringCardAction::damage = damage;

  attachment = new SpriteProxyNode();
  attachment->setTexture(Textures().LoadTextureFromFile(NODE_PATH));
  attachment->SetLayer(-1);

  attachmentAnim = Animation(NODE_ANIM);
  attachmentAnim.SetAnimation("DEFAULT");

  AddAttachment(actor, "buster", *attachment).UseAnimation(attachmentAnim);

}

ZapringCardAction::~ZapringCardAction()
{
}

void ZapringCardAction::OnExecute(Character* user) {
  // On shoot frame, drop projectile
  auto onFire = [=]() -> void {
    auto actor = &GetActor();

    Audio().Play(AudioType::TOSS_ITEM_LITE);

    Team team = actor->GetTeam();
    Zapring* y = new Zapring(team, damage, 2.0, actor->GetFacing());

    auto props = y->GetHitboxProperties();
    props.aggressor = user->GetID();
    y->SetHitboxProperties(props);
    zapring = y;

    int step = 1;

    if (user->GetFacing() == Direction::left) {
      step = -1;
    }

    auto tile = actor->GetTile()->Offset(step, 0);

    if (tile) {
      actor->GetField()->AddEntity(*y, *tile);
    }
  };

  AddAnimAction(1, onFire);
}

void ZapringCardAction::Update(double _elapsed)
{
  CardAction::Update(_elapsed);
}

void ZapringCardAction::OnAnimationEnd()
{

}

void ZapringCardAction::OnActionEnd()
{
  if (zapring) {
    zapring->Delete();
  }
}
