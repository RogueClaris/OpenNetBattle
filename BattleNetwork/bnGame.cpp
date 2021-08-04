#include <time.h>
#include <queue>
#include <atomic>
#include <cmath>
#include <Swoosh/ActivityController.h>
#include <Swoosh/Ease.h>

#include "bnGame.h"
#include "bnTextureResourceManager.h"
#include "bnAudioResourceManager.h"
#include "bnShaderResourceManager.h"
#include "bnInputManager.h"
#include "bnWebClientMananger.h"
#include "bnNaviRegistration.h"
#include "bnInputManager.h"
#include "bnGameOverScene.h"
#include "bnFakeScene.h"
#include "bnConfigReader.h"
#include "bnConfigScene.h"
#include "bnFont.h"
#include "bnText.h"
#include "bnQueueMobRegistration.h"
#include "bnQueueNaviRegistration.h"
#include "bnResourceHandle.h"
#include "bnInputHandle.h"
#include "overworld/bnOverworldHomepage.h"
#include "SFML/System.hpp"
#include "bnCardFolderCollection.h"

Game::Game(DrawWindow& window) : 
  window(window), 
  reader("config.ini"),
  configSettings(),
  netManager(),
  textureManager(),
  audioManager(),
  shaderManager(),
  inputManager(*window.GetRenderWindow()),
  ActivityController(*window.GetRenderWindow()) {
  
  // figure out system endianness
  {
    int n = 1;
    // little endian if true
    if (*(char*)&n == 1) { endian = Endianness::little; }
  }

  // Link the resource handle to use all the manangers created by the game
  ResourceHandle::audio    = &audioManager;
  ResourceHandle::textures = &textureManager;
  ResourceHandle::shaders  = &shaderManager;

#ifdef BN_MOD_SUPPORT
  ResourceHandle::scripts  = &scriptManager;
#endif

  // Link i/o handle to use the input manager created by the game
  InputHandle::input = &inputManager;

  // Link net handle to use manager created by the game
  NetHandle::net = &netManager;

  // Use the engine's window settings for this platform to create a properly 
  // sized render surface...
  unsigned int win_x = static_cast<unsigned int>(window.GetView().getSize().x);
  unsigned int win_y = static_cast<unsigned int>(window.GetView().getSize().y);

  renderSurface.create(win_x, win_y, window.GetRenderWindow()->getSettings());

  // Use our external render surface as the game's screen
  window.SetRenderSurface(renderSurface);
}

Game::~Game() {

}

void Game::SetCommandLineValues(const cxxopts::ParseResult& values) {
  commandline = values.arguments();

  if (commandline.empty()) return;

  Logger::Log("Command line args provided");
  for (auto&& kv : commandline) {
    Logger::Logf("%s : %s", kv.key().c_str(), kv.value().c_str());
  }

  // Now that we have CLI values, we can configure 
  // other subsystems that need to read from them...
  unsigned int myPort = CommandLineValue<unsigned int>("port");
  uint16_t maxPayloadSize = CommandLineValue<uint16_t>("mtu");
  netManager.BindPort(myPort);

  if (maxPayloadSize != 0) {
    netManager.SetMaxPayloadSize(maxPayloadSize);
  }
}

TaskGroup Game::Boot(const cxxopts::ParseResult& values)
{
  SetCommandLineValues(values);

  isDebug = CommandLineValue<bool>("debug");

  // Initialize the engine and log the startup time
  const clock_t begin_time = clock();

  /**
  * TODO
  DrawWindow::WindowMode mode = configSettings.IsFullscreen() ? DrawWindow::WindowMode::fullscreen : DrawWindow::WindowMode::window;

  window.Initialize(windowMode);
  */

  Logger::Logf("Engine initialized: %f secs", float(clock() - begin_time) / CLOCKS_PER_SEC);

  // does shaders too
  Callback<void()> graphics;
  graphics.Slot(std::bind(&Game::RunGraphicsInit, this, &progress));

  Callback<void()> audio;
  audio.Slot(std::bind(&Game::RunAudioInit, this, &progress));

  Callback<void()> navis;
  navis.Slot(std::bind(&Game::RunNaviInit, this, &progress));

  Callback<void()> mobs;
  mobs.Slot(std::bind(&Game::RunMobInit, this, &progress));

  Callback<void()> finish;
  finish.Slot([this] {
    // Tell the input event loop how to behave when the app loses and regains focus
    inputManager.BindLoseFocusEvent(std::bind(&Game::LoseFocus, this));
    inputManager.BindRegainFocusEvent(std::bind(&Game::GainFocus, this));
    inputManager.BindResizedEvent(std::bind(&Game::Resize, this, std::placeholders::_1, std::placeholders::_2));

    Font::specialCharLookup.insert(std::make_pair(char(-1), "THICK_SP"));
    Font::specialCharLookup.insert(std::make_pair(char(-2), "THICK_EX"));
  });

  inputManager.SupportConfigSettings(reader);

  TaskGroup tasks;
  tasks.AddTask("Init graphics", std::move(graphics));
  tasks.AddTask("Init audio", std::move(audio));
  tasks.AddTask("Load Navis", std::move(navis));
  tasks.AddTask("Load mobs", std::move(mobs));
  tasks.AddTask("Finishing", std::move(finish));

    // Load font symbols for use across the entire engine...
  textureManager.LoadImmediately(TextureType::FONT);

  if (configSettings.IsOK()) {
    // If the file is good, use the Audio() and 
    // controller settings from the config
    audioManager.EnableAudio(reader.GetConfigSettings().IsAudioEnabled());
    audioManager.SetStreamVolume(((reader.GetConfigSettings().GetMusicLevel()) / 3.0f)*100.0f);
    audioManager.SetChannelVolume(((reader.GetConfigSettings().GetSFXLevel()) / 3.0f)*100.0f);
  }

  mouse.setTexture(textureManager.LoadTextureFromFile("resources/ui/mouse.png"));
  mouse.setScale(2.f, 2.f);
  mouseAnimation = Animation("resources/ui/mouse.animation");
  mouseAnimation << "DEFAULT" << Animator::Mode::Loop;
  mouseAlpha = 1.0;

  // set a loading spinner on the bottom-right corner of the screen
  spinner.setTexture(textureManager.LoadTextureFromFile("resources/ui/spinner.png"));
  spinner.setScale(2.f, 2.f);
  spinner.setPosition(float(window.GetView().getSize().x - 64), float(window.GetView().getSize().y - 50));

  spinnerAnimator = Animation("resources/ui/spinner.animation") << "SPIN" << Animator::Mode::Loop;

  return tasks;
}

void Game::Run()
{
  sf::Clock clock;
  float scope_elapsed = 0.0f;
  float speed = 1.0f;
  float messageCooldown = 3;

  bool inMessageState = true;

  while (window.Running()) {
    float FPS = 0.f;

    FPS = (float)(1.0 / (float)scope_elapsed);
    std::string fpsStr = std::to_string(FPS);
    fpsStr.resize(4);
    sf::String title = sf::String(std::string("FPS: ") + fpsStr);
    getWindow().setTitle(title);

    clock.restart();

    // Poll input
    inputManager.Update();

    // unused images need to be free'd 
    textureManager.HandleExpiredTextureCache();

    double delta = 1.0 / static_cast<double>(frame_time_t::frames_per_second);
    this->elapsed += from_seconds(delta);

    bool nextFrameKey = inputManager.Has(InputEvents::pressed_advance_frame);
    bool resumeKey = inputManager.Has(InputEvents::pressed_resume_frames);

    // Poll net code
    netManager.Update(delta);

    if (nextFrameKey && isDebug && !frameByFrame) {
      frameByFrame = true;
    }
    else if (resumeKey && frameByFrame) {
      frameByFrame = false;
    }

    bool updateFrame = (frameByFrame && nextFrameKey) || !frameByFrame;

    if (updateFrame) {
      // Prepare for draw calls
      window.Clear();

      this->update(delta);
      this->draw();

      window.Display();
    }

    scope_elapsed = clock.getElapsedTime().asSeconds();
  }
}

void Game::SetWindowMode(DrawWindow::WindowMode mode)
{
  windowMode = mode;
}

void Game::Postprocess(ShaderType shaderType)
{
  this->postprocess = shaderManager.GetShader(shaderType);
}

void Game::NoPostprocess()
{
  this->postprocess = nullptr;
}

const sf::Vector2f Game::CameraViewOffset(Camera& camera)
{
  return window.GetView().getCenter() - camera.GetView().getCenter();
}

unsigned Game::FrameNumber() const
{
  return this->elapsed.count();
}

const Endianness Game::GetEndianness()
{
  return endian;
}

void Game::LoadConfigSettings()
{
}

void Game::RunNaviInit(std::atomic<int>* progress) {
  clock_t begin_time = clock();
  QueuNaviRegistration(); // Queues navis to be loaded later

  NAVIS.LoadAllNavis(*progress);

  Logger::Logf("Loaded registered navis: %f secs", float(clock() - begin_time) / CLOCKS_PER_SEC);
}

void Game::RunMobInit(std::atomic<int>* progress) {
  clock_t begin_time = clock();
  QueueMobRegistration(); // Queues mobs to be loaded later

  MOBS.LoadAllMobs(*progress);

  Logger::Logf("Loaded registered mobs: %f secs", float(clock() - begin_time) / CLOCKS_PER_SEC);
}

void Game::RunGraphicsInit(std::atomic<int> * progress) {
  clock_t begin_time = clock();
  textureManager.LoadAllTextures(*progress);

  Logger::Logf("Loaded textures: %f secs", float(clock() - begin_time) / CLOCKS_PER_SEC);

  begin_time = clock();
  shaderManager.LoadAllShaders(*progress);

  Logger::Logf("Loaded shaders: %f secs", float(clock() - begin_time) / CLOCKS_PER_SEC);
}

void Game::RunAudioInit(std::atomic<int> * progress) {
  const clock_t begin_time = clock();
  audioManager.LoadAllSources(*progress);

  Logger::Logf("Loaded Audio() sources: %f secs", float(clock() - begin_time) / CLOCKS_PER_SEC);
}

void Game::GainFocus() {
  window.RegainFocus();
  audioManager.Mute(false);

#ifdef __ANDROID__
  // TODO: Reload all graphics and somehow reassign all gl IDs to all allocated sfml graphics structures
  // Textures().RecoverLostGLContext();
  // ENGINE.RecoverLostGLContext(); // <- does the window need recreation too?
#endif
}

void Game::LoseFocus() {
  audioManager.Mute(true);
}

void Game::Resize(int newWidth, int newHeight) {
  float windowRatio = (float)newWidth / (float)newHeight;
  float viewRatio = window.GetView().getSize().x / window.GetView().getSize().y;

  showScreenBars = windowRatio >= viewRatio;
  window.Resize(newWidth, newHeight);
}