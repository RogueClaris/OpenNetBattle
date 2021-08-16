#pragma once
#include <string>
#include <map>
#include "bnPA.h"

namespace BuiltInProgramAdvances {
	const std::map<std::string, PA::PAData> advanceList = {
		{"Zeta Cannon 1", PA::PAData{
			"Zeta Cannon 1",
			"",
			"PLAYER_IDLE",
			40,
			Element::none,
			Element::none,
			false,
			false,
			{},
			PA::Steps{
				PA::StepType { "Cannon","Cannon",'A' },
				PA::StepType { "Cannon","Cannon",'B' },
				PA::StepType { "Cannon","Cannon",'C' }
				}
			}
		},
		{"Zeta Cannon 2", PA::PAData{
			"Zeta Cannon 2",
			"",
			"PLAYER_IDLE",
			80,
			Element::none,
			Element::none,
			false,
			false,
			{},
			PA::Steps{
				PA::StepType { "HiCannon","HiCannon",'L' },
				PA::StepType { "HiCannon","HiCannon",'M' },
				PA::StepType { "HiCannon","HiCannon",'N' }
				}
			}
		},
		{"Zeta Cannon 3", PA::PAData{
			"Zeta Cannon 3",
			"",
			"PLAYER_IDLE",
			120,
			Element::none,
			Element::none,
			false,
			false,
			{},
			PA::Steps{
				PA::StepType { "M-Cannon","M-Cannon",'R' },
				PA::StepType { "M-Cannon","M-Cannon",'S' },
				PA::StepType { "M-Cannon","M-Cannon",'T' }
				}
			}
		},
		{"Dream Sword", PA::PAData{
			"Dream Sword",
			"",
			"PLAYER_SWING",
			400,
			Element::sword,
			Element::none,
			false,
			false,
			{},
			PA::Steps{
				PA::StepType { "S141L","Sword",'L' },
				PA::StepType { "S142L","WideSwrd",'L' },
				PA::StepType { "S143L","LongSwrd",'L' }
				}
			}
		},
	};
};