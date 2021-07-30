#pragma once
#include <string>
#include <map>
#include "bnCard.h"

namespace BuiltInCards {
    const std::map<std::string, Battle::Card> cardList = {
        {"Cannon A", Battle::Card{{
                "", //uuid unused
                40,  // damage
                0,  // limit
                'A', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Cannon", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "Cannon attack to 1 enemy.", // battle scene hint text
                "Fire a cannon down your row.", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
        {"Cannon B", Battle::Card{{
                "", //uuid unused
                40,  // damage
                0,  // limit
                'B', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Cannon", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "Cannon attack to 1 enemy.", // battle scene hint text
                "Fire a cannon down your row.", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
        {"Cannon C", Battle::Card{{
                "", //uuid unused
                40,  // damage
                0,  // limit
                'C', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Cannon", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "Cannon attack to 1 enemy.", // battle scene hint text
                "Fire a cannon down your row.", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
        {"Cannon *", Battle::Card{{
                "", //uuid unused
                40,  // damage
                0,  // limit
                '*', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Cannon", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "Cannon attack to 1 enemy.", // battle scene hint text
                "Fire a cannon down your row.", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
        {"HiCannon L", Battle::Card{{
                "", //uuid unused
                80,  // damage
                0,  // limit
                'L', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "HiCannon", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "Cannon attack to 1 enemy.", // battle scene hint text
                "Fire a cannon down your row.", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
        {"HiCannon M", Battle::Card{{
                "", //uuid unused
                80,  // damage
                0,  // limit
                'M', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "HiCannon", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "Cannon attack to 1 enemy.", // battle scene hint text
                "Fire a cannon down your row.", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
          {"HiCannon N", Battle::Card{{
            "", //uuid unused
            80,  // damage
            0,  // limit
            'N', // code
            true, /*!< Can this card be boosted by other cards? */
            false, /*!< time freeze */
            "HiCannon", // should be the same as the map entry 
            "PLAYER_SHOOT", // action state name for animation
            "Cannon attack to 1 enemy.", // battle scene hint text
            "Fire a cannon down your row.", // detailed library scene hint text
            Element::none, // primary element
            Element::none, // secondary element (hidden)
            Battle::CardClass::standard, //rank e.g. standard, mega, giga
            {} /*!< Cards can be tagged with additional user information*/
            }}
          },
          { "MCannon R", Battle::Card{{
                  "", //uuid unused
                  120,  // damage
                  0,  // limit
                  'R', // code
                  true, /*!< Can this card be boosted by other cards? */
                  false, /*!< time freeze */
                  "MCannon", // should be the same as the map entry 
                  "PLAYER_SHOOT", // action state name for animation
                  "Cannon attack to 1 enemy.", // battle scene hint text
                  "Fire a cannon down your row.", // detailed library scene hint text
                  Element::none, // primary element
                  Element::none, // secondary element (hidden)
                  Battle::CardClass::standard, //rank e.g. standard, mega, giga
                  {} /*!< Cards can be tagged with additional user information*/
                  }}
          },
          { "MCannon S", Battle::Card{{
                "", //uuid unused
                120,  // damage
                0,  // limit
                'S', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "MCannon", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "Cannon attack to 1 enemy.", // battle scene hint text
                "Fire a cannon down your row.", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
          { "MCannon T", Battle::Card{{
                "", //uuid unused
                120,  // damage
                0,  // limit
                'T', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "MCannon", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "Cannon attack to 1 enemy.", // battle scene hint text
                "Fire a cannon down your row.", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
          { "Yoyo1 L", Battle::Card{{
                  "", //uuid unused
                  40,  // damage
                  0,  // limit
                  'L', // code
                  true, /*!< Can this card be boosted by other cards? */
                  false, /*!< time freeze */
                  "Yoyo1", // should be the same as the map entry 
                  "PLAYER_SHOOT", // action state name for animation
                  "Bladed YoYo 3sq ahead!", // battle scene hint text
                  "Press A to shoot a yoyo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
                  Element::sword, // primary element
                  Element::none, // secondary element (hidden)
                  Battle::CardClass::standard, //rank e.g. standard, mega, giga
                  {} /*!< Cards can be tagged with additional user information*/
                  }}
          },
          { "Yoyo1 M", Battle::Card{{
                  "", //uuid unused
                  40,  // damage
                  0,  // limit
                  'M', // code
                  true, /*!< Can this card be boosted by other cards? */
                  false, /*!< time freeze */
                  "Yoyo1", // should be the same as the map entry 
                  "PLAYER_SHOOT", // action state name for animation
                  "Bladed YoYo 3sq ahead!", // battle scene hint text
                  "Press A to shoot a yoyo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
                  Element::sword, // primary element
                  Element::none, // secondary element (hidden)
                  Battle::CardClass::standard, //rank e.g. standard, mega, giga
                  {} /*!< Cards can be tagged with additional user information*/
                  }}
          },
          { "Yoyo1 N", Battle::Card{{
              "", //uuid unused
              40,  // damage
              0,  // limit
              'N', // code
              true, /*!< Can this card be boosted by other cards? */
              false, /*!< time freeze */
              "Yoyo1", // should be the same as the map entry 
              "PLAYER_SHOOT", // action state name for animation
              "Bladed YoYo 3sq ahead!", // battle scene hint text
              "Press A to shoot a yoyo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
              Element::sword, // primary element
              Element::none, // secondary element (hidden)
              Battle::CardClass::standard, //rank e.g. standard, mega, giga
              {} /*!< Cards can be tagged with additional user information*/
              }}
          },
          { "Yoyo1 *", Battle::Card{{
              "", //uuid unused
              40,  // damage
              0,  // limit
              '*', // code
              true, /*!< Can this card be boosted by other cards? */
              false, /*!< time freeze */
              "Yoyo1", // should be the same as the map entry 
              "PLAYER_SHOOT", // action state name for animation
              "Bladed YoYo 3sq ahead!", // battle scene hint text
              "Press A to shoot a yoyo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
              Element::sword, // primary element
              Element::none, // secondary element (hidden)
              Battle::CardClass::standard, //rank e.g. standard, mega, giga
              {} /*!< Cards can be tagged with additional user information*/
              }}
          },
          { "Yoyo2 J", Battle::Card{{
              "", //uuid unused
              50,
              0,
              'J',
              true,
              false,
              "Yoyo2",
              "PLAYER_SHOOT",
              "Bladed YoYo 3sq ahead!",
              "Press A to shoot a yoyo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
              Element::sword,
              Element::none,
              Battle::CardClass::standard,
              {}
              }}
          },
          { "Yoyo2 K", Battle::Card{{
              "", //uuid unused
              50,
              0,
              'K',
              true,
              false,
              "Yoyo2",
              "PLAYER_SHOOT",
              "Bladed YoYo 3sq ahead!",
              "Press A to shoot a yoyo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
              Element::sword,
              Element::none,
              Battle::CardClass::standard,
              {}
              }}
          },
          { "Yoyo2 L", Battle::Card{{
              "", //uuid unused
              50,
              0,
              'L',
              true,
              false,
              "Yoyo2",
              "PLAYER_SHOOT",
              "Bladed YoYo 3sq ahead!",
              "Press A to shoot a yoyo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
              Element::sword,
              Element::none,
              Battle::CardClass::standard,
              {}
              }}
          },
          { "Yoyo3 C", Battle::Card{{
                  "", //uuid unused
                  60,
                  0,
                  'C',
                  true,
                  false,
                  "Yoyo3",
                  "PLAYER_SHOOT",
                  "Bladed YoYo 3sq ahead!",
                  "Press A to shoot a yoyo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
                  Element::sword,
                  Element::none,
                  Battle::CardClass::standard,
                  {}
                  }}
          },
          { "Yoyo3 D", Battle::Card{{
                  "", //uuid unused
                  60,
                  0,
                  'D',
                  true,
                  false,
                  "Yoyo3",
                  "PLAYER_SHOOT",
                  "Bladed YoYo 3sq ahead!",
                  "Press A to shoot a yoyo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
                  Element::sword,
                  Element::none,
                  Battle::CardClass::standard,
                  {}
                  }}
          },
          { "Yoyo3 E", Battle::Card{{
                  "", //uuid unused
                  60,
                  0,
                  'E',
                  true,
                  false,
                  "Yoyo3",
                  "PLAYER_SHOOT",
                  "Bladed YoYo 3sq ahead!",
                  "Press A to shoot a yoyo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
                  Element::sword,
                  Element::none,
                  Battle::CardClass::standard,
                  {}
                  }}
          },

          {"FireSword E", Battle::Card{{
                "", //uuid unused
                140,  // damage
                0,  // limit
                'E', // code
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
          { "Vulcan1 C", Battle::Card{{
                  "", //uuid unused
                  10,  // damage
                  0,  // limit
                  'C', // code
                  true, /*!< Can this card be boosted by other cards? */
                  false, /*!< time freeze */
                  "Vulcan1", // should be the same as the map entry 
                  "PLAYER_SHOOT", // action state name for animation
                  "3-shot burst!", // battle scene hint text
                  "Rat-a-tat-tat!", // detailed library scene hint text
                  Element::none, // primary element
                  Element::none, // secondary element (hidden)
                  Battle::CardClass::standard, //rank e.g. standard, mega, giga
                  {} /*!< Cards can be tagged with additional user information*/
                  }}
          },
            { "Vulcan1 D", Battle::Card{{
                "", //uuid unused
                10,  // damage
                0,  // limit
                'D', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Vulcan1", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "3-shot burst!", // battle scene hint text
                "Rat-a-tat-tat!", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
            },
            { "Vulcan1 E", Battle::Card{{
                "", //uuid unused
                10,  // damage
                0,  // limit
                'E', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Vulcan1", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "3-shot burst!", // battle scene hint text
                "Rat-a-tat-tat!", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
            },
        {"Vulcan2 B", Battle::Card{{
                "", //uuid unused
                10,  // damage
                0,  // limit
                'B', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Vulcan2", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "5-shot burst!", // battle scene hint text
                "Rat-a-tat-tat!", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
        },
          {"Vulcan3 M", Battle::Card{{
                "", //uuid unused
                10,  // damage
                0,  // limit
                'M', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Vulcan3", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "7-shot burst!", // battle scene hint text
                "Rat-a-tat-tat!", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
          { "WindRack F", Battle::Card{{
                  "", //uuid unused
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
          },
          { "Sword A", Battle::Card{{
                  "", //uuid unused
                  140,  // damage
                  0,  // limit
                  'A', // code
                  true, /*!< Can this card be boosted by other cards? */
                  false, /*!< time freeze */
                  "Sword", // should be the same as the map entry 
                  "PLAYER_SWING", // action state name for animation
                  "Slash 1sq ahead!", // battle scene hint text
                  "Take out a small sword and slash directly ahead!", // detailed library scene hint text
                  Element::sword, // primary element
                  Element::none, // secondary element (hidden)
                  Battle::CardClass::standard, //rank e.g. standard, mega, giga
                  {} /*!< Cards can be tagged with additional user information*/
                  }}
          }
  };
}