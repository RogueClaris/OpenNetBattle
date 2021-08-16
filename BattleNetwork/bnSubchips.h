#pragma once

#include <string>
#include <vector>

namespace Subchips {
	class Subchip {
	private:
		std::string name;
		int hpGain = 0;
		int duration = 0;
		int numOwned = 0;
		std::string useMessage;
		int price = 0;
	public:
		void SetAmount(int amt) { this->numOwned = amt; };
		void Increase(int amt) { this->numOwned++; };
		std::string GetName() {
			return this->name;
		}
		int GetAmount() {
			return this->numOwned;
		}
		Subchip(const std::string name, const int hpGain, const std::string useMessage, const int price) { numOwned = 0, duration = 0; }
	};
}