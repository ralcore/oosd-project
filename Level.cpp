#include "Level.h"
#include "Tilemap.h"
#include <iostream>

Level::Level() : player(), tilemap()
{
	int tiles[] = { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 };
	tilemap.load("tiles.png", sf::Vector2u(32, 32), tiles, sizeof(tiles) / sizeof(*tiles), 4, 4);
}

void Level::tick(sf::Int32 frametime)
{
	// player actions first
	player.tick(frametime, tilemap);
}

void Level::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(tilemap);
	window.draw(player);
	window.display();
}