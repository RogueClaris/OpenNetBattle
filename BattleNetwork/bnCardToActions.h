#pragma once
#include "bnFishy.h"
#include "bnTile.h"
#include "bnAura.h"
#include "bnWindRackCardAction.h"
#include "bnZapringCardAction.h"
#include "bnAirHockeyCardAction.h"
#include "bnHubBatchCardAction.h"
#include "bnMachGunCardAction.h"
#include "bnCannonCardAction.h"
#include "bnZetaCannonCardAction.h"
#include "bnAirShotCardAction.h"
#include "bnTwinFangCardAction.h"
#include "bnTornadoCardAction.h"
#include "bnFireBurnCardAction.h"
#include "bnElecSwordCardAction.h"
#include "bnSwordCardAction.h"
#include "bnWideSwordCardAction.h"
#include "bnLongSwordCardAction.h"
#include "bnDreamSwordCardAction.h"
#include "bnVulcanCardAction.h"
#include "bnReflectCardAction.h"
#include "bnYoYoCardAction.h"
#include "bnBombCardAction.h"
#include "bnCrackShotCardAction.h"
#include "bnRecoverCardAction.h"
#include "bnThunderCardAction.h"
#include "bnElecPulseCardAction.h"
#include "bnDarkTornadoCardAction.h"
#include "bnRollCardAction.h"
#include "bnProtoManCardAction.h"
#include "bnCubeCardAction.h"
#include "bnAuraCardAction.h"
#include "bnAntiDmgCardAction.h"
#include "bnAreaGrabCardAction.h"
#include "bnInvisCardAction.h"
#include "bnInvalidCardAction.h"
/***
 * all of this code will be tossed out when scripting cards is complete. 
 * This is for demonstration of the engine until we have scripting done
 */

static CardAction* CardToAction(const Battle::Card& card, Character& character) {
  // Identify the card by the name
  std::string name = card.GetShortName();
  CardAction* next{nullptr};
  
  if (name.substr(0, 4) == "Atk+") {
    next = new InvalidCardAction(character);
  }else if (name.substr(0, 5) == "Recov") {
    next = new RecoverCardAction(character, card.GetUnmoddedProps().damage);
  }
  else if (name == "CrckPanel") {
    // Crack the top, middle, and bottom row in front of player

    int dir = character.GetTeam() == Team::red ? 1 : -1;

    Battle::Tile* top = character.GetField()->GetAt(character.GetTile()->GetX() + dir, 1);
    Battle::Tile* mid = character.GetField()->GetAt(character.GetTile()->GetX() + dir, 2);
    Battle::Tile* low = character.GetField()->GetAt(character.GetTile()->GetX() + dir, 3);

    // If the tiles are valid, set their state to CRACKED
    if (top) { top->SetState(TileState::cracked); }
    if (mid) { mid->SetState(TileState::cracked); }
    if (low) { low->SetState(TileState::cracked); }

    character.Audio().Play(AudioType::PANEL_CRACK);
  }
  else if (name.substr(0, 4) == "YoYo") {
    next = new YoYoCardAction(character, card.GetDamage());
  }
  else if (name == "Invis") {
    next = new InvisCardAction(character);
  }
  else if (name.substr(0, 7) == "Rflectr") {
    next = new ReflectCardAction(character, card.GetDamage(), ReflectShield::Type::yellow);
  }
  else if (name.substr(0, 11) == "Zeta Cannon") {
    next = new ZetaCannonCardAction(character, card.GetDamage());
  }
  else if (name == "TwinFang") {
    next = new TwinFangCardAction(character, card.GetDamage());
  }
  else if (name == "Tornado") {
    next = new TornadoCardAction(character, card.GetDamage());
  }
  else if (name == "DarkTorn") {
    next = new DarkTornadoCardAction(character, card.GetDamage());
  }
  else if (name == "ElecSwrd") {
    next = new ElecSwordCardAction(character, card.GetDamage());
  }
  else if (name.substr(0, 7) == "FireBrn") {
    auto type = FireBurn::Type(std::atoi(name.substr(7, 1).c_str()));
    next = new FireBurnCardAction(character, type, card.GetDamage());
  }
  else if (name.substr(0, 6) == "Vulcan") {
    next = new VulcanCardAction(character, card.GetDamage());
  }
  else if (name.size() >= 6 && name.substr(0, 6) == "Cannon") {
    next = new CannonCardAction(character, CannonCardAction::Type::green, card.GetDamage());
  }
  else if (name == "HiCannon") {
    next = new CannonCardAction(character, CannonCardAction::Type::blue, card.GetDamage());
  }
  else if (name == "M-Cannon") {
    next = new CannonCardAction(character, CannonCardAction::Type::red, card.GetDamage());
  }
  else if (name == "Minibomb") {
    next = new BombCardAction(character, card.GetDamage());
  }
  else if (name == "CrakShot") {
    next = new CrackShotCardAction(character, card.GetDamage());
  }
  else if (name == "Sword") {
    next = new SwordCardAction(character, card.GetDamage());
  }
  else if (name == "ElcPuls1") {
    next = new ElecPulseCardAction(character, card.GetDamage());
  }
  else if (name == "LongSwrd") {
      next = new LongSwordCardAction(character, card.GetDamage());
  }
  else if (name == "Dream Sword") {
      next = new DreamSwordCardAction(character, card.GetDamage());
  }
  else if (name == "WideSwrd") {
    next = new WideSwordCardAction(character, card.GetDamage());
  }
  else if (name == "FireSwrd") {
    auto action = new LongSwordCardAction(character, card.GetDamage());
    action->SetElement(Element::fire);
    next = action;
  }
  else if (name == "AirShot") {
      next = new AirShotCardAction(character, card.GetDamage());
  }
  else if (name == "Zapring") {
      next = new ZapringCardAction(character, card.GetDamage());
  }
  else if (name.substr(0, 7) == "Thunder") {
    next = new ThunderCardAction(character, card.GetDamage());
  }
  else if (name.substr(0, 4) == "Roll") {
    next = new RollCardAction(character, card.GetDamage());
  }
  else if (name == "ProtoMan") {
    next = new ProtoManCardAction(character, card.GetDamage());
  }
  else if (name == "RockCube") {
    next = new CubeCardAction(character);
  }
  else if (name == "AreaGrab") {
    next = new AreaGrabCardAction(character, 10);
  }
  else if (name == "AntiDmg") {
    next = new AntiDmgCardAction(character, card.GetDamage());
  }
  else if (name == "Barrier") {
    next = new AuraCardAction(character, Aura::Type::BARRIER_10);
  }
  else if (name == "Barr100") {
    next = new AuraCardAction(character, Aura::Type::BARRIER_100);
  }
  else if (name == "Barr200") {
    next = new AuraCardAction(character, Aura::Type::BARRIER_200);
  }
  else if (name == "Barr500") {
    next = new AuraCardAction(character, Aura::Type::BARRIER_500);
  }
  else if (name.substr(0, 7) == "MachGun") {
    next = new MachGunCardAction(character, card.GetDamage());
  }
  else if (name == "HubBatch") {
    next = new HubBatchCardAction(character);
  }
  else if (name == "AirHocky") {
    next = new AirHockeyCardAction(character, card.GetDamage());
  }
  else if (name == "WindRack") {
    next = new WindRackCardAction(character, card.GetDamage());
  }

  return next;
}