#pragma once
#include <map>
#include <string>
#include "../../bnCard.h"

namespace BuiltInCards {
    const std::map<std::string, Battle::Card> cardList = {
      {"Yoyo1", Battle::Card{{
        "", // uuid unused
        40,  // damage
        0,  // limit
        '*', // code
        true, /*!< Can this card be boosted by other cards? */
        false, /*!< time freeze */
        "Yoyo1", // should be the same as the map entry 
        "PLAYER_SHOOT", // action state name for animation
        "Shoot 3 tiles, hits 3 times!", // battle scene hint text
        "Press A to shoot a yoyo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
        Element::none, // primary element
        Element::none, // secondary element (hidden)
        Battle::CardClass::standard, //rank e.g. standard, mega, giga
        {} /*!< Cards can be tagged with additional user information*/
        }}
      },
      {"FireSwrd", Battle::Card{{
        "", // uuid unused
        80,  // damage
        0,  // limit
        'F', // code
        true, /*!< Can this card be boosted by other cards? */
        false, /*!< time freeze */
        "FireSwrd", // should be the same as the map entry 
        "PLAYER_SWING", // action state name for animation
        "Fire long sword", // battle scene hint text
        "", // detailed library scene hint text
        Element::fire, // primary element
        Element::none, // secondary element (hidden)
        Battle::CardClass::standard, //rank e.g. standard, mega, giga
        {"slow_burn"} /*!< Cards can be tagged with additional user information*/
        }}
      },
    };
}