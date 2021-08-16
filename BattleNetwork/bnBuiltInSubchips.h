#pragma once

#include "bnSubchips.h"
#include <vector>

namespace BuiltInSubchips {
	const std::vector<Subchips::Subchip> SubchipList{
		Subchips::Subchip("SmlEnrgy", 150, "used a Small Energy! 150HP restored!", 300),
		Subchips::Subchip("MedEnrgy", 300, "used a Medium Energy! 300HP restored!", 600),
		Subchips::Subchip("LrgEnrgy", 500, "used a Large Energy! 500HP restored!", 1250),
		Subchips::Subchip("MaxEnrgy", 9999, "used a Max Energy! All HP restored!", 2500),
	};
};