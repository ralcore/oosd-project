#include "Level.h"

Level::Level() : player()
{
	Enemy enemy;
	enemies.push_back(enemy);
}


void Level::tick(sf::Int32 frametime)
{
	// player actions first
	player.tick(frametime);

	//ticks through the vector of enemies
	for (auto &e: enemies)
	{
		e.tick(frametime);
	
	}


}

void Level::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(player);
	for (auto& e : enemies)
	{
		window.draw(e);
	}
	window.display();
}