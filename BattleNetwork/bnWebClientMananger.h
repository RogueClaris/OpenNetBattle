#pragma once
#include <WebAPI/WebClient.h>
#include <memory>
#include <thread>
#include <mutex>
#include <queue>
#include <future>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include "bnCard.h"

#undef GetUserName

template<typename T>
bool is_ready(const std::future<T>& f) {
  return f.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
}

class WebClientManager {
private:
  std::thread tasksThread; //!< This thread performs api requests when queued by the battle engine
  std::thread pingThread; //!< This thread pings the server to gauge the connection
  std::mutex clientMutex; //!< Mutex for WebClient since it may be accessed by multiple threads...
  std::condition_variable taskQueueWakeup;

  char* version{ 0 }; //!< Session headers must match or client cannot load
  const size_t version_len{ 256 };

  bool shutdownSignal;
  bool isWorking;
  bool isConnected; //!< True if pinged heartbeat endpoint successfully in the last invernal
  long heartbeatInterval; //!< The time in milliseconds to ping the web server
  long long since; //!< Last time in milliseconds the API was fetched (how recent are we in sync?)
  std::string username;
  WebAccounts::AccountState account;
  std::unique_ptr<WebAccounts::WebClient> client;
  std::map<std::string, std::shared_ptr<sf::Texture>> iconTextureCache;
  std::map<std::string, std::shared_ptr<sf::Texture>> cardTextureCache;
  std::map<std::string, std::string> keys; //!< Table of string key-pair values
  std::queue<std::function<void()>> taskQueue;

  void PingThreadHandler();
  void QueuedTasksThreadHandler();
  void InitDownloadImageHandler();

public:
  struct CardListCommandResult {
    bool success{};
    std::vector<std::string> failed;
  };

  WebClientManager();
  ~WebClientManager();
  static WebClientManager& GetInstance();
  void PingInterval(long interval);
  const long GetPingInterval() const;
  void ConnectToWebServer(const char* apiVersion, const char* domain, int port);
  const bool IsConnectedToWebServer();
  const bool IsLoggedIn();
  const bool IsWorking();

  std::future<bool> SendLoginCommand(std::string username, std::string password);
  std::future<bool> SendLogoutCommand();
  std::future<WebAccounts::AccountState> SendFetchAccountCommand();
  std::future<CardListCommandResult> SendFetchCardListCommand(const std::vector<std::string>& cardList);

  std::shared_ptr<sf::Texture> GetIconForCard(const std::string& uuid);
  std::shared_ptr<sf::Texture> GetImageForCard(const std::string& uuid);
  std::shared_ptr<WebAccounts::Card> GetWebCard(const std::string& uuid);
  std::shared_ptr<WebAccounts::CardProperties> GetWebCardModel(const std::string& modelid);
  const Battle::Card MakeBattleCardFromWebCardData(const WebAccounts::Card& card);
  const Battle::Card MakeBattleCardFromWebComboData(const WebAccounts::CardCombo& combo);
  const std::string& GetUserName() const;

  void UploadCardData(const std::string& uuid,
    std::shared_ptr<sf::Texture> icon,
    std::shared_ptr<sf::Texture> image,
    std::shared_ptr<WebAccounts::Card> data,
    std::shared_ptr<WebAccounts::CardProperties> model);

  void CacheTextureData(const WebAccounts::AccountState& account);
  void SaveSession(const std::string& inpath);
  void SetKey(const std::string& key, const std::string& value);
  const std::string GetValue(const std::string& key);
  const bool LoadSession(const std::string& outpath);
  void UseCachedAccount(const WebAccounts::AccountState& account);
  void ShutdownAllTasks();
};

/*! \brief Shorthand to get instance of the manager */
#define WEBCLIENT WebClientManager::GetInstance()