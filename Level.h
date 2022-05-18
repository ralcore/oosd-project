#pragma once
#include "Player.h"
#include "Tilemap.h"
#include "Projectile.h"
#include "Enemy.h"
#include <vector>
#include "Portal.h"

class Level
{
private:
	Player player;
	Tilemap tilemap;
	std::vector<Enemy*> enemies;
	std::vector<Projectile*> projectiles;
	Portal portal;
	
public:
	Level();
	Level(int levelnumber);
	void tick(sf::Int32 frametime, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
};

