#pragma once

#include "bnTextureResourceManager.h"
#include "bnAudioResourceManager.h"
#include <SFML/Graphics.hpp>

class TextBox : public sf::Drawable, public sf::Transformable {
private:
  sf::Font* font;
  mutable sf::Text text;
  double charsPerSecond; // default is 10 cps
  double progress;
  int areaWidth, areaHeight;
  std::string message;
  std::vector<int> lines;
  int lineIndex;
  int numberOfFittingLines;
  int charIndex;
  bool play;
  bool mute;
  int charSize;
  sf::Color fillColor;
  sf::Color outlineColor;
public:
  TextBox(int width, int height, int characterSize = 15, std::string fontPath = "resources/fonts/dr_cain_terminal.ttf") {
    font = TEXTURES.LoadFontFromFile(fontPath);
    text = sf::Text();
    message = "";
    areaWidth = width;
    areaHeight = height;
    charsPerSecond = 10;
    charIndex = 0;
    play = true;
    mute = false;
    progress = 0;
    charSize = characterSize;
    fillColor = sf::Color::White;
    outlineColor = sf::Color::White;
    lineIndex = 0;
    numberOfFittingLines = 1;
  }

  ~TextBox() {
    delete font;
  }

  void SetTextFillColor(sf::Color color) {
    fillColor = color;
  }

  void SetTextOutlineColor(sf::Color color) {
    outlineColor = color;
  }

  void SetTextColor(sf::Color color) {
    SetTextFillColor(color);
    SetTextOutlineColor(color);
  }

  void Mute(bool enabled = true) {
    mute = enabled;
  }

  void Unmute() {
    Mute(false);
  }

  void FormatToFit() {
    if (message.empty())
      return;

    lines.push_back(0); // All text begins at pos 0
 
    text = sf::Text(message, *font);
    text.setCharacterSize(charSize);

    sf::Text prevText = text;

    int index = 0;
    int wordIndex = -1; // If we are breaking on a word
    int lastRow = 0;
    int line = 1;

    double fitHeight = 0;

    while (index < message.size()) {
      if (message[index] != ' ' && message[index] != '\n' && wordIndex == -1) {
        wordIndex = index;
      }
      else if (message[index] == ' ' || message[index] == '\n') {
        wordIndex = -1;
      }

      text.setString(message.substr(lastRow, index - lastRow));

      double width  = text.getGlobalBounds().width;
      double height = text.getGlobalBounds().height;

      if (width > areaWidth && wordIndex != -1 && wordIndex > 0 && index > 0) {
        // Line break at the next word
        message.insert(wordIndex, "\n");
        lastRow = wordIndex+1;
        lines.push_back(lastRow);
        index=lastRow;
        wordIndex = -1;

        if (fitHeight < areaHeight) {
          line++;
          fitHeight += height;
        }
      }
      index++;
    }

    // make final text blank to start
    text.setString("");

    numberOfFittingLines = line;

    //std::cout << "num of fitting lines: " << numberOfFittingLines << std::endl;
    //std::cout << "lines found: " << lines.size() << std::endl;
  }

  const bool HasMore() const {
    if (lineIndex + numberOfFittingLines < lines.size())
      if (charIndex > lines[lineIndex + numberOfFittingLines])
        return true;

    return false;
  }

  const bool HasLess() const {
    return lineIndex > 0;
  }

  void ShowNextLine() {
    lineIndex++;

    if (lineIndex >= lines.size())
      lineIndex = (int)lines.size()-1;
  }

  void ShowPreviousLine() {
    lineIndex--;

    if (lineIndex < 0)
      lineIndex = 0;
  }

  void SetCharactersPerSecond(const double cps) {
    this->charsPerSecond = cps;
  }

  void SetMessage(const std::string message) {
    this->message = message;
    charIndex = 0;
    progress = 0;
    lines.clear();
    lineIndex = 0;
    numberOfFittingLines = 1;
    FormatToFit();
  }

  void Play(const bool play = true) {
    this->play = play;
  }

  void Stop() {
    Play(false);
  }

  const char GetCurrentCharacter() const {
    return message[charIndex];
  }

  const int GetNumberOfFittingLines() const {
    return numberOfFittingLines;
  }

  const double GetCharsPerSecond() const {
    return charsPerSecond;
  }

  virtual void Update(const double elapsed) {
    if (!play || message.empty()) return;

    bool playOnce = true;

    double charIndexIter = 0;
    progress += elapsed;

    double simulate = progress;
    while (simulate > 0 && charsPerSecond > 0) {
      simulate -= 1.0/ charsPerSecond;

      if (charIndexIter++ > charIndex && charIndex < message.size()) {
        charIndex++;

        while (message[charIndex] == ' ' && charIndex < message.size())
          charIndex++;

        if (!mute && message[charIndex] != ' ') {
          if (playOnce) {
            AUDIO.Play(AudioType::TEXT);
            playOnce = false;
          }
        }
      }
      
      int begin = lines[lineIndex];
      int len = begin;

      if (charIndex >= lines[lineIndex]) {
        if (lineIndex + (numberOfFittingLines) < lines.size()) {
          len = std::min(charIndex - begin, lines[lineIndex + (numberOfFittingLines)] - begin);
        }
        else {
          len = charIndex - begin;
        }
      }
      else
        len = 0;

      if (len <= 0)
        text.setString("");
      else 
        text.setString(message.substr(begin, len));
    }
  }

  const bool EndOfMessage() const { 
    return (charIndex >= message.length()); 
  }

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
    if (message.empty())
      return;

    // apply the transform
    states.transform *= getTransform();

    text.setPosition(this->getPosition());
    text.setScale(this->getScale());
    text.setRotation(this->getRotation());
    text.setFillColor(fillColor);
    text.setOutlineColor(outlineColor);

    target.draw(text);
  }
};
