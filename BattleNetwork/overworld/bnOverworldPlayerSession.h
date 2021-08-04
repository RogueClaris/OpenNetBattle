#pragma once

#include "../bnEmotions.h"
#include "../bnInbox.h"
#include "../bnCardFolderCollection.h"
#include "BuiltInAreas.h"

namespace Overworld {
  struct PlayerSession {
      int health{};
      int maxHealth{};
      int money{};
      Emotion emotion{};
      Inbox inbox;
      sf::Vector3f PlayerPosition{};
      Area area;
  };
}
