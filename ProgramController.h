#pragma once
#include "GameController.h"
#include <SFML/Graphics.hpp>

class ProgramController
{
private:
	sf::Clock frame_timer;
	sf::Time frame_time;
	sf::RenderWindow window;
	GameController game_controller;
	// TODO: menucontroller
	int state;

public:
	ProgramController();
	sf::Time getFrameTime();
	int getState();
	void setState(int new_state);
	void gameLoop();
};

