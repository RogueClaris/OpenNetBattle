#include <Segues/BlackWashFade.h>
#include "bnOverworldGameArea.h"
#include "bnOverworldOnlineArea.h"
#include "../netplay/bnNetPlayConfig.h"
#include "../bnMessage.h"
#include "bnConveyors.h"
#include "bnOverworldMap.h"

using namespace swoosh::types;

constexpr size_t DEFAULT_PORT = 8765;

Overworld::GameArea::GameArea(
    swoosh::ActivityController& controller,
    const std::string& mapPath,
    sf::Vector3f entryPos,
    Direction mapDirection
    )
    :
    SceneBase(controller)
    {
      LoadMap(FileUtil::Read(mapPath));

      auto& map = GetMap();

      // spawn in the player
      auto player = GetPlayer();
      auto& command = GetTeleportController().TeleportIn(player, entryPos, mapDirection, true);
      command.onFinish.Slot([=] {
        GetPlayerController().ControlActor(player);
      });
    }

Overworld::GameArea::~GameArea() {
}

void Overworld::GameArea::onUpdate(double elapsed)
{
  // Update our logic
  auto& map = GetMap();

  // do default logic
  SceneBase::onUpdate(elapsed);

  if (Input().Has(InputEvents::pressed_shoulder_left) && !IsInputLocked()) {
    auto& meta = NAVIS.At(GetCurrentNavi());
    const std::string& image = meta.GetMugshotTexturePath();
    const std::string& anim = meta.GetMugshotAnimationPath();
    auto mugshot = Textures().LoadTextureFromFile(image);

    auto& menuSystem = GetMenuSystem();
    menuSystem.SetNextSpeaker(sf::Sprite(*mugshot), anim);
    menuSystem.EnqueueMessage("This is the internet.");

    GetPlayer()->Face(Direction::down_right);
  }
  detectConveyor();
  auto player = GetPlayer();
  propertyAnimator.Update(*player, elapsed);
  propertyAnimator.OnComplete([this] {
      GetPlayerController().ControlActor(GetPlayer());
      });
}

void Overworld::GameArea::onDraw(sf::RenderTexture& surface)
{
  SceneBase::onDraw(surface);
  Text nameText{ Font::Style::small };
}

void Overworld::GameArea::onStart()
{
  SceneBase::onStart();

  Audio().Stream("resources/loops/loop_overworld.ogg", false);
  infocus = true;
}

void Overworld::GameArea::onResume()
{
  SceneBase::onResume();
  Audio().Stream("resources/loops/loop_overworld.ogg", false);
  infocus = true;
}

void Overworld::GameArea::onLeave()
{
  infocus = false;
}

void Overworld::GameArea::OnTileCollision()
{
    auto& teleportController = GetTeleportController();

    if (!teleportController.IsComplete()) {
        return;
    }

    auto& map = GetMap();
    auto& player = GetPlayer();
    auto tileSize = sf::Vector2f(map.GetTileSize());
    auto playerPos = player->getPosition();
    auto interpolateTime = sf::seconds(0.5f);
    auto z = (float)player->GetElevation();
    auto& playerController = GetPlayerController();
    auto playerPos2 = sf::Vector3f(
        std::floor(playerPos.x / (tileSize.x / 2)),
        std::floor(playerPos.y / tileSize.y),
        std::floor(z)
    );
    for (auto i = 0; i < map.GetLayerCount(); i++) {
        auto& layer = map.GetLayer(i);

        for (auto j = 0; j < layer.GetTileObjects().size(); j++) {
            TileObject theWarp = layer.GetTileObjects()[j];
            auto warpPos2 = sf::Vector3f(
                std::floor(theWarp.position.x / (tileSize.x / 2)),
                std::floor(theWarp.position.y / tileSize.y),
                std::floor(z)
            );
            if (ObjectType::position_warp == theWarp.type && playerPos2 == warpPos2) {
                playerController.ReleaseActor();
                auto& command = teleportController.TeleportOut(player);
                auto targetTilePos = sf::Vector2f(
                    theWarp.customProperties.GetPropertyFloat("x"),
                    theWarp.customProperties.GetPropertyFloat("y")
                );

                auto targetWorldPos = map.TileToWorld(targetTilePos);

                auto targetPosition = sf::Vector3f(targetWorldPos.x, targetWorldPos.y, theWarp.customProperties.GetPropertyFloat("z"));
                auto direction = FromString(theWarp.customProperties.GetProperty("direction"));

                sf::Vector2f player_pos = { player->getPosition().x, player->getPosition().y };
                float distance = std::pow(targetWorldPos.x - player_pos.x, 2.0f) + std::pow(targetWorldPos.y - player_pos.y, 2.0f);

                // this is a magic number - this is about as close to 2 warps that are 8 blocks away vertically 
                // (expression is also squared)
                if (distance < 40'000) {
                    warpCameraController.QueueWaneCamera(map.WorldToScreen(targetPosition), interpolateTime, 0.55f);
                }
                command.onFinish.Slot([=] {
                    teleportIn(targetPosition, Orthographic(direction));
                    warpCameraController.QueueUnlockCamera();
                    GetPlayerController().ControlActor(player);
                    });
                break;
            }
        }
    }
    
}

bool Overworld::GameArea::positionIsInWarp(sf::Vector3f position) {
    auto& map = GetMap();
    auto& player = GetPlayer();
    auto tileSize = sf::Vector2f(map.GetTileSize());
    auto& objectList = map.GetLayer(player->GetElevation()).GetTileObjects();
    auto z = player->GetElevation();
    auto workingPos = sf::Vector2f(std::floor(position.x / (tileSize.x/2)), std::floor(position.y / tileSize.y));
    for (auto i = 0; i < objectList.size(); i++) {
        auto warpPos = sf::Vector2f(
            std::floor(objectList[i].position.x / (tileSize.x / 2)),
            std::floor(objectList[i].position.y / tileSize.y)
        );
        if (warpPos == workingPos) {
            return true;
        }
    }
    return false;
}

void Overworld::GameArea::detectConveyor() {
    if (propertyAnimator.IsAnimatingPosition()) {
        // if the server is dragging the player around, ignore conveyors
        return;
    }
    auto player = GetPlayer();
    auto& map = GetMap();
    auto playerTilePos = map.WorldToTileSpace(player->getPosition());
    auto& layer = map.GetLayer(player->GetLayer());
    auto tile = layer.GetTile(int(playerTilePos.x), int(playerTilePos.y));
    if (!tile) {
        return;
    }
    if (tile->isConveyor(map)) {
        auto tileMeta = map.GetTileMeta(tile->gid);
        if (tileMeta == nullptr) {
            return;
        }
        auto direction = tileMeta->direction;
        if (tile->flippedHorizontal) {
            direction = FlipHorizontal(direction);
        }

        if (tile->flippedVertical) {
            direction = FlipVertical(direction);
        }

        auto endTilePos = playerTilePos;
        float tileDistance = 0.0f;

        ActorPropertyAnimator::PropertyStep animationProperty;
        animationProperty.property = ActorProperty::animation;

        // resolve animation
        switch (direction) {
        case Direction::up_left:
            animationProperty.stringValue = "IDLE_UL";
            break;
        case Direction::up_right:
            animationProperty.stringValue = "IDLE_UR";
            break;
        case Direction::down_left:
            animationProperty.stringValue = "IDLE_DL";
            break;
        case Direction::down_right:
            animationProperty.stringValue = "IDLE_DR";
            break;
        }

        ActorPropertyAnimator::PropertyStep axisProperty;
        axisProperty.ease = Ease::linear;
        auto isConveyorNext = [&layer, &map](sf::Vector2f endTilePos) {
            auto tile = layer.GetTile(int(endTilePos.x), int(endTilePos.y));

            if (!tile) {
                Logger::Log("this should not show up");
                return false;
            }

            return tile->isConveyor(map);
        };

        // resolve end position
        switch (direction) {
        case Direction::up_left:
        case Direction::down_right:
            endTilePos.x = std::floor(endTilePos.x);
            axisProperty.property = ActorProperty::x;
            break;
        case Direction::up_right:
        case Direction::down_left:
            axisProperty.property = ActorProperty::y;
            endTilePos.y = std::floor(endTilePos.y);
            break;
        }

        auto unprojectedDirection = Orthographic(direction);
        auto walkVector = UnitVector(unprojectedDirection);

        endTilePos += walkVector;

        bool nextTileIsConveyor = isConveyorNext(endTilePos);
        if (nextTileIsConveyor) {
            endTilePos += walkVector / 2.0f;
        }

        // fixing overshooting
        switch (direction) {
        case Direction::up_left:
            endTilePos.x = std::nextafter(endTilePos.x + 1.0f, -INFINITY);
            break;
        case Direction::up_right:
            endTilePos.y = std::nextafter(endTilePos.y + 1.0f, -INFINITY);
            break;
        }

        auto endPos = map.TileToWorld(endTilePos);

        switch (axisProperty.property) {
        case ActorProperty::x:
            axisProperty.value = endPos.x;
            tileDistance = std::abs(endTilePos.x - playerTilePos.x);
            break;
        case ActorProperty::y:
            axisProperty.value = endPos.y;
            tileDistance = std::abs(endTilePos.y - playerTilePos.y);
            break;
        }

        propertyAnimator.Reset();

        auto speed = tileMeta->customProperties.GetPropertyFloat("speed");

        if (speed == 0.0f) {
            speed = 1.0f;
        }
        auto duration = tileDistance / speed;
        ActorPropertyAnimator::PropertyStep sfxProperty;
        sfxProperty.property = ActorProperty::sound_effect_loop;
        sfxProperty.stringValue = GetPath(tileMeta->customProperties.GetProperty("sound effect"));

        ActorPropertyAnimator::KeyFrame startKeyframe;
        startKeyframe.propertySteps.push_back(animationProperty);
        startKeyframe.propertySteps.push_back(sfxProperty);
        propertyAnimator.AddKeyFrame(startKeyframe);

        ActorPropertyAnimator::KeyFrame endKeyframe;
        endKeyframe.propertySteps.push_back(axisProperty);
        endKeyframe.duration = duration;
        propertyAnimator.AddKeyFrame(endKeyframe);

        if (!nextTileIsConveyor) {
            ActorPropertyAnimator::KeyFrame waitKeyFrame;
            // reuse last property to simulate idle
            waitKeyFrame.propertySteps.push_back(axisProperty);
            waitKeyFrame.duration = 0.25;
            propertyAnimator.AddKeyFrame(waitKeyFrame);
        }

        propertyAnimator.UseKeyFrames(*player);
        GetPlayerController().ReleaseActor();
    }
}

Overworld::TeleportController::Command& Overworld::GameArea::teleportIn(sf::Vector3f position, Direction direction)
{
    auto actor = GetPlayer();

    if (!positionIsInWarp(position)) {
        actor->Face(direction);
        direction = Direction::none;
    }

    return GetTeleportController().TeleportIn(actor, position, direction);
}

void Overworld::GameArea::onEnd()
{
}

void Overworld::GameArea::OnInteract(Interaction type) {
  if(type != Interaction::action) {
    return;
  }

  auto player = GetPlayer();
  auto targetPos = player->PositionInFrontOf();
  auto targetOffset = targetPos - player->getPosition();

  for (const auto& other : GetSpatialMap().GetChunk(targetPos.x, targetPos.y)) {
    if (player == other) continue;

    auto collision = player->CollidesWith(*other, targetOffset);

    if (collision) {
      other->Interact(player, type);
      break;
    }
  }
}
