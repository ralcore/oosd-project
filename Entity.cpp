#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Entity::Entity() {
	vel.x = 0;
	vel.y = 0;
	sf::Color color(0, 0, 0);
	sf::CircleShape shape(100);
	shape.setRadius(16);
	shape.setFillColor(color);
	shape.setPosition(0, 0);
	shape.setRotation(0);
}

Entity::Entity(float posx, float posy, int colorr, int colorg, int colorb) {
	vel.x = 0;
	vel.y = 0;
	sf::Color color(colorr, colorg, colorb);
	sf::CircleShape shape(100);
	shape.setRadius(16);
	shape.setFillColor(color);
	shape.setPosition(posx, posy);
	shape.setRotation(0);
}

bool Entity::move()
{
	// takes vel (set by child classes), checks for collisions
	// and applies new position.
	// returns 0 if collision found and movement should not be made.

	sf::Vector2 newpos = shape.getPosition() + vel;
	// TODO: check for collisions with wall, return 0 if collision found
	// else: apply movement changes and return 1
	shape.setPosition(newpos);
	return true;
}

void Entity::tick()
{
	move();
}