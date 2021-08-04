#pragma once
#include <Poco/Net/DatagramSocket.h>
#include <Poco/Buffer.h>
#include "bnOverworldSceneBase.h"
#include "bnOverworldPollingPacketProcessor.h"

namespace Overworld {
  class Homepage : public SceneBase {
  private:
    bool scaledmap{ false }, clicked{ false };
    bool infocus{ false };
    Poco::Net::SocketAddress remoteAddress; //!< server
    std::shared_ptr<PollingPacketProcessor> packetProcessor;
    uint16_t maxPayloadSize{};
    sf::Vector3f netWarpTilePos;
    unsigned int netWarpObjectId{};
    ServerStatus serverStatus{ ServerStatus::offline };

    void UpdateServerStatus(ServerStatus status, uint16_t serverMaxPayloadSize);
    void EnableNetWarps(bool enabled);

  public:

    /**
     * @brief Loads the player's library data and loads graphics
     */
    Homepage(swoosh::ActivityController&);
    ~Homepage();

    void onUpdate(double elapsed) override;
    void onDraw(sf::RenderTexture& surface) override;
    void onStart() override;
    void onEnd() override;
    void onResume() override;
    void onLeave() override;

    void OnTileCollision() override;
    void OnInteract(Interaction type) override;
  };
}