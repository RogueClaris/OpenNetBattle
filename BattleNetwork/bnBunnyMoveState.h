#pragma once
#include "bnAIState.h"
#include "bnBunny.h"
#include "bnTile.h"
#include "bnField.h"

/**
 * @class BunnyMoveState
 * @author mav
 * @date 28/04/19
 * @brief Moves mettaur and decides to attack or pass
 */
class BunnyMoveState : public AIState<Bunny>
{
private:
  bool isMoving{}; /*!< Whether or not move animation is playing */
  int MoveCount = 0;
  int MoveCountBeforeAttack = 10;
public:

  /**
   * @brief constructor
   */
  BunnyMoveState();
  
  /**
   * @brief deconstructor
   */
  ~BunnyMoveState();

  /**
   * @brief does nothing
   * @param met
   */
  void OnEnter(Bunny& met);
  
  /**
   * @brief Tries to move to player. If it can't passes turn
   * @param _elapsed in seconds
   * @param met
   */
  void OnUpdate(double _elapsed, Bunny& met);
  
  /**
   * @brief Does nothing
   * @param met
   */
  void OnLeave(Bunny& met);
};

