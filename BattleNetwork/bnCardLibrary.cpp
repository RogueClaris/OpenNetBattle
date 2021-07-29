#include "bnCardLibrary.h"
#include "bnFileUtil.h"
#include "bnCurrentTime.h"
#include "bnTextureResourceManager.h"
#include <assert.h>
#include <algorithm>

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
    for (auto i = 0; i < BuiltInCards::cardList.size(); i++) {
        this->AddCard(BuiltInCards::cardList.find(i)->second);
    }
}

const bool CardLibrary::SaveLibrary(const std::string& path) {
  /**
   * Each card has a particular format
   * Lines beginning with pound '#' are comments and are ignored
   * Card name="ProtoMan" cardIndex="139" iconIndex="232" damage="120" type="Normal" codes="*,P" desc="Slices all enmy on field" "ProtoMan appears, stops time,\nand teleports to each open enemy striking once." rarity="5"
   */

  try {
    FileUtil::WriteStream ws(path);

    ws << "# Saved on " << CurrentTime::AsString() << ws.endl();

    for (auto& card : library) {
      ws << "Card name=\"" << card.GetShortName() << "\" cardIndex=\""
         << card.GetUUID() << "\" ";
      ws << "\" damage=\"" << std::to_string(card.GetDamage()) << "\" ";
      ws << "type=\"" << GetStrFromElement(card.GetElement()) << "\" ";

      auto codes = CardLibrary::GetCardCodes(card);

      ws << "codes=\"";

      ws << card.GetCode();

      /*unsigned i = 0;
      for (auto code : codes) {
        ws << code;
        i++;

        if (i != codes.size() - 1) ws << ",";
      }*/

      ws << "\" ";

      ws << "desc=\"" << card.GetDescription() << "\" ";
      ws << "verbose=\""<< card.GetVerboseDescription() << "\" ";

      ws << ws.endl();
    }

    Logger::Log(std::string("library saved successfully. Number of cards saved: ") +
                std::to_string(GetSize()));
    return true;
  } catch(std::exception& e) {
    Logger::Log(std::string("library save failed. Reason: ") + e.what());
  }

  return false;
}