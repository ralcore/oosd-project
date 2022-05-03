#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	Player(float posx, float posy);
	void tick(sf::Time frame_time);
	std::vector<std::shared_ptr<sf::Drawable>> getDrawables();
	void handleInput(sf::Time frame_time);
};

