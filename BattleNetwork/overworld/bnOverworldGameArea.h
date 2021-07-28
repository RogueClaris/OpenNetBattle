#pragma once
#include "bnOverworldSceneBase.h"
#include "bnOverworldActorPropertyAnimator.h"

namespace Overworld {
  class GameArea final : public SceneBase {
  private:
    bool scaledmap{ false }, clicked{ false };
    bool infocus{ false };
    std::string mapPath;
    sf::Vector3f entryPos{};
    Direction mapDirection;
    CameraController warpCameraController;
    Overworld::TeleportController::Command& teleportIn(sf::Vector3f position, Direction direction);
    bool positionIsInWarp(sf::Vector3f position);
    bool isPosMatch(float x1, float y1, float x2, float y2);
    ActorPropertyAnimator propertyAnimator;
  public:
    /**
     * @brief Loads the player's library data and loads graphics
     */
    GameArea(swoosh::ActivityController&, const std::string& mapPath, sf::Vector3f entryPos, const Direction mapDirection);
    ~GameArea();

    void onUpdate(double elapsed) override;
    void onDraw(sf::RenderTexture& surface) override;
    void onStart() override;
    void onEnd() override;
    void onResume() override;
    void onLeave() override;

    void OnTileCollision() override;
    void OnInteract(Interaction type) override;
    void detectConveyor();
  };
}