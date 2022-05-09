#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	Player(float posx, float posy);
	void tick(sf::Int32 frametime);
	void handleInput(sf::Int32 t);
};

