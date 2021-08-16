#include "bnCardLibrary.h"
#include "bnFileUtil.h"
#include "bnCurrentTime.h"
#include "bnTextureResourceManager.h"
#include <assert.h>
#include <algorithm>
#include <optional>
#include "bnWebClientMananger.h"

CardLibrary::CardLibrary() {
  LoadLibrary();
}


CardLibrary::~CardLibrary() {
}

CardLibrary& CardLibrary::GetInstance() {
  static CardLibrary instance;
  return instance;
}

CardLibrary::Iter CardLibrary::Begin()
{
  return library.begin();
}

CardLibrary::Iter CardLibrary::End()
{
  return library.end();
}

void CardLibrary::ResetLibrary() {
    library.clear();
}

const unsigned CardLibrary::GetSize() const
{
  return (unsigned)library.size();
}

void CardLibrary::AddCard(Battle::Card card)
{
  library.insert(card);
}

bool CardLibrary::IsCardValid(Battle::Card& card)
{
  for (auto i = Begin(); i != End(); i++) {
    if (i->GetShortName() == card.GetShortName() && i->GetCode() == card.GetCode()) {
      return true;
    }
  }

  return false;
}

std::list<char> CardLibrary::GetCardCodes(const Battle::Card& card)
{
  std::list<char> codes;

  for (auto i = Begin(); i != End(); i++) {
    if (i->GetShortName() == card.GetShortName()) {
      codes.insert(codes.begin(), i->GetCode());
    }
  }

  return codes;
}

const int CardLibrary::GetCountOf(const Battle::Card & card)
{
  return int(library.count(card));
}


void CardLibrary::LoadLibrary() {
    auto TMP = new TextureResourceManager();
    for (auto& [key, value] : BuiltInCards::cardList) {
        if (value.IsTaggedAs("Program Advance")) {
            auto icon = TMP->LoadTextureFromFile("resources/cardicons/Program Advance.png");
            auto image = TMP->LoadTextureFromFile("resources/cardimages/Program Advance.png");
            WEBCLIENT.UploadCardData(value.GetUUID(), icon, image);
        }
        else if (value.IsTaggedAs("Navi")) {
            if (value.IsTaggedAs("DS Chip")) {
                auto icon = TMP->LoadTextureFromFile("resources/cardicons/NaviSummonDS.png");
                auto image = TMP->LoadTextureFromFile("resources/cardimages/NaviSummonDS.png");
                WEBCLIENT.UploadCardData(value.GetUUID(), icon, image);
            }
            else if (value.IsTaggedAs("SP Chip")) {
                auto icon = TMP->LoadTextureFromFile("resources/cardicons/NaviSummonSP.png");
                auto image = TMP->LoadTextureFromFile("resources/cardimages/NaviSummonSP.png");
                WEBCLIENT.UploadCardData(value.GetUUID(), icon, image);
            }
            else {
                auto icon = TMP->LoadTextureFromFile("resources/cardicons/NaviSummon.png");
                auto image = TMP->LoadTextureFromFile("resources/cardimages/NaviSummon.png");
                WEBCLIENT.UploadCardData(value.GetUUID(), icon, image);
            }

        }
        else {
            auto icon = TMP->LoadTextureFromFile("resources/cardicons/" + value.GetShortName() + ".png");
            auto image = TMP->LoadTextureFromFile("resources/cardimages/" + value.GetShortName() + ".png");
            WEBCLIENT.UploadCardData(value.GetUUID(), icon, image);
        }
    }
    
    delete TMP;
}

const bool CardLibrary::SaveLibrary(const std::string& path) {
  return false;
}