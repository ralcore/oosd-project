#include "Level.h"
#include "Tilemap.h"

Level::Level() : player()
{

}

void Level::tick(sf::Int32 frametime)
{
	// player actions first
	player.tick(frametime);
}

void Level::draw(sf::RenderWindow& window)
{
	Tilemap tilemap;
	int tiles[] = { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 };
	tilemap.load("tiles.png", sf::Vector2u(8, 8), tiles, 4, 4);
	window.clear();
	window.draw(player);
	window.draw(tilemap);
	window.display();
}