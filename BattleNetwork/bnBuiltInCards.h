#pragma once
#include <string>
#include <map>
#include "bnCard.h"

namespace BuiltInCards {
    const std::map<int, Battle::Card> cardList = {
          {0, Battle::Card{{
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
                Element::sword, // primary element
                Element::breaker, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
          {1, Battle::Card{{
                "", // uuid unused
                80,  // damage
                0,  // limit
                'F', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "FireSwrd", // should be the same as the map entry 
                "PLAYER_SWING", // action state name for animation
                "Fire long sword", // battle scene hint text
                "Swing a blade of flames!", // detailed library scene hint text
                Element::fire, // primary element
                Element::sword, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {"slow_burn"} /*!< Cards can be tagged with additional user information*/
                }}
          },
          {2, Battle::Card{{
                "", // uuid unused
                15,  // damage
                0,  // limit
                'F', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Vulcan2", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "4-shot burst!", // battle scene hint text
                "Rat-a-tat-tat!", // detailed library scene hint text
                Element::cursor, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
        },
        {3, Battle::Card{{
                "", // uuid unused
                140,  // damage
                0,  // limit
                'F', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "WindRack", // should be the same as the map entry 
                "PLAYER_SWING", // action state name for animation
                "Racket of Wind", // battle scene hint text
                "Swing wide and blow them away!", // detailed library scene hint text
                Element::wind, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
        }
  };
}