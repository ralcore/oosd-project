#include "Player.h"

// creates default white entity
Player::Player() : Entity(0, 0, 255, 255, 255)
{

}

// creates default white entity in given location
Player::Player(float posx, float posy) : Entity(posx, posy, 255, 255, 255)
{

}

void Player::tick(sf::Int32 frametime) 
{
	// handles all player-related logic

	// handling input
	handleInput(frametime);
	Entity::tick();
}

void Player::handleInput(sf::Int32 t)
{
	// based on time passed since last frame,
	// gets keyboard inputs and calculates v = u + at
	// to get the player's velocity on this frame

	// gather player movement inputs + corresponding acceleration values
	sf::Vector2<float> a(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		a.x += 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		a.x -= 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		// negative y is upwards in sfml
		a.y -= 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		a.y += 2;
	}

	// calculate new velocity values (suvat)
	vel.x = vel.x + t * a.x;
	vel.y = vel.y + t * a.y;

}