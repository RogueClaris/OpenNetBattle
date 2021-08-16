#include <Swoosh/ActivityController.h>
#include <Segues/WhiteWashFade.h>

#include "bnGameOverScene.h"
#include "bnTitleScene.h"

using namespace swoosh::types;

GameOverScene::GameOverScene(swoosh::ActivityController& controller) : Scene(controller) {
  fadeInCooldown = 2.0f;
  gameOverTexture = *Textures().LoadTextureFromFile("resources/scenes/game_over/game_over.png");
  gameOver.setTexture(gameOverTexture);
  gameOver.setScale(2.f, 2.f);
  gameOver.setOrigin(gameOver.getLocalBounds().width / 2, gameOver.getLocalBounds().height / 2);

  leave = false;

  setView(sf::Vector2u(640, 480));
}

GameOverScene::~GameOverScene() {

}

void GameOverScene::onStart() {
  Audio().StopStream();
  Audio().Stream("resources/loops/game_over.ogg");
}

void GameOverScene::onResume() {

}

void GameOverScene::onUpdate(double elapsed) {
  if(!leave) {
    fadeInCooldown -= (float) elapsed;

    if (fadeInCooldown < 0) {
      fadeInCooldown = 0;
    }

    if (fadeInCooldown == 0 && (sf::Touch::isDown(0) || Input().Has(InputEvents::pressed_confirm))) {
      leave = true;
    }
  } 
  else {
      onEnd();
  }
}

void GameOverScene::onDraw(sf::RenderTexture& surface) {
    auto createPos = (sf::Vector2i)getController().getVirtualWindowSize();
    surface.create(createPos.x, createPos.y);
    sf::Vector2f logoPos = (sf::Vector2f)((sf::Vector2i)getController().getVirtualWindowSize() / 2);
    gameOver.setPosition(logoPos);
    surface.draw(gameOver);

}

void GameOverScene::onEnd()
{
    getController().rewind<segue<WhiteWashFade>::to<TitleScene>>();
}

void GameOverScene::onExit() {
}