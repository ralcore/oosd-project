#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Entity::Entity() {
	vel.x = 0;
	vel.y = 0;
	sf::Color color(0, 0, 0);
	baseshape.setRadius(16);
	baseshape.setFillColor(color);
	baseshape.setPosition(0, 0);
	baseshape.setRotation(0);
}

Entity::Entity(float posx, float posy, int colorr, int colorg, int colorb) {
	vel.x = 0;
	vel.y = 0;
	sf::Color color(colorr, colorg, colorb);
	baseshape.setRadius(16);
	baseshape.setFillColor(color);
	baseshape.setPosition(posx, posy);
	baseshape.setRotation(0);
}

bool Entity::move()
{
	// takes vel (set by child classes), checks for collisions
	// and applies new position.
	// returns 0 if collision found and movement should not be made.

	sf::Vector2 newpos = baseshape.getPosition() + vel;
	// TODO: check for collisions with wall, return 0 if collision found
	// else: apply movement changes and return 1
	baseshape.setPosition(newpos);
	return true;
}

void Entity::tick()
{
	move();
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(baseshape, states);
}