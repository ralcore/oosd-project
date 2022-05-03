#include "Player.h"

// creates default white entity
Player::Player() : Entity(0, 0, 255, 255, 255)
{

}

// creates default white entity in given location
Player::Player(float posx, float posy) : Entity(posx, posy, 255, 255, 255)
{

}

void Player::tick(sf::Time frame_time) 
{
	// handling input
	handleInput(frame_time);
	Entity::tick();
}

void Player::handleInput(sf::Time frame_time)
{
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

	// getting time value
	float t = frame_time.asSeconds();

	// calculate new velocity values (suvat)
	vel.x = vel.x + t * a.x;
	vel.y = vel.y + t * a.y;

}

std::vector<std::shared_ptr<sf::Drawable>> Player::getDrawables()
{
	std::vector<std::shared_ptr<sf::Drawable>> drawables = Entity::getDrawables();
	return drawables;
}