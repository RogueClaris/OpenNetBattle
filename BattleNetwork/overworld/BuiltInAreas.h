#pragma once
#include <string>
#include <map>
#include "../bnCard.h"
#include "bnOverworldMap.h"
#include "../bnFileUtil.h"
#include "bnOverworldSceneBase.h"

namespace Overworld {
	struct Area {
		std::string name;
		std::unique_ptr<Map&> areaMap;
		std::string filePath;
	};

	const std::map<std::string, Area> areaList = {
		{"Netopia 4", Area{"Netopia 4", nullptr, "resources/ow/maps/Netopia 4.tmx"}}
		
	};
}