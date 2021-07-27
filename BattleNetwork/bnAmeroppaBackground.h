#pragma once
#include <SFML/Graphics.hpp>
using sf::Texture;
using sf::Sprite;
using sf::IntRect;
using sf::Drawable;
#include <vector>
using std::vector;

#include "bnAnimation.h"
#include "bnBackground.h"

class AmeroppaBackground final : public IBackground<AmeroppaBackground>
{
public:
	AmeroppaBackground();
	~AmeroppaBackground();

	void Update(double _elapsed) override;

private:
	float x, y;
	Animation animation;
	sf::Sprite dummy;
};
