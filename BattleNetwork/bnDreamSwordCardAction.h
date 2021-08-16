#pragma once
#include "bnSwordCardAction.h"
#include "bnAnimation.h"
#include <SFML/Graphics.hpp>

class SpriteProxyNode;
class Character;
class DreamSwordCardAction : public SwordCardAction {
public:
  DreamSwordCardAction(Character& actor, int damage);
  ~DreamSwordCardAction();
  void OnSpawnHitbox(Entity::ID_t userId) override;
};

