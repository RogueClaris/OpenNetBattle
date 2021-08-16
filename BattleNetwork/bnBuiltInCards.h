#pragma once
#include <string>
#include <map>
#include "bnCard.h"

namespace BuiltInCards {
    const std::map<std::string, Battle::Card> cardList = {
        {"Cannon A", Battle::Card{{
                "S001A", //uuid unused
                40,  // damage
                99,  // limit
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
                "S001B", //uuid unused
                40,  // damage
                99,  // limit
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
                "S001C", //uuid unused
                40,  // damage
                99,  // limit
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
                "S001*", //uuid unused
                40,  // damage
                99,  // limit
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
                "S002L", //uuid unused
                80,  // damage
                99,  // limit
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
                "S002M", //uuid unused
                80,  // damage
                99,  // limit
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
            "S002N", //uuid unused
            80,  // damage
            99,  // limit
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
          { "M-Cannon R", Battle::Card{{
                  "S003R", //uuid unused
                  120,  // damage
                  99,  // limit
                  'R', // code
                  true, /*!< Can this card be boosted by other cards? */
                  false, /*!< time freeze */
                  "M-Cannon", // should be the same as the map entry 
                  "PLAYER_SHOOT", // action state name for animation
                  "Cannon attack to 1 enemy.", // battle scene hint text
                  "Fire a cannon down your row.", // detailed library scene hint text
                  Element::none, // primary element
                  Element::none, // secondary element (hidden)
                  Battle::CardClass::standard, //rank e.g. standard, mega, giga
                  {} /*!< Cards can be tagged with additional user information*/
                  }}
          },
          { "M-Cannon S", Battle::Card{{
                "S003S", //uuid unused
                120,  // damage
                99,  // limit
                'S', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "M-Cannon", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "Cannon attack to 1 enemy.", // battle scene hint text
                "Fire a cannon down your row.", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
          { "M-Cannon T", Battle::Card{{
                "S003T", //uuid unused
                120,  // damage
                99,  // limit
                'T', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "M-Cannon", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "Cannon attack to 1 enemy.", // battle scene hint text
                "Fire a cannon down your row.", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
          { "MarkCann1 K", Battle::Card{{
                  "S004K",
                  70,
                  99,
                  'K',
                  true,
                  false,
                  "MarkCann1",
                  "PLAYER_SHOOT",
                  "Sweep, lock on, and fire.",
                  "Sweep three columns ahead and fire once you lock on!",
                  Element::cursor,
                  Element::none,
                  Battle::CardClass::standard,
              {}
          }}
          },
          { "MarkCann1 M", Battle::Card{{
                "S004M",
                70,
                99,
                'M',
                true,
                false,
                "MarkCann1",
                "PLAYER_SHOOT",
                "Sweep, lock on, and fire.",
                "Sweep three columns ahead and fire once you lock on!",
                Element::cursor,
                Element::none,
                Battle::CardClass::standard,
            {}
        }}
          },
          { "MarkCann1 S", Battle::Card{{
                "S004S",
                70,
                99,
                'S',
                true,
                false,
                "MarkCann1",
                "PLAYER_SHOOT",
                "Sweep, lock on, and fire.",
                "Sweep three columns ahead and fire once you lock on!",
                Element::cursor,
                Element::none,
                Battle::CardClass::standard,
            {}
        }}
          },
          { "AirShot *", Battle::Card{{
                  "S013*",
                  20,
                  99,
                  '*',
                  true,
                  false,
                  "AirShot",
                  "PLAYER_SHOOT",
                  "Knocks an to the\nback row!",
                  "Quickly fires off a burst of air that, upon impact, pushes back foes and objects alike!",
                  Element::wind,
                  Element::none,
                  Battle::CardClass::standard,
              {}
            }}
          },
          { "Zapring *", Battle::Card{{
            "S014*",
            20,
            99,
            '*',
            true,
            false,
            "Zapring",
            "PLAYER_SHOOT",
            "Fire a stunning ring!",
            "Quickly shoots out an electrified ring that, upon impact, stuns the enemy it hits!",
            Element::elec,
            Element::none,
            Battle::CardClass::standard,
            {}
            }}
          },
          { "Vulcan1 C", Battle::Card{{
                  "S018C", //uuid unused
                  10,  // damage
                  99,  // limit
                  'C', // code
                  true, /*!< Can this card be boosted by other cards? */
                  false, /*!< time freeze */
                  "Vulcan1", // should be the same as the map entry 
                  "PLAYER_SHOOT", // action state name for animation
                  "3-shots pierce 1pnl!", // battle scene hint text
                  "Rat-a-tat-tat!", // detailed library scene hint text
                  Element::none, // primary element
                  Element::none, // secondary element (hidden)
                  Battle::CardClass::standard, //rank e.g. standard, mega, giga
                  {} /*!< Cards can be tagged with additional user information*/
                  }}
          },
            { "Vulcan1 D", Battle::Card{{
                "S018D", //uuid unused
                10,  // damage
                99,  // limit
                'D', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Vulcan1", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "3-shots pierce 1pnl!", // battle scene hint text
                "Rat-a-tat-tat!", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
            },
            { "Vulcan1 E", Battle::Card{{
                "S018E", //uuid unused
                10,  // damage
                99,  // limit
                'E', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Vulcan1", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "3-shots pierce 1pnl!", // battle scene hint text
                "Rat-a-tat-tat!", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
            },
        {"Vulcan2 B", Battle::Card{{
                "S019B", //uuid unused
                10,  // damage
                99,  // limit
                'B', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Vulcan2", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "5-shots pierce 1pnl!", // battle scene hint text
                "Rat-a-tat-tat!", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
        },
          {"Vulcan3 M", Battle::Card{{
                "S020M", //uuid unused
                10,  // damage
                99,  // limit
                'M', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "Vulcan3", // should be the same as the map entry 
                "PLAYER_SHOOT", // action state name for animation
                "7-shots pierce 1pnl!", // battle scene hint text
                "Rat-a-tat-tat!", // detailed library scene hint text
                Element::none, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
          { "Minibomb *", Battle::Card{{
                  "S078*",
                  50,
                  99,
                  '*',
                  true,
                  false,
                  "Minibomb",
                  "PLAYER_THROW",
                  "Throw a bomb 3sq ahead!",
                  "Throw a small, modestly powerful bomb three tiles ahead! Explodes on imapct!",
                  Element::none,
                  Element::none,
                  Battle::CardClass::standard,
              {}
            }}
          },
          { "Sword A", Battle::Card{{
                  "S141A", //uuid unused
                  80,  // damage
                  99,  // limit
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
          },
          { "Sword L", Battle::Card{{
            "S141L", //uuid unused
            80,  // damage
            99,  // limit
            'L', // code
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
          },
          { "Sword S", Battle::Card{{
            "S141S", //uuid unused
            80,  // damage
            99,  // limit
            'S', // code
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
          },
          { "Sword Y", Battle::Card{{
            "S141Y", //uuid unused
            80,  // damage
            99,  // limit
            'Y', // code
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
          },
        { "WideSword A", Battle::Card{{
              "S142A", //uuid unused
              80,  // damage
              99,  // limit
              'A', // code
              true, /*!< Can this card be boosted by other cards? */
              false, /*!< time freeze */
              "WideSwrd", // should be the same as the map entry 
              "PLAYER_SWING", // action state name for animation
              "Slash 1sq ahead, 3sq wide!", // battle scene hint text
              "Take out a wide sword and slash directly ahead! Hits up to 3 targets!", // detailed library scene hint text
              Element::sword, // primary element
              Element::none, // secondary element (hidden)
              Battle::CardClass::standard, //rank e.g. standard, mega, giga
              {} /*!< Cards can be tagged with additional user information*/
              }}
        },
        { "WideSword L", Battle::Card{{
          "S142L", //uuid unused
          80,  // damage
          99,  // limit
          'L', // code
          true, /*!< Can this card be boosted by other cards? */
          false, /*!< time freeze */
          "WideSwrd", // should be the same as the map entry 
          "PLAYER_SWING", // action state name for animation
          "Slash 1sq ahead, 3sq wide!", // battle scene hint text
          "Take out a wide sword and slash directly ahead! Hits up to 3 targets!", // detailed library scene hint text
          Element::sword, // primary element
          Element::none, // secondary element (hidden)
          Battle::CardClass::standard, //rank e.g. standard, mega, giga
          {} /*!< Cards can be tagged with additional user information*/
          }}
        },
        { "WideSword S", Battle::Card{{
          "S142S", //uuid unused
          80,  // damage
          99,  // limit
          'S', // code
          true, /*!< Can this card be boosted by other cards? */
          false, /*!< time freeze */
          "WideSwrd", // should be the same as the map entry 
          "PLAYER_SWING", // action state name for animation
          "Slash 1sq ahead, 3sq wide!", // battle scene hint text
          "Take out a wide sword and slash directly ahead! Hits up to 3 targets!", // detailed library scene hint text
          Element::sword, // primary element
          Element::none, // secondary element (hidden)
          Battle::CardClass::standard, //rank e.g. standard, mega, giga
          {} /*!< Cards can be tagged with additional user information*/
          }}
        },
        { "WideSword Y", Battle::Card{{
          "S142Y", //uuid unused
          80,  // damage
          99,  // limit
          'Y', // code
          true, /*!< Can this card be boosted by other cards? */
          false, /*!< time freeze */
          "WideSwrd", // should be the same as the map entry 
          "PLAYER_SWING", // action state name for animation
          "Slash 1sq ahead, 3sq wide!", // battle scene hint text
          "Take out a wide sword and slash directly ahead! Hits up to 3 targets!", // detailed library scene hint text
          Element::sword, // primary element
          Element::none, // secondary element (hidden)
          Battle::CardClass::standard, //rank e.g. standard, mega, giga
          {} /*!< Cards can be tagged with additional user information*/
          }}
        },
          { "LongSword A", Battle::Card{{
                "S143A", //uuid unused
                80,  // damage
                99,  // limit
                'A', // code
                true, /*!< Can this card be boosted by other cards? */
                false, /*!< time freeze */
                "LongSwrd", // should be the same as the map entry 
                "PLAYER_SWING", // action state name for animation
                "Slash 2sq ahead!!", // battle scene hint text
                "Take out a Long sword and slash directly ahead! Hits up to 2 targets!", // detailed library scene hint text
                Element::sword, // primary element
                Element::none, // secondary element (hidden)
                Battle::CardClass::standard, //rank e.g. standard, mega, giga
                {} /*!< Cards can be tagged with additional user information*/
                }}
          },
          { "LongSword L", Battle::Card{{
            "S143L", //uuid unused
            80,  // damage
            99,  // limit
            'L', // code
            true, /*!< Can this card be boosted by other cards? */
            false, /*!< time freeze */
            "LongSwrd", // should be the same as the map entry 
            "PLAYER_SWING", // action state name for animation
            "Slash 2sq ahead!!", // battle scene hint text
            "Take out a Long sword and slash directly ahead! Hits up to 2 targets!", // detailed library scene hint text
            Element::sword, // primary element
            Element::none, // secondary element (hidden)
            Battle::CardClass::standard, //rank e.g. standard, mega, giga
            {} /*!< Cards can be tagged with additional user information*/
            }}
          },
          { "LongSword S", Battle::Card{{
            "S143S", //uuid unused
            80,  // damage
            99,  // limit
            'S', // code
            true, /*!< Can this card be boosted by other cards? */
            false, /*!< time freeze */
            "LongSwrd", // should be the same as the map entry 
            "PLAYER_SWING", // action state name for animation
            "Slash 2sq ahead!!", // battle scene hint text
            "Take out a Long sword and slash directly ahead! Hits up to 2 targets!", // detailed library scene hint text
            Element::sword, // primary element
            Element::none, // secondary element (hidden)
            Battle::CardClass::standard, //rank e.g. standard, mega, giga
            {} /*!< Cards can be tagged with additional user information*/
            }}
          },
          { "LongSword Y", Battle::Card{{
            "S143Y", //uuid unused
            80,  // damage
            99,  // limit
            'Y', // code
            true, /*!< Can this card be boosted by other cards? */
            false, /*!< time freeze */
            "LongSwrd", // should be the same as the map entry 
            "PLAYER_SWING", // action state name for animation
            "Slash 2sq ahead!!", // battle scene hint text
            "Take out a Long sword and slash directly ahead! Hits up to 2 targets!", // detailed library scene hint text
            Element::sword, // primary element
            Element::none, // secondary element (hidden)
            Battle::CardClass::standard, //rank e.g. standard, mega, giga
            {} /*!< Cards can be tagged with additional user information*/
            }}
          },
        { "FireSword E", Battle::Card{{
            "S151E", //uuid unused
            140,  // damage
            99,  // limit
            'E', // code
            true, /*!< Can this card be boosted by other cards? */
            false, /*!< time freeze */
            "FireSwrd", // should be the same as the map entry 
            "PLAYER_SWING", // action state name for animation
            "Fire sword swings 2sq deep!", // battle scene hint text
            "Swing a blade of flames!", // detailed library scene hint text
            Element::fire, // primary element
            Element::sword, // secondary element (hidden)
            Battle::CardClass::standard, //rank e.g. standard, mega, giga
            {"slow_burn"} /*!< Cards can be tagged with additional user information*/
            }}
        },
        { "WindRack F", Battle::Card{{
              "S166F", //uuid unused
              140,  // damage
              99,  // limit
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
          { "YoYo1 L", Battle::Card{{
              "S189L", //uuid unused
              40,  // damage
              99,  // limit
              'L', // code
              true, /*!< Can this card be boosted by other cards? */
              false, /*!< time freeze */
              "YoYo1", // should be the same as the map entry 
              "PLAYER_SHOOT", // action state name for animation
              "Bladed YoYo 3sq ahead!", // battle scene hint text
              "Press A to shoot a YoYo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
              Element::sword, // primary element
              Element::none, // secondary element (hidden)
              Battle::CardClass::standard, //rank e.g. standard, mega, giga
              {} /*!< Cards can be tagged with additional user information*/
              }}
          },
          { "YoYo1 M", Battle::Card{{
                  "S189M", //uuid unused
                  40,  // damage
                  99,  // limit
                  'M', // code
                  true, /*!< Can this card be boosted by other cards? */
                  false, /*!< time freeze */
                  "YoYo1", // should be the same as the map entry 
                  "PLAYER_SHOOT", // action state name for animation
                  "Bladed YoYo 3sq ahead!", // battle scene hint text
                  "Press A to shoot a YoYo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
                  Element::sword, // primary element
                  Element::none, // secondary element (hidden)
                  Battle::CardClass::standard, //rank e.g. standard, mega, giga
                  {} /*!< Cards can be tagged with additional user information*/
                  }}
          },
          { "YoYo1 N", Battle::Card{{
              "S189N", //uuid unused
              40,  // damage
              99,  // limit
              'N', // code
              true, /*!< Can this card be boosted by other cards? */
              false, /*!< time freeze */
              "YoYo1", // should be the same as the map entry 
              "PLAYER_SHOOT", // action state name for animation
              "Bladed YoYo 3sq ahead!", // battle scene hint text
              "Press A to shoot a YoYo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
              Element::sword, // primary element
              Element::none, // secondary element (hidden)
              Battle::CardClass::standard, //rank e.g. standard, mega, giga
              {} /*!< Cards can be tagged with additional user information*/
              }}
          },
          { "YoYo1 *", Battle::Card{{
              "S189*", //uuid unused
              40,  // damage
              99,  // limit
              '*', // code
              true, /*!< Can this card be boosted by other cards? */
              false, /*!< time freeze */
              "YoYo1", // should be the same as the map entry 
              "PLAYER_SHOOT", // action state name for animation
              "Bladed YoYo 3sq ahead!", // battle scene hint text
              "Press A to shoot a YoYo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
              Element::sword, // primary element
              Element::none, // secondary element (hidden)
              Battle::CardClass::standard, //rank e.g. standard, mega, giga
              {} /*!< Cards can be tagged with additional user information*/
              }}
          },
          { "YoYo2 J", Battle::Card{{
              "S190J", //uuid unused
              50,
              99,
              'J',
              true,
              false,
              "YoYo2",
              "PLAYER_SHOOT",
              "Bladed YoYo 3sq ahead!",
              "Press A to shoot a YoYo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
              Element::sword,
              Element::none,
              Battle::CardClass::standard,
              {}
              }}
          },
          { "YoYo2 K", Battle::Card{{
              "S190K", //uuid unused
              50,
              99,
              'K',
              true,
              false,
              "YoYo2",
              "PLAYER_SHOOT",
              "Bladed YoYo 3sq ahead!",
              "Press A to shoot a YoYo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
              Element::sword,
              Element::none,
              Battle::CardClass::standard,
              {}
              }}
          },
          { "YoYo2 L", Battle::Card{{
              "S190L", //uuid unused
              50,
              99,
              'L',
              true,
              false,
              "YoYo2",
              "PLAYER_SHOOT",
              "Bladed YoYo 3sq ahead!",
              "Press A to shoot a YoYo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
              Element::sword,
              Element::none,
              Battle::CardClass::standard,
              {}
              }}
          },
          { "YoYo3 C", Battle::Card{{
                  "S191C", //uuid unused
                  60,
                  99,
                  'C',
                  true,
                  false,
                  "YoYo3",
                  "PLAYER_SHOOT",
                  "Bladed YoYo 3sq ahead!",
                  "Press A to shoot a YoYo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
                  Element::sword,
                  Element::none,
                  Battle::CardClass::standard,
                  {}
                  }}
          },
          { "YoYo3 D", Battle::Card{{
                  "S191D", //uuid unused
                  60,
                  99,
                  'D',
                  true,
                  false,
                  "YoYo3",
                  "PLAYER_SHOOT",
                  "Bladed YoYo 3sq ahead!",
                  "Press A to shoot a YoYo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
                  Element::sword,
                  Element::none,
                  Battle::CardClass::standard,
                  {}
                  }}
          },
          { "YoYo3 E", Battle::Card{{
                  "S191E", //uuid unused
                  60,
                  99,
                  'E',
                  true,
                  false,
                  "YoYo3",
                  "PLAYER_SHOOT",
                  "Bladed YoYo 3sq ahead!",
                  "Press A to shoot a YoYo across the field 2 spaces. Hits 3 times and returns to sender.", // detailed library scene hint text
                  Element::sword,
                  Element::none,
                  Battle::CardClass::standard,
                  {}
                  }}
          },
          { "Thunder1 B", Battle::Card{{
                  "S245B",
                  40,
                  99,
                  'B',
                  true,
                  false,
                  "Thunder1",
                  "PLAYER_SHOOT",
                  "Thunder chases the enmy!",
                  "Pressing A unleashes a ball of lightning which slowly seeks out a target.",
                  Element::elec,
                  Element::none,
                  Battle::CardClass::standard,
              {}
          }}
          },
          { "Thunder1 L", Battle::Card{{
              "S245L",
              40,
              99,
              'L',
              true,
              false,
              "Thunder1",
              "PLAYER_SHOOT",
              "Thunder chases the enmy!",
              "Pressing A unleashes a ball of lightning which slowly seeks out a target.",
              Element::elec,
              Element::none,
              Battle::CardClass::standard,
          {}
      }}
          },
          { "Thunder1 P", Battle::Card{{
              "S245P",
              40,
              99,
              'P',
              true,
              false,
              "Thunder1",
              "PLAYER_SHOOT",
              "Thunder chases the enmy!",
              "Pressing A unleashes a ball of lightning which slowly seeks out a target.",
              Element::elec,
              Element::none,
              Battle::CardClass::standard,
          {}
      }}
          },
          { "Thunder1 *", Battle::Card{{
              "S245*",
              40,
              99,
              '*',
              true,
              false,
              "Thunder1",
              "PLAYER_SHOOT",
              "Thunder chases the enmy!",
              "Pressing A unleashes a ball of lightning which slowly seeks out a target.",
              Element::elec,
              Element::none,
              Battle::CardClass::standard,
          {}
      }}
          },
          { "RockCube *", Battle::Card{{
          "S449*",
          0,
          99,
          '*',
          true,
          false,
          "RockCube",
          "PLAYER_IDLE",
          "Cube of stone appears!",
          "Places a Rock Cube in front of the user. Combine with Wind for heavy damage!",
          Element::summon,
          Element::none,
          Battle::CardClass::standard,
          {}
          }}
          },
          { "Recov10 *", Battle::Card{{
          "S554*",
          10,
          0,
          '*',
          false,
          false,
          "Recov10",
          "PLAYER_IDLE",
          "Heal up for 10HP!",
          "This handy chip restores 10HP! Use it in a pinch!",
          Element::plus,
          Element::none,
          Battle::CardClass::standard,
          {}
          }}
          },
          { "CrackShot A", Battle::Card{{
              "S580A", //uuid unused
              60,
              99,
              'A',
              true,
              false,
              "CrakShot",
              "PLAYER_SWORD",
              "Throw pnl forward!",
              "Using this chip breaks the panel in front of you and sends it flying as a projectile!", // detailed library scene hint text
              Element::none,
              Element::none,
              Battle::CardClass::standard,
              {}
              }}
          },
          { "Barrier E", Battle::Card{{
                  "S669E",
                  0,
                  99,
                  'E',
                  false,
                  true,
                  "Barrier",
                  "PLAYER_IDLE",
                  "Summon 10HP Barrier!",
                  "When you use this chip, you gain a barrier that defends against 10HP of damage. Overkill won't bleed through!",
                  Element::none,
                  Element::none,
                  Battle::CardClass::standard,
              {}
            }}
          },
          { "Barrier R", Battle::Card{{
              "S669R",
              0,
              99,
              'R',
              false,
              true,
              "Barrier",
              "PLAYER_IDLE",
              "Summon 10HP Barrier!",
              "When you use this chip, you gain a barrier that defends against 10HP of damage. Overkill won't bleed through!",
              Element::none,
              Element::none,
              Battle::CardClass::standard,
          {}
        }}
          },
          { "Barrier Y", Battle::Card{{
              "S669Y",
              0,
              99,
              'Y',
              false,
              true,
              "Barrier",
              "PLAYER_IDLE",
              "Summon 10HP Barrier!",
              "When you use this chip, you gain a barrier that defends against 10HP of damage. Overkill won't bleed through!",
              Element::none,
              Element::none,
              Battle::CardClass::standard,
              {}
            }}
          },
          { "Barr100 Y", Battle::Card{{
          "S670Y",
          0,
          99,
          'Y',
          false,
          true,
          "Barr100",
          "PLAYER_IDLE",
          "Summon 100HP Barrier!",
          "When you use this chip, you gain a barrier that defends against 100HP of damage. Overkill won't bleed through!",
          Element::none,
          Element::none,
          Battle::CardClass::standard,
              {}
            }}
          },
          { "Barr200 Y", Battle::Card{{
              "S671Y",
              0,
              99,
              'Y',
              false,
              true,
              "Barr200",
              "PLAYER_IDLE",
              "Summon 200HP Barrier!",
              "When you use this chip, you gain a barrier that defends against 200HP of damage. Overkill won't bleed through!",
              Element::none,
              Element::none,
              Battle::CardClass::standard,
                {}
                }}
          },
          { "Atk+10 *", Battle::Card{{
          "S712*",
          0,
          99,
          '*',
          false,
          false,
          "Atk+10",
          "PLAYER_IDLE",
          "Next Chip dmg +10!",
          "This chip does nothing on its own! Select it after an attack chip to deal more damage!",
          Element::plus,
          Element::none,
          Battle::CardClass::standard,
          {"booster"}
          }}
          },
          { "Zeta Cannon 1", Battle::Card{{
          "P001",
          40,
          99,
          '*',
          true,
          false,
          "Zeta Cannon 1",
          "PLAYER_IDLE",
          "How are you reading this?",
          "This chip is a program advance! How did you get your hands on it!?",
          Element::none,
          Element::none,
          Battle::CardClass::giga,
          {"Program Advance"}
          }}
          },
          { "Zeta Cannon 2", Battle::Card{{
          "P002",
          80,
          99,
          '*',
          true,
          false,
          "Zeta Cannon 2",
          "PLAYER_IDLE",
          "How are you reading this?",
          "This chip is a program advance! How did you get your hands on it!?",
          Element::none,
          Element::none,
          Battle::CardClass::giga,
          {"Program Advance"}
          }}
              },
          { "Zeta Cannon 3", Battle::Card{{
              "P003",
              120,
              99,
              '*',
              true,
              false,
              "Zeta Cannon 3",
              "PLAYER_IDLE",
              "How are you reading this?",
              "This chip is a program advance! How did you get your hands on it!?",
              Element::none,
              Element::none,
              Battle::CardClass::giga,
              {"Program Advance"}
              }}
          },
          { "Dream Sword", Battle::Card{{
          "P023",
          400,
          99,
          '*',
          true,
          false,
          "Dream Sword",
          "PLAYER_SWING",
          "How are you reading this?",
          "This chip is a program advance! How did you get your hands on it!?",
          Element::sword,
          Element::none,
          Battle::CardClass::giga,
          {"Program Advance"}
          }}
          },
  };
}