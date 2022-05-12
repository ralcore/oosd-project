#include "Player.h"
#include <iostream>

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
	const float ACC = 0.015;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		a.x -= ACC;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		a.x += ACC;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		// negative y is upwards in sfml
		a.y -= ACC;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		a.y += ACC;
	}
	
	// prevent player being faster on diagonal
	// magic number is pythag:
	// triangle with sides 1, 1 will have diagonal of sqrt(2)
	// divide sides by sqrt(2) to normalise diagonal to 1
	if (a.x != 0 && a.y != 0) {
		a /= (float)sqrt(2);
	}

	// applying friction values
	const float FRIC = 0.015;
	a.x += (0 - vel.x * FRIC);
	a.y += (0 - vel.y * FRIC);

	std::cout << std::to_string(vel.x) + "\n";

	// calculate new velocity values (suvat)
	vel.x = vel.x + t * a.x;
	vel.y = vel.y + t * a.y;

}