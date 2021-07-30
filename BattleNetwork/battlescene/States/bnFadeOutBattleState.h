#pragma once

#include "../bnBattleSceneState.h"

// modes for fading out style
enum class QuitMode : int {
    white = 0,
    black,
    pixelate,
    game_over
};

class Player;

/* 
    \brief This structure accepts the battle scene as input and asks to quit
    This is a dummy state because the constructor asks the scene in return to use its 
    Quit() routine
*/
class FadeOutBattleState final : public BattleSceneState {
  bool keepPlaying{ true };
  QuitMode mode;
  double wait{ 2 }; // in seconds
  std::vector<Player*>& tracked;
public:
  FadeOutBattleState(const QuitMode& mode, std::vector<Player*>& tracked);

  void onStart(const BattleSceneState* last) override;
  void onEnd(const BattleSceneState* next) override;
  void onUpdate(double);
  void onDraw(sf::RenderTexture&);
  void EnableKeepPlaying(bool enable);
};