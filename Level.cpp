#include "Level.h"
#include "Tilemap.h"
#include <iostream>

Level::Level() : player(), tilemap()
{
	int tiles[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	tilemap.load("tiles.png", sf::Vector2u(32, 32), tiles, sizeof(tiles) / sizeof(*tiles), 24, 11);
	Projectile projectile(128, 128, 0);
	projectiles.push_back(new Projectile(projectile));
	Enemy enemy;
	enemies.push_back(enemy);
}

void Level::tick(sf::Int32 frametime, sf::RenderWindow& window)
{
	// player actions first
	player.tick(frametime, tilemap, window);

	for (auto &e: enemies)
	{
		e.tick(frametime);
	}

	for (auto& projectile : projectiles) {
		projectile->tick(frametime, player, tilemap, projectiles);
	}
}

void Level::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(tilemap);
	window.draw(player);
	for (auto& projectile : projectiles) {
		projectile->draw(window);
	}
	for (auto& e : enemies)
	{
		window.draw(e);
	}
	window.display();
}