#pragma once
#include "Player.h"

class GameController
{
private:
	Player player;
	
public:
	GameController();
	void gameTick(sf::Time frame_time);
	std::vector<std::shared_ptr<sf::Drawable>> getDrawables();
};

