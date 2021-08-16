#pragma once

#include <map>
#include <string>
#include <vector>
#include <optional>

namespace MobRewards {
	const std::map<std::string, std::vector<std::vector<std::string>>> RewardList = {
		{"Canodumb", {{"Card", "S001*", "10"}, {"Card", "S001A", "7"}, {"Card", "S001B", "5"}, {"Card", "S001C", "3"}, {"Money", "100", "1"}}},
		{"Canodumb2", {{"Card", "S002L", "7"}, {"Card", "S002M", "5"}, {"Card", "S002N", "3"}, {"Money", "250", "1"}}},
		{"Canodumb3", {{"Card", "S003R", "7"}, {"Card", "S003S", "5"}, {"Card", "S003T", "3"}, {"Money", "400", "1"}}},
		{"Starfish", {{"Money", "100", "1"}}},
		{"StarfishSP", {{"Money", "300", "1"}}},
		{"Metrid", {{"Money", "200", "1"}}},
	};
	std::vector<std::vector<std::string>> LookupReward(std::string name) {
		for (auto& [key, value] : MobRewards::RewardList) {
			if (key == name) {
				return value;
			}
		}
		return std::vector<std::vector<std::string>>{};
	};
}