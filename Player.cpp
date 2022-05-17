#include "Player.h"
#include <iostream>

// creates default white entity
Player::Player() : Entity(64, 64, 255, 255, 255, 16), shield(sf::Vector2f(32, 8)), health(3)
{
	shield.setFillColor(sf::Color(0, 255, 0));
	shield.setOrigin(sf::Vector2f(16, 32));
}

// creates default white entity in given location
Player::Player(float posx, float posy) : Entity(posx, posy, 255, 255, 255, 16), shield(sf::Vector2f(32, 8)), health(3)
{
	shield.setFillColor(sf::Color(0, 255, 0));
	shield.setOrigin(sf::Vector2f(16, 32));
}

void Player::tick(sf::Int32 frametime, Tilemap tilemap, sf::RenderWindow& window) 
{
	// handles all player-related logic
	
	// handling input
	handleInput(frametime);
	Entity::tick(tilemap);

	// handling shield
	shield.setPosition(baseshape.getPosition());
	// get mouse position relative to player
	sf::Vector2f m(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	sf::Vector2f m_relative = m - baseshape.getPosition();
	// get angle. y is first. don't ask me why
	float angle = atan2(m_relative.y, m_relative.x);
	angle *= 180 / (2*acos(0.0));
	angle += 90;
	shield.setRotation(angle);

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(baseshape);
	target.draw(shield);
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

	// calculate new velocity values (suvat)
	vel.x = vel.x + t * a.x;
	vel.y = vel.y + t * a.y;

}

float Player::getAngle()
{
	return shield.getRotation();
}

sf::Vector2f Player::getShieldOrigin()
{
	return shield.getOrigin();
}

void Player::hurt()
{
	health--;
}