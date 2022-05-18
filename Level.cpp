#include "Level.h"
#include "Tilemap.h"
#include <iostream>
#include <vector>
#include "Portal.h"

Level::Level() : player(300, 152), tilemap(), portal(), levelnum(1)
{
	int tiles[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	tilemap.load("tiles.png", sf::Vector2u(32, 32), tiles, sizeof(tiles) / sizeof(*tiles), 19, 19);
	Enemy enemy(288, 256);
	enemies.push_back(new Enemy(enemy));
}

Level::Level(int levelnumber) : player(300, 152), tilemap(), portal(), levelnum(levelnumber)
{
	// hacky fix to replace scrapped pointer-based level loading mechanism :[
	switch (levelnumber) {
	case 1:
	{
		int tiles[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
		tilemap.load("tiles.png", sf::Vector2u(32, 32), tiles, sizeof(tiles) / sizeof(*tiles), 19, 19);
		Enemy enemy(288, 256);
		enemies.push_back(new Enemy(enemy));
	}
		break;
	case 2:
	{
		int tiles[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
		tilemap.load("tiles.png", sf::Vector2u(32, 32), tiles, sizeof(tiles) / sizeof(*tiles), 19, 19);
		Enemy enemy(128, 256);
		enemies.push_back(new Enemy(enemy));
		Enemy enemy2(448, 256);
		enemies.push_back(new Enemy(enemy2));
		break;
	}
	case 3:
	{
		int tiles[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
		tilemap.load("tiles.png", sf::Vector2u(32, 32), tiles, sizeof(tiles) / sizeof(*tiles), 19, 19);
		Enemy enemy(128, 448);
		enemies.push_back(new Enemy(enemy));
		Enemy enemy2(448, 448);
		enemies.push_back(new Enemy(enemy2));
		Enemy enemy3(304, 448);
		enemies.push_back(new Enemy(enemy3));
		break;
	}
	case 4:
	{
		int tiles[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
		tilemap.load("tiles.png", sf::Vector2u(32, 32), tiles, sizeof(tiles) / sizeof(*tiles), 19, 19);
		Enemy enemy(128, 400);
		enemies.push_back(new Enemy(enemy));
		Enemy enemy2(128, 290);
		enemies.push_back(new Enemy(enemy2));
		Enemy enemy3(448, 400);
		enemies.push_back(new Enemy(enemy3));
		Enemy enemy4(448, 290);
		enemies.push_back(new Enemy(enemy4));
		break;
	}
	case 5:
	{
		int tiles[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
		tilemap.load("tiles.png", sf::Vector2u(32, 32), tiles, sizeof(tiles) / sizeof(*tiles), 19, 19);
		Enemy enemy(200, 500);
		enemies.push_back(new Enemy(enemy));
		Enemy enemy2(48, 290);
		enemies.push_back(new Enemy(enemy2));
		Enemy enemy3(408, 500);
		enemies.push_back(new Enemy(enemy3));
		Enemy enemy4(560, 290);
		enemies.push_back(new Enemy(enemy4));
		Enemy enemy5(304, 304);
		enemies.push_back(new Enemy(enemy5));
		break;
	}
	case 6:
		// game beaten. blank screen
		break;
	case 7:
		// player died. blank screen
		break;
	}
}

int Level::tick(sf::Int32 frametime, sf::RenderWindow& window, Level* loadedlevel)
{
	// returns true if level beaten

	// player actions first
	player.tick(frametime, tilemap, window);

	for (auto &e: enemies)
	{
		e->tick(frametime, tilemap, player, projectiles);
	}

	for (auto& projectile : projectiles) {
		projectile->tick(frametime, player, tilemap, projectiles, enemies);
	}

	//if no more enemies are in the vector and are therefore all dead, only then does it check to see if the player collides with the portal
	if (enemies.empty())
	{
		if (portal.collisionPortal(player)) {
			return 1;
		}
	}

	if (player.getHealth() == 0) {
		return 2;
	}

	return 0;
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
		e->draw(window);
	}

	//if all enemies are dead, display the portal
	if (enemies.empty())
	{
		window.draw(portal);
	}

	draw_text_levels(window);

	window.display();
}

void Level::draw_text_levels(sf::RenderWindow& window)
{
	// if the game is beaten, say so
	if (levelnum == 6)
	{
		sf::Font font;
		if (font.loadFromFile("Montserrat-Regular.ttf"))
		{
			sf::Text text;
			text.setFont(font);
			text.setString("game complete!");
			text.setCharacterSize(24);
			text.setFillColor(sf::Color(0, 255, 0));
			text.setPosition(200, 200);

			sf::Text text2;
			text2.setFont(font);
			text2.setString("thank you for playing.");
			text2.setCharacterSize(16);
			text2.setFillColor(sf::Color(100, 255, 100));
			text2.setPosition(214, 230);

			window.draw(text);
			window.draw(text2);
		}
		else {
			std::cout << "ERROR: font not found" << std::endl;
		}
	} 
	else if (levelnum == 7)
	{
		sf::Font font;
		if (font.loadFromFile("Montserrat-Regular.ttf"))
		{
			sf::Text text;
			text.setFont(font);
			text.setString("you died!");
			text.setCharacterSize(24);
			text.setFillColor(sf::Color(255, 0, 0));
			text.setPosition(250, 200);

			sf::Text text2;
			text2.setFont(font);
			text2.setString("try again.");
			text2.setCharacterSize(16);
			text2.setFillColor(sf::Color(255, 100, 100));
			text2.setPosition(266, 230);

			window.draw(text);
			window.draw(text2);
		}
		else {
			std::cout << "ERROR: font not found" << std::endl;
		}
	}
}