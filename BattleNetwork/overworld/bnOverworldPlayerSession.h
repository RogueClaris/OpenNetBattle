#pragma once

#include "../bnEmotions.h"
#include "../bnInbox.h"
#include "../bnCardFolderCollection.h"
#include "../bnCardLibrary.h"
#include "../bnSubchips.h"
#include "../bnBuiltInSubchips.h"
#include <map>

namespace Overworld {
    struct PlayerSession {
        int health{};
        int maxHealth{};
        int money{};
        Emotion emotion{};
        Inbox inbox;
        std::string mapName;
        sf::Vector3f playerPos;
        CardFolderCollection folders;
        CardLibrary pack;
    };
    class SessionSaver {
    private:
        std::map<std::string, int> sizes;
    public:
        PlayerSession LoadGameSession(std::string loadPath);
        bool SaveGameSession(std::string savePath, PlayerSession& sessionToSave);
    };
}