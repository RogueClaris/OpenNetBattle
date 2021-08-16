#include "bnTextureResourceManager.h"

#include <stdlib.h>
#include <atomic>
#include <sstream>
#include <fstream>
#include <mutex>

using std::ifstream;
using std::stringstream;

void TextureResourceManager::LoadAllTextures(std::atomic<int> &status) {
  TextureType textureType = static_cast<TextureType>(0);
  while (textureType != TextureType::TEXTURE_TYPE_SIZE) {
    status++;

    std::shared_ptr<Texture> texture = LoadTextureFromFile(paths[static_cast<int>(textureType)]);

    //std::scoped_lock lock(mutex);

    textures.insert(pair<TextureType, CachedResource<Texture>>(textureType, texture));
    textureType = (TextureType)(static_cast<int>(textureType) + 1);
  }
}

void TextureResourceManager::LoadImmediately(TextureType type)
{
  //std::scoped_lock lock(mutex);

  // don't fetch it from disk if we already have it
  if (textures.find(type) != textures.end()) return;

  using CachedTexture = CachedResource<Texture>;

  std::shared_ptr<Texture> texture = LoadTextureFromFile(paths[static_cast<int>(type)]);
  textures.insert(pair<TextureType, CachedTexture>(type, CachedTexture(texture, true)));
}

void TextureResourceManager::HandleExpiredTextureCache()
{
  // std::scoped_lock lock(mutex);

  auto iter = texturesFromPath.begin();
  while (iter != texturesFromPath.end()) {
    if (iter->second.GetSecondsSinceLastRequest() > 60.0f) {
      if (iter->second.IsInUse()) {
        iter++; continue;
      }

      // 1 minute is long enough
      Logger::Logf("Texture data %s expired", iter->first.c_str());
      iter = texturesFromPath.erase(iter);
      continue;
    }

    iter++;
  }
}

std::shared_ptr<Texture> TextureResourceManager::LoadTextureFromFile(string _path) {
  //std::scoped_lock lock(mutex);

  auto iter = texturesFromPath.find(_path);

  // check cache first
  if (iter != texturesFromPath.end()) {
    return iter->second.GetResource();
  }

  auto pathsIter = std::find(paths.begin(), paths.end(), _path);

  bool skipCaching = false;

  if (pathsIter != paths.end()) {
    skipCaching = true;
  }

  std::shared_ptr<Texture> texture = std::make_shared<Texture>();
  
  if (!texture->loadFromFile(_path)) {
    Logger::Logf("Failed loading texture: %s", _path.c_str());
  } else {
    Logger::Logf("Loaded texture: %s", _path.c_str());
  }

  if (!skipCaching) {
    texturesFromPath.insert(std::make_pair(_path, texture));
  }

  return texture;
}

std::shared_ptr<Texture> TextureResourceManager::GetTexture(TextureType _ttype) {
  //std::scoped_lock lock(mutex);
  return textures.at(_ttype).GetResource();
}

TextureResourceManager::TextureResourceManager() {
  //-Tiles-
  //Blue tile
  paths.push_back("resources/tiles/tile_atlas_blue.png");

  //Red tile
  paths.push_back("resources/tiles/tile_atlas_red.png");

  //-Navis-
  // Megaman
  paths.push_back("resources/navis/megaman/navi_megaman_atlas.png");

  // Starman
  paths.push_back("resources/navis/starman/navi_starman_atlas.png");

  // Roll
  paths.push_back("resources/navis/roll/navi_roll_atlas.png");

  // Forte
  paths.push_back("resources/navis/forte/navi_forte_atlas.png");

  // Mobs
  paths.push_back("resources/ui/mob_name_backdrop.png");
  paths.push_back("resources/ui/mob_name_backdrop_edge.png");
  paths.push_back("resources/mobs/mob_move.png");
  paths.push_back("resources/mobs/mob_explosion.png");
  paths.push_back("resources/mobs/boss_shine.png");

  // Mettaur
  paths.push_back("resources/mobs/mettaur/mettaur.png");

  // Metrid
  paths.push_back("resources/mobs/metrid/metrid.png");

  // ProgsMan
  paths.push_back("resources/mobs/progsman/mob_progsman_atlas.png");

  // canodumbs
  paths.push_back("resources/mobs/canodumb/canodumb_atlas.png");

  // MetalMan
  paths.push_back("resources/mobs/metalman/metalman_atlas.png");

  // Alpha
  paths.push_back("resources/mobs/alpha/alpha.png");

  // Starfish
  paths.push_back("resources/mobs/starfish/starfish_atlas.png");

  // Megalian
  paths.push_back("resources/mobs/megalian/megalian_atlas.png");

  // HoneyBomber
  paths.push_back("resources/mobs/honeybomber/honeybomber.png");

  // Select screen "Anything Goes"
  paths.push_back("resources/mobs/select/random.png");

  // Battle misc / Artifacts
  paths.push_back("resources/navis/counter_reveal.png");
  paths.push_back("resources/mobs/mystery_data/mystery_data.png");
  paths.push_back("resources/mobs/cube/cube.png");
  paths.push_back("resources/mobs/small_shadow.png");

  //-Spells-
  paths.push_back("resources/spells/spell_bullet_hit.png");
  paths.push_back("resources/spells/spell_buster_charge.png");
  paths.push_back("resources/spells/spell_charged_bullet_hit.png");
  paths.push_back("resources/spells/guard_hit.png");
  paths.push_back("resources/spells/spell_wave.png");
  paths.push_back("resources/spells/spell_prog_bomb.png");
  paths.push_back("resources/spells/auras.png");
  paths.push_back("resources/spells/thunder.png");
  paths.push_back("resources/spells/reflect_shield.png");
  paths.push_back("resources/spells/bubble.png");
  paths.push_back("resources/spells/bubble_trap.png");
  paths.push_back("resources/spells/elecpulse.png");
  paths.push_back("resources/spells/ninja_star_atlas.png");
  paths.push_back("resources/spells/poof.png");
  paths.push_back("resources/spells/spell_heal.png");
  paths.push_back("resources/spells/areagrab.png");
  paths.push_back("resources/spells/spell_sword_slashes.png");
  paths.push_back("resources/spells/spell_meteor.png");
  paths.push_back("resources/spells/spell_ring_explosion.png");
  paths.push_back("resources/spells/spell_twin_fang.png");
  paths.push_back("resources/spells/spell_tornado.png");
  paths.push_back("resources/spells/spell_flame.png");
  paths.push_back("resources/spells/spell_bomb.png");
  paths.push_back("resources/spells/spell_panel_shot.png");
  paths.push_back("resources/spells/spell_yoyo.png");
  paths.push_back("resources/spells/spell_super_vulcan.png");
  paths.push_back("resources/spells/alpha_rocket.png");
  paths.push_back("resources/spells/spell_bees.png");
  paths.push_back("resources/spells/artifact_impact_fx.png");
  paths.push_back("resources/spells/artifact_vulcan_impact.png");
  paths.push_back("resources/spells/spell_wind.png");

  // Card Select 
  paths.push_back("resources/ui/card_select.png");
  paths.push_back("resources/ui/card_select_mega_overlay.png");
  paths.push_back("resources/ui/card_select_giga_overlay.png");
  paths.push_back("resources/ui/card_select_dark_overlay.png");
  paths.push_back("resources/ui/card_cursor_small.png");
  paths.push_back("resources/ui/card_cursor_big.png");
  paths.push_back("resources/ui/card_nosupport.png");
  paths.push_back("resources/ui/card_nodata.png");
  paths.push_back("resources/ui/card_senddata.png");
  paths.push_back("resources/ui/card_missing.png");
  paths.push_back("resources/ui/icon_missing.png");
  paths.push_back("resources/ui/card_lock.png");
  paths.push_back("resources/ui/card_frame.png");
  paths.push_back("resources/ui/cust_badge.png");
  paths.push_back("resources/ui/cust_badge_mask.png");
  paths.push_back("resources/ui/form_select.png");
  paths.push_back("resources/ui/form_cursor.png");
  paths.push_back("resources/ui/form_item_bg.png");

  // In battle signs
  paths.push_back("resources/ui/program_advance.png");
  paths.push_back("resources/ui/battle_start.png");
  paths.push_back("resources/ui/enemy_deleted.png");
  paths.push_back("resources/ui/double_delete.png");
  paths.push_back("resources/ui/triple_delete.png");
  paths.push_back("resources/ui/counter_hit.png");
  paths.push_back("resources/ui/alert.png");

  // Battle Results Frame
  paths.push_back("resources/ui/battle_results.png");
  paths.push_back("resources/ui/zenny.png");
  paths.push_back("resources/ui/nodata.png");
  paths.push_back("resources/ui/press_a.png");
  paths.push_back("resources/ui/counter_star.png");

  // folder view
  paths.push_back("resources/ui/folder_card.png");
  paths.push_back("resources/ui/folder_card_mega.png");
  paths.push_back("resources/ui/folder_card_giga.png");
  paths.push_back("resources/ui/folder_card_dark.png");
  paths.push_back("resources/ui/folder_dock.png");
  paths.push_back("resources/ui/pack_dock.png");
  paths.push_back("resources/ui/folder_rarity.png");
  paths.push_back("resources/ui/scrollbar.png");
  paths.push_back("resources/ui/select_cursor.png");
  paths.push_back("resources/ui/folder_equip.png");
  paths.push_back("resources/ui/folder_name.png");
  paths.push_back("resources/ui/folder_cursor.png");
  paths.push_back("resources/ui/folder_options.png");
  paths.push_back("resources/ui/folder_new.png");
  paths.push_back("resources/ui/folder_size.png");
  paths.push_back("resources/ui/folder_textbox.png");
  paths.push_back("resources/ui/mb_placeholder.png");
  paths.push_back("resources/ui/folder_edit_next.png");
  paths.push_back("resources/ui/folder_sort.png");
  paths.push_back("resources/ui/letter_cursor.png");

  // Navi Select View
  paths.push_back("resources/scenes/select/glow_sheet.png");
  paths.push_back("resources/scenes/select/pad_base.png");
  paths.push_back("resources/scenes/select/pad_bottom.png");
  paths.push_back("resources/scenes/select/char_name.png");
  paths.push_back("resources/scenes/select/stat.png");
  paths.push_back("resources/scenes/select/element.png");
  paths.push_back("resources/scenes/select/info_box.png");
  paths.push_back("resources/scenes/select/symbol_slots.png");

  // Mugshots
  paths.push_back("resources/ui/navigator.png");
  paths.push_back("resources/ui/textbox.png");
  paths.push_back("resources/ui/textbox_next.png");
  paths.push_back("resources/ui/textbox_cursor.png");

  // Background/foreground
  paths.push_back("resources/scenes/title/bg_blue.png");
  paths.push_back("resources/scenes/title/prog-pulse.png");
  paths.push_back("resources/scenes/game_over/game_over.png");
  paths.push_back("resources/scenes/select/battle_select.png");
  paths.push_back("resources/scenes/folder/bg.png");
  paths.push_back("resources/scenes/folder/folder_info.png");
  paths.push_back("resources/scenes/folder/folder_name.png");
  paths.push_back("resources/scenes/select/bg.png");

  // other ui / icons
  paths.push_back("resources/ui/aura_numset.png");
  paths.push_back("resources/ui/hp_numset.png");
  paths.push_back("resources/ui/player_numset.png");
  paths.push_back("resources/ui/gamepad_support_icon.png");
  paths.push_back("resources/ui/main_menu_ui.png");
  paths.push_back("resources/ui/elements.png");

  // texture maps
  paths.push_back("resources/shaders/textures/distortion.png");
  paths.push_back("resources/shaders/textures/heat.png");
  paths.push_back("resources/shaders/textures/noise.png");
  paths.push_back("resources/shaders/textures/noise_invert.png");

  // misc ui
  paths.push_back("resources/ui/light.png");
  paths.push_back("resources/ui/webaccount_icon.png");
  paths.push_back("resources/ui/spinner.png");
  paths.push_back("resources/ui/screen_bar.png");
  paths.push_back("resources/ui/menu_option_edge.png");
  paths.push_back("resources/ui/menu_option_mid.png");

  // font
  paths.push_back("resources/fonts/fonts_compressed.png");

  // config ui
  paths.push_back("resources/scenes/config/audio.png");
  paths.push_back("resources/scenes/config/end_btn.png");

  //Claris additions
  
  // spells
  paths.push_back("resources/spells/spell_zapring.png");
  // bunny family
  paths.push_back("resources/mobs/bunny/bunny.png");
}

TextureResourceManager::~TextureResourceManager() {
}
