#include "bnBunnyIdleState.h"
#include "bnBunnyMoveState.h"
#include "bnAnimationComponent.h"

BunnyIdleState::BunnyIdleState() : cooldown(0.5), AIState<Bunny>() { ; }
BunnyIdleState::~BunnyIdleState() { ; }

void BunnyIdleState::OnEnter(Bunny& bun) {
  auto& animation = *bun.GetFirstComponent<AnimationComponent>();
  cooldown = 0.4f;
  switch (bun.GetRank()) {
  case(Bunny::Rank::_1):
      animation.SetAnimation("IDLE_1");
      break;
  case(Bunny::Rank::_2):
      animation.SetAnimation("IDLE_2");
      break;
  case(Bunny::Rank::_3):
      animation.SetAnimation("IDLE_3");
      break;
  default:
      animation.SetAnimation("IDLE_3");
      break;
  }
  if (bun.MoveCount >= bun.MoveCountBeforeAttack) {
      cooldown = 0.1f;
  }
}

void BunnyIdleState::OnUpdate(double _elapsed, Bunny& bun) {
  cooldown -= _elapsed;

  if (cooldown < 0) {
    bun.ChangeState<BunnyMoveState>();
  }
}

void BunnyIdleState::OnLeave(Bunny& bun) {
}