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
	int levelnum;
	
public:
	Level();
	Level(int levelnumber);
	int tick(sf::Int32 frametime, sf::RenderWindow& window, Level* loadedlevel);
	void draw(sf::RenderWindow& window);
	void draw_text_levels(sf::RenderWindow& window);
};

