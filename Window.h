#pragma once
#include "Level.h"
#include <SFML/Graphics.hpp>

class Window
{
private:
	sf::Clock frametimer;
	sf::Int32 frametime;
	sf::RenderWindow window;
	Level level;
	// TODO: menucontroller
	int state;

public:
	Window();
	void windowLoop();
	Level loadLevel(int levelnum);
};

