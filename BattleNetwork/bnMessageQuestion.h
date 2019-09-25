#pragma once
#include "bnMessage.h"
#include "bnAnimatedTextbox.h"
#include <string>
#include <functional>

/**
    * @class Question
   * @author mav
   * @date 13/05/19
   * @brief Initializes yes/no message objects
   *
   * @warning honestly this design could be changed to do without the hackery and should see changes
   */
class Question : public Message {
private:
  bool yes; /*!< Flag for if yes was selected */
  std::function<void()> onYes; /*!< Callback when user presses yes */
  std::function<void()> onNo; /*!< Callback when user presses no */
  bool isQuestionReady; /*!< Flag for when the user has been prompted and input is waiting */
  mutable sf::Sprite selectCursor; /*!< Used for making selections */
  double elapsed;
  sf::Text options;
public:
  Question(std::string message, std::function<void()> onYes = std::function<void()>(), std::function<void()> onNo = std::function<void()>());
  ~Question();

  /**
  * @brief Selects yes if applicable
  * @return true if success, false otherwise
  */
  const bool SelectYes();

  /**
 * @brief Selects no if applicable
 * @return true if success, false otherwise
 */
  const bool SelectNo();

  void ExecuteSelection();

  void OnUpdate(double elapsed);
  void OnDraw(sf::RenderTarget& target, sf::RenderStates states);

  void SetTextBox(AnimatedTextBox* parent);

};
