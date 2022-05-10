#pragma once
#include "Player.h"

class Level
{
private:
	Player player;
	
public:
	Level();
	void tick(sf::Int32 frametime);
	void draw(sf::RenderWindow& window);
};

