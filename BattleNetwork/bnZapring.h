#pragma once
#pragma once
#include "bnSpell.h"
#include "bnAnimationComponent.h"

/*! \brief Zapring fires dead ahead, stunning 1 target.*/
class Zapring : public Spell {
protected:
  AnimationComponent* animation; /*!< Zapring spinning animation */
  double speed; /*!< Faster spinning */
  bool hit;
public:

  /**
   * @brief Sets animation and speed modifier
   * @param tile
   *
   * Speed modifier changes sliding/gliding time
   */
   Zapring(Team _team, int damage, double speed = 1.0, Direction facing = Direction::right);

  /**
   * @brief deconstructor
   */
  ~Zapring();

  /**
   * @brief Counts tile movements to max 3 and then returns to owner tile
   * @param _elapsed in seconds
   */
  void OnUpdate(double _elapsed);

  /**
   * @brief Deals hitbox damage
   * @param _entity
   */
  void Attack(Character* _entity);

  /**
  * @brief If not on the return tile, spawn an explosion
  */
  void OnDelete();

  void OnSpawn(Battle::Tile& start);

  bool CanMoveTo(Battle::Tile* tile);

  void OnCollision(const Character*);
};