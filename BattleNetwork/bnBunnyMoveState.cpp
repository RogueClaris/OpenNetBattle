#include "bnBunnyMoveState.h"
#include "bnBunny.h"
#include "bnTile.h"
#include "bnField.h"
#include "bnBunnyAttackState.h"
#include "bnBunnyIdleState.h"
#include "bnAnimationComponent.h"

BunnyMoveState::BunnyMoveState() : isMoving(false), AIState<Bunny>() { ; }
BunnyMoveState::~BunnyMoveState() { ; }

void BunnyMoveState::OnEnter(Bunny& met) {
    met.animation->SetPlaybackSpeed(1.0);
    switch (met.GetRank()) {
    case(Bunny::Rank::_1):
        met.MoveCountBeforeAttack = 10;
        break;
    case(Bunny::Rank::_2):
        met.MoveCountBeforeAttack = 8;
        break;
    case(Bunny::Rank::_3):
        met.MoveCountBeforeAttack = 6;
        break;
    }
}

void BunnyMoveState::OnUpdate(double _elapsed, Bunny& met) {
  if (isMoving) return; // We're already moving (animations take time)

  Entity* target = met.GetTarget();

  Direction nextDirection = Direction::none;
  std::vector<Direction> dirArr = { Direction::left, Direction::right, Direction::up, Direction::down };
  if (met.MoveCount >= met.MoveCountBeforeAttack) {
      met.animation->SetPlaybackSpeed(2.0);
      Entity* target = met.GetTarget();
      if (target && target->GetTile()) {
          if (target->GetTile()->GetY() < met.GetTile()->GetY()) {
              if (met.CanMoveTo(met.GetTile() + Direction::up)) {
                  nextDirection = Direction::up;
              }
              else if (met.CanMoveTo(met.GetTile() + Direction::left)) {
                  nextDirection = Direction::left;
              }
              else if (met.CanMoveTo(met.GetTile() + Direction::right)) {
                  nextDirection = Direction::right;
              }
          }
          else if (target->GetTile()->GetY() > met.GetTile()->GetY()) {
              if (met.CanMoveTo(met.GetTile() + Direction::down)) {
                  nextDirection = Direction::down;
              }
              else if (met.CanMoveTo(met.GetTile() + Direction::left)) {
                  nextDirection = Direction::left;
              }
              else if (met.CanMoveTo(met.GetTile() + Direction::right)) {
                  nextDirection = Direction::right;
              }
          }
          else {
              // Try attacking if facing an available tile
              met.MoveCount = 0;
              met.animation->SetPlaybackSpeed(1.0);
              return met.ChangeState<BunnyAttackState>();
          }
      }
  }
  else {
      nextDirection = dirArr[rand() % 4];
  }
  if (met.Teleport(met.GetTile() + nextDirection)) {
      auto anim = met.GetFirstComponent<AnimationComponent>();
      auto onFinish = [this, ptr = &met, anim]() {
          switch (ptr->GetRank()) {
          case(Bunny::Rank::_1):
              anim->SetAnimation("MOVE_DOWN_1");
              break;
          case(Bunny::Rank::_2):
              anim->SetAnimation("MOVE_DOWN_2");
              break;
          case(Bunny::Rank::_3):
              anim->SetAnimation("MOVE_DOWN_3");
              break;
          }
          ptr->ChangeState<BunnyIdleState>();
          ptr->MoveCount++;
      };
      switch (met.GetRank()) {
      case(Bunny::Rank::_1):
          anim->SetAnimation("MOVE_UP_1", onFinish);
          break;
      case(Bunny::Rank::_2):
          anim->SetAnimation("MOVE_UP_2", onFinish);
          break;
      case(Bunny::Rank::_3):
          anim->SetAnimation("MOVE_UP_3", onFinish);
          break;
      }
      anim->SetInterruptCallback(onFinish);

      isMoving = true;
  }
  else {
      return;
  }
}

void BunnyMoveState::OnLeave(Bunny& met) {
}
