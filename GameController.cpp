#include "GameController.h"

GameController::GameController() : player()
{

}

void GameController::gameTick(sf::Time frame_time)
{
	// player actions first
	player.tick(frame_time);
}

std::vector<std::shared_ptr<sf::Drawable>> GameController::getDrawables()
{
	// returns a vector of objects to draw to the screen
	return player.getDrawables();
}