#pragma once
#include "bnRandomMettaurMob.h"
#include "bnStarfish.h"
#include "bnCanodumb.h"
#include "bnMegalian.h"
#include "bnCanodumbIdleState.h"
#include "bnBattleItem.h"
#include "bnStringEncoder.h"
#include "bnCard.h"
#include "bnField.h"
#include "bnTile.h"
#include "bnMysteryData.h"
#include "bnGear.h"
#include "bnStarfishIdleState.h"
#include "bnUndernetBackground.h"
#include "bnMetrid.h"
#include "bnFadeInState.h"
#include "bnBunny.h"

RandomMettaurMob::RandomMettaurMob(Field* field) : MobFactory(field)
{
}


RandomMettaurMob::~RandomMettaurMob()
{
}

Mob* RandomMettaurMob::Build()
{
    return nullptr;
}

Mob* RandomMettaurMob::Build(std::vector<std::string> mobNameList)
{
    // Build a mob around the field input
    Mob* mob = new Mob(field);
    auto count = std::max(1, (int)std::floor((rand() % 4)));
    int mobIndex;
    while (mob->GetMobCount() < count) {
        int i = std::round(std::max(1, rand() % field->GetWidth()+1));
        int j = std::round(std::max(1, rand() % field->GetHeight()+1));
        Battle::Tile* tile = field->GetAt(i, j);
        if (tile->GetTeam() == Team::blue && !tile->IsReservedByCharacter()) {
            mobIndex = (int)(rand() % mobNameList.size());
            std::string mobName = mobNameList[mobIndex];
            /*FrozenLake suggests a height check to ensure all mobs are visible on the battlefield. Implement that.*/
            Character::Rank rank = static_cast<Character::Rank>(std::atoi(&mobName[mobName.size() - 1])-1);
            if (mobNameList[mobIndex].find("Mettaur") != std::string::npos) {
                auto spawner = mob->CreateSpawner<Mettaur>(rank);
                spawner.SpawnAt<FadeInState>(i, j);
            }
            else if (mobNameList[mobIndex].find("Canodumb") != std::string::npos) {
                auto spawner = mob->CreateSpawner<Canodumb>(rank);
                spawner.SpawnAt<FadeInState>(i, j);
            }
            else if (mobNameList[mobIndex].find("Metrid") != std::string::npos) {
                auto spawner = mob->CreateSpawner<Metrid>(rank);
                spawner.SpawnAt<FadeInState>(i, j);
            }
            else if (mobNameList[mobIndex].find("Bunny") != std::string::npos) {
                auto spawner = mob->CreateSpawner<Bunny>(rank);
                spawner.SpawnAt<FadeInState>(i, j);
            }
        }
    }
    return mob;
};