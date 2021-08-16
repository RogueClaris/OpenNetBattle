#pragma once
#include "bnCharacter.h"
#include "bnBunnyIdleState.h"
#include "bnAI.h"
#include "bnAnimationComponent.h"
#include "bnTextureType.h"
#include "bnMobHealthUI.h"

/*! \brief Basic Bunny enemy */
class Bunny : public Character, public AI<Bunny> {
  friend class BunnyIdleState;
  friend class BunnyMoveState;
  friend class BunnyAttackState;

public:
  using DefaultState = BunnyIdleState;
  int MoveCount = 0;
  int MoveCountBeforeAttack = 8;
    /**
   * @brief Loads animations and gives itself a turn ID
   */
  Bunny(Rank _rank = Rank::_1);

  /**
   * @brief Removes its turn ID from the list of active Bunnys
   */
  ~Bunny();

  /**
   * @brief Uses AI state to move around. Deletes when health is below zero.
   * @param _elapsed in seconds
   */
  void OnUpdate(double _elapsed) override;

  void OnDelete() override;

  /**
   * @brief Get the hit height of this entity
   * @return const float
   */
  const float GetHeight() const override;

private:
  TextureType textureType;
  AnimationComponent* animation;
  DefenseRule* virusBody;
};
