#pragma once
#include "Player.h"
#include "Tilemap.h"
#include "Projectile.h"

class Level
{
private:
	Player player;
	Tilemap tilemap;
	std::vector<Projectile> projectiles;
	
public:
	Level();
	void tick(sf::Int32 frametime, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
};

