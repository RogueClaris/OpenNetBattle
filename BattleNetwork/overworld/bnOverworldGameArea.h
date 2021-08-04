#pragma once
#include "bnOverworldSceneBase.h"
#include "bnOverworldHomepage.h"
#include "bnOverworldActorPropertyAnimator.h"
#include "../bnCardFolderCollection.h"
#include "../bnCardLibrary.h"
#include "../bnPA.h"

namespace Overworld {
  class GameArea final : public Homepage {
  private:
    bool scaledmap{ false }, clicked{ false };
    bool infocus{ false };
    std::string mapPath;
    sf::Vector3f entryPos{};
    Direction mapDirection;
    int steps = 0;
    CameraController warpCameraController;
    Overworld::TeleportController::Command& teleportIn(sf::Vector3f position, Direction direction);
    bool positionIsInWarp(sf::Vector3f position);
    ActorPropertyAnimator propertyAnimator;
    bool goToBattle = false;
    bool isLoad = false;
  public:
    /**
     * @brief Loads the player's library data and loads graphics
     */
    GameArea(swoosh::ActivityController&, const std::string& mapPath, sf::Vector3f entryPos, const Direction mapDirection, bool isLoad);
    ~GameArea();

    void onUpdate(double elapsed);
    void onDraw(sf::RenderTexture& surface);
    void onStart();
    void onEnd();
    void onResume();
    void onLeave();

    void OnTileCollision();
    void OnInteract(Interaction type);
    void detectConveyor();
  };
}