#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Level
{
private:
	Player player;
	std::vector<Enemy> enemies;
	
public:
	Level();
	void tick(sf::Int32 frametime);
	void draw(sf::RenderWindow& window);
};

