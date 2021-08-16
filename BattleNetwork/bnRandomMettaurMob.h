/*! \brief Spawns random enemies on random tiles. Anything goes.
 */
#pragma once
#include "bnMobFactory.h"
#include "bnMettaur.h"
#include "bnMettaurIdleState.h"
#include "bnMetrid.h"
#include "bnStarfish.h"
#include "bnCanodumb.h"
#include "bnMegalian.h"
#include "bnCanodumbIdleState.h"
#include "bnBattleItem.h"
#include "bnStringEncoder.h"
#include "bnCard.h"
#include "bnField.h"
#include "bnTile.h"
#include "bnFishy.h"
#include "bnMysteryData.h"
#include "bnStarfishIdleState.h"
#include "bnUndernetBackground.h"

class RandomMettaurMob :
  public MobFactory
{
public:
  RandomMettaurMob(Field* field);
  ~RandomMettaurMob();

  /**
   * @brief Builds and returns the generated mob
   * @return Mob*
   */
  Mob* Build();

  Mob* Build(std::vector<std::string> mobNameList);
};

