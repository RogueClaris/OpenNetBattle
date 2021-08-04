#include "bnTwoMettaurMob.h"
#include "bnField.h"
#include "bnWebClientMananger.h"
#include "bnBuiltInCards.h"
#include "bnFadeInState.h"
#include "bnOwnedCardsUI.h"

namespace {
  static std::vector<Battle::Card> GenCards() {
    auto list = BuiltInCards::cardList;

    int rand_size = (rand() % 4)+1;

    std::vector<Battle::Card> cards;

    return cards;
  }
}

TwoMettaurMob::TwoMettaurMob(Field* field) : MobFactory(field)
{
}


TwoMettaurMob::~TwoMettaurMob()
{
}

Mob* TwoMettaurMob::Build() {
  // Construct a new mob 
  Mob* mob = new Mob(field);

  int count = 3;

  // place a hole somewhere
  field->GetAt( 4 + (rand() % 3), 1 + (rand() % 3))->SetState(TileState::volcano);
  field->GetAt(1, 1)->SetState(TileState::volcano);

  while (count > 0) {
    for (int i = 0; i < field->GetWidth(); i++) {
      for (int j = 0; j < field->GetHeight(); j++) {
        Battle::Tile* tile = field->GetAt(i + 1, j + 1);

        if (tile->IsWalkable() && !tile->IsReservedByCharacter() && tile->GetTeam() == Team::blue) {
          if (rand() % 50 > 25 && count-- > 0) {
            auto spawner = mob->CreateSpawner<Mettaur>(Mettaur::Rank::Rare2);
            Mob::Mutator* mutator = spawner.SpawnAt<FadeInState>(i + 1, j + 1);

            // randomly spawn met with random card list
            // provided from our available built-in card list
            if (rand() % 50 > 25) {
              mutator->Mutate([mob](Character& in) {
                OwnedCardsUI* ui = in.CreateComponent<OwnedCardsUI>(&in);
                ui->AddCards(::GenCards());
                ui->setPosition(0, -in.GetHeight());
                });
            }
          }
        }
      }
    }
  }

  return mob;
}
