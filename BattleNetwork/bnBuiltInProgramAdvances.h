#pragma once
#include <string>
#include <map>
#include "bnPA.h"

namespace BuiltInProgramAdvances {
	const std::map<std::string, PA::PAData> advanceList = {
		{"Zeta Cannon 1", PA::PAData{
			"Zeta Cannon 1",
			"",
			"PLAYER_SHOOT",
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
		}
	};
};