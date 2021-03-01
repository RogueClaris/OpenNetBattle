#include "bnVendorScene.h"
#include "bnMessage.h"
#include "bnTextureResourceManager.h"
#include <Segues/BlackWashFade.h>

//
// Background 
//

#define TILEW 64
#define TILEH 64

#define PATH std::string("resources/scenes/vendors/")

VendorScene::VendorBackground::VendorBackground() :
  x(0.0f),
  y(0.0f),
  IBackground<VendorBackground>(Textures().LoadTextureFromFile(PATH + "bg.png"), 240, 180)
{
  FillScreen(sf::Vector2u(TILEW, TILEH));
}

VendorScene::VendorBackground::~VendorBackground()
{
}

void VendorScene::VendorBackground::Update(double _elapsed)
{
  y -= 0.75f * static_cast<float>(_elapsed);
  x -= 0.75f * static_cast<float>(_elapsed);

  if (x < 0) x = 1;
  if (y < 0) y = 1;

  Wrap(sf::Vector2f(x, y));
}

//
// VendorScene
//

void VendorScene::ShowDefaultMessage()
{
  //textbox.ClearAllMessages();
  auto message = new Message(defaultMessage);
  message->ShowEndMessageCursor(false);
  textbox.EnqueMessage(mugshot, anim, message);
  textbox.CompleteCurrentBlock();
  this->showDescription = false;
}

VendorScene::VendorScene(swoosh::ActivityController& controller, const sf::Sprite& mugshot, const Animation& anim) :
  Scene(controller),
  label(Font::Style::thin),
  textbox({ 4, 255 }),
  mugshot(mugshot),
  anim(anim)
{
  label.setScale(2.f, 2.f);

  moreItems.setTexture(*LOAD_TEXTURE(TEXT_BOX_NEXT_CURSOR));
  moreItems.setScale(2.f, 2.f);

  wallet.setTexture(*Textures().LoadTextureFromFile("resources/scenes/vendors/price.png"), true);
  wallet.setScale(2.f, 2.f);
  wallet.setPosition(340, 0.f);

  list.setTexture(*Textures().LoadTextureFromFile("resources/scenes/vendors/list.png"), true);
  list.setScale(2.f, 2.f);
  list.setPosition(0.f, 0.f);

  cursor.setTexture(*LOAD_TEXTURE(FOLDER_CURSOR));
  cursor.setScale(2.f, 2.f);

  bg = new VendorBackground;

  // Load key items 
  items = std::vector<VendorScene::Item>{
    {"SmartWatch", "Tells time.", 2000},
    {"Pizza", "Smells delicious and recovers HP.", 500},
    {"Key", "Opens a gate.", 1000},
    {"GigaFreeze", "Control cyberworld with this neat trick.", 99999},
    {"Sock", "Keeps your feet warms for the winter.", 20}
  };

  defaultMessage = "How can I help you? OPTION: description CANCEL: go back";
  auto message = new Message(defaultMessage);
  message->ShowEndMessageCursor(false);
  textbox.EnqueMessage(mugshot, anim, message);
  textbox.CompleteCurrentBlock();

  textbox.Mute();
  textbox.Open();

  setView(sf::Vector2u(480, 320));
}

VendorScene::~VendorScene()
{
  delete bg;
}

void VendorScene::onLeave()
{
}

void VendorScene::onExit()
{
}

void VendorScene::onEnter()
{
}

void VendorScene::onResume()
{
}

void VendorScene::onStart()
{
}

void VendorScene::onUpdate(double elapsed)
{
  textbox.Update(elapsed);
  bg->Update(elapsed);

  unsigned lastRow = row;
  bool updateDescription = false;

  if (question) {
    if (Input().Has(InputEvents::pressed_ui_left)) {
      question->SelectYes();
      Audio().Play(AudioType::CHIP_SELECT);
    }
    else if (Input().Has(InputEvents::pressed_ui_right)) {
      question->SelectNo();
      Audio().Play(AudioType::CHIP_SELECT);
    }
    else if (Input().Has(InputEvents::pressed_confirm)) {
      question->ConfirmSelection();
      textbox.CompleteCurrentBlock();
    }
    else if (Input().Has(InputEvents::pressed_cancel)) {
      question->SelectNo();
      question->ConfirmSelection();
      textbox.CompleteCurrentBlock();
    }
  }
  else {
    if (Input().Has(InputEvents::pressed_ui_up)) {
      row--;
    }
    else if (Input().Has(InputEvents::pressed_ui_down)) {
      row++;
    }
    else if (Input().Has(InputEvents::pressed_confirm)) {
      // todo: long item descriptions?
      if (!showDescription) {
         {
          std::string itemName = items[row + rowOffset].name;
          std::string msg = itemName + "\nAre you sure?";
          question = new Question(msg,
            [this, itemName]() {
              textbox.EnqueMessage(new Message("I bought " + itemName));
              textbox.CompleteCurrentBlock();
              question = nullptr;
              Audio().Play(AudioType::ITEM_GET);
            },
            [this]() {
              this->ShowDefaultMessage();
              question = nullptr;
              Audio().Play(AudioType::CHIP_DESC_CLOSE);
            });

          textbox.ClearAllMessages();
          textbox.EnqueMessage(mugshot, anim, question);
          textbox.CompleteCurrentBlock();
        }
      }
    }
    else if (Input().Has(InputEvents::pressed_cancel)) {
      // Don't ask to leave if in the middle of another (or current) question
      if (!question) {
        question = new Question("Leaving so soon?",
          [this]() {
            textbox.EnqueMessage(mugshot, anim, new Message("Goodbye!"));
            textbox.CompleteCurrentBlock();
            using namespace swoosh::types;
            getController().pop<segue<BlackWashFade, milli<500>>>();
            Audio().Play(AudioType::CHIP_DESC_CLOSE);
            question = nullptr;
          },
          [this]() {
            this->ShowDefaultMessage();
            question = nullptr;
            Audio().Play(AudioType::CHIP_DESC_CLOSE);
          });

        textbox.ClearAllMessages();
        textbox.EnqueMessage(mugshot, anim, question);
        textbox.CompleteCurrentBlock();
        Audio().Play(AudioType::CHIP_DESC);
      }
    }
    else if (Input().Has(InputEvents::pressed_option)) {
      showDescription = !showDescription;

      if (!showDescription) {
        textbox.ClearAllMessages();
        this->ShowDefaultMessage();
      }

      Audio().Play(AudioType::CHIP_DESC);

      updateDescription = true;
    }
  }

  signed lastRowOffset = rowOffset;

  if (row >= maxRows) {
    rowOffset++;
    row--;
  }

  if (row < 0) {
    rowOffset--;
    row++;
  }

  signed maxRowOffset = static_cast<signed>(items.size());

  row = std::max(0, row);
  row = std::min(maxRowOffset - 1, row);

  size_t index = static_cast<size_t>(row);

  rowOffset = std::max(0, rowOffset);
  rowOffset = std::min(maxRowOffset, rowOffset);

  size_t offset = static_cast<size_t>(rowOffset);
  index += offset;

  // Now that we've forced the change of values into a restricted range,
  // check to see if we actually selected anything new
  if (index < items.size() && (updateDescription || rowOffset != lastRowOffset || row != lastRow)) {
    if (rowOffset != lastRowOffset || row != lastRow) {
      Audio().Play(AudioType::CHIP_SELECT);
    };

    if (showDescription) {
      textbox.ClearAllMessages();
      auto message = new Message(items[index].desc);
      message->ShowEndMessageCursor(false);
      textbox.EnqueMessage(message);
      textbox.CompleteCurrentBlock();
    }
  }
  else {
    row = lastRow;
    rowOffset = lastRowOffset;
  }

  float startPos = 40.f;
  float endPos = 160.f;
  float rowsPerView = std::max(1.f, static_cast<float>(maxRowOffset - maxRows));
  float delta = static_cast<float>(rowOffset) / rowsPerView;
  float y = (endPos * delta) + (startPos * (1.f - delta));

  cursor.setPosition(10 + 1.f, 18 + (row * 32) + 1.f);

  auto bounce = std::sin((float)totalElapsed * 20.0f);
  moreItems.setPosition(sf::Vector2f(225, 140 + bounce) * 2.0f);
  totalElapsed += static_cast<float>(elapsed);
}

void VendorScene::onDraw(sf::RenderTexture& surface)
{
  surface.draw(*bg);
  surface.draw(list);
  surface.draw(wallet);

  label.SetColor(sf::Color(41, 99, 140));
  label.SetString(std::to_string(monies) + "z");
  label.setOrigin(label.GetLocalBounds().width, label.GetLocalBounds().height);
  label.setPosition(wallet.getPosition() + sf::Vector2f{(wallet.getLocalBounds().width*2.f) - 10.f, 56.f});
  surface.draw(label);

  if (items.size()) {
    for (size_t j = 0; j < maxRows; j++) {
      size_t offset = static_cast<size_t>(rowOffset);
      size_t index = offset + static_cast<size_t>(j);
      if (index < items.size()) {
        auto& item = items[index];
        label.SetString(item.name);
        label.setPosition(35, 18.f + (j * 32.f));
        label.setOrigin(0.f, 0.f);
        surface.draw(label);

        label.SetString(std::to_string(item.cost)+"z");
        label.setOrigin(label.GetLocalBounds().width, 0.f);
        label.setPosition(322.f, 18.f + (j * 32.f));
        surface.draw(label);
      }
    }
  }

  surface.draw(textbox);

  /*
  if (textbox.HasMore()) {
    surface.draw(moreText);
  }*/

  surface.draw(cursor);
}

void VendorScene::onEnd()
{
}
