#pragma once
#include "Player.h"
#include "Tilemap.h"

class Level
{
private:
	Player player;
	Tilemap tilemap;
	
public:
	Level();
	void tick(sf::Int32 frametime);
	void draw(sf::RenderWindow& window);
};

