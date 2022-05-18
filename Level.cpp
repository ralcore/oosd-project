#include "Level.h"
#include "Tilemap.h"
#include <iostream>
#include <vector>
#include "Portal.h"
#include "GUI.h"

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

	Portal portal();

	GUI gui();
}

void Level::tick(sf::Int32 frametime, sf::RenderWindow& window)
{
	// player actions first
	player.tick(frametime, tilemap, window);

	for (auto &e: enemies)
	{
		e.tick(frametime, tilemap);
	}

	for (auto& projectile : projectiles) {
		projectile->tick(frametime, player, tilemap, projectiles);
	}

	//if no more enemies are in the vector and are therefore all dead, only then does it check to see if the player collides with the portal
	if (enemies.empty())
	{
		portal.collisionPortal(player);
	}

	//gui.displayStats(player);
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

	//if all enemies are dead, display the portal
	if (enemies.empty())
	{
		window.draw(portal);
	}
	window.display();
}