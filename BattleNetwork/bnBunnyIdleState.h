#pragma once
#include "bnAIState.h"

class Bunny;

class BunnyIdleState : public AIState<Bunny>
{
  double cooldown; /*!< How long to wait before moving */
public:

  /**
   * @brief Sets default cooldown to 1 second
   */
  BunnyIdleState();
  
  /**
   * @brief deconstructor
   */
  ~BunnyIdleState();

  /**
   * @brief Sets animation to correct rank color met 
   * @param met
   * 
   * If SP met, cooldown is set to 0.5 seconds
   */
  void OnEnter(Bunny& met);
  
  /**
   * @brief When cooldown hits zero, changes to BunnyMoveState
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

