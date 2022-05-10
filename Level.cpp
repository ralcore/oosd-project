#include "Level.h"

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
	window.clear();
	window.draw(player);
	window.display();
}