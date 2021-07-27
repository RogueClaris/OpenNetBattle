#include "bnAmeroppaBackground.h"
#include "bnLogger.h"
#include "bnTextureResourceManager.h"
#include "bnGame.h"

#define COMPONENT_WIDTH 128
#define COMPONENT_HEIGHT 256

#define PATH std::string("resources/scenes/ameroppa/")

AmeroppaBackground::AmeroppaBackground() :
	x(0.0f),
	y(0.0f),
	IBackground<AmeroppaBackground>(Textures().LoadTextureFromFile(PATH + "bg.png"), 240, 180)
{
	FillScreen(sf::Vector2u(COMPONENT_WIDTH, COMPONENT_HEIGHT));

	animation = Animation(PATH + "bg.animation");
	animation.Load();
	animation.SetAnimation("BG");
	animation << Animator::Mode::Loop;
}

AmeroppaBackground::~AmeroppaBackground() {
}

void AmeroppaBackground::Update(double _elapsed) {

	animation.Update(_elapsed, dummy);

	y += 0.25f * static_cast<float>(_elapsed);
	x += 0.25f * static_cast<float>(_elapsed);

	if (x > 1) x = 0;
	if (y > 1) y = 0;

	Wrap(sf::Vector2f(x, y));

	// Grab the subrect used in the sprite from animation Update() call
	TextureOffset(dummy.getTextureRect());
}