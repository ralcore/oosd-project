#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Entity::Entity() {
	vel.x = 0;
	vel.y = 0;
	sf::Color color(0, 0, 0);
	baseshape.setRadius(16);
	baseshape.setOrigin(16, 16);
	baseshape.setFillColor(color);
	baseshape.setRotation(0);
}

Entity::Entity(float posx, float posy, int colorr, int colorg, int colorb, float radius) {
	vel.x = 0;
	vel.y = 0;
	sf::Color color(colorr, colorg, colorb);
	baseshape.setRadius(radius);
	baseshape.setFillColor(color);
	baseshape.setOrigin(radius, radius);
	baseshape.setPosition(posx, posy);
	baseshape.setRotation(0);
}

bool Entity::move(Tilemap tilemap)
{
	// takes vel (set by child classes), checks for collisions
	// and applies new position.
	// returns 1 if collision found and movement should not be made.

	sf::Vector2f newpos = baseshape.getPosition() + vel;

	// round to nearest 32
	sf::Vector2f index = newpos / 32.f;
	index.x = floor(index.x);
	index.y = floor(index.y);
	index *= 32.f;
	bool collided = false;

	if (tilemap.getTile(index) == 1) {
		// tile needs checking - check if player has collided
		// left
		if (distanceToLine(newpos, index, sf::Vector2f(index.x, index.y + 32)) < 16) {
			newpos.x = baseshape.getPosition().x;
			vel.x = -vel.x;
			collided = true;
		}
		// right
		if (distanceToLine(newpos, sf::Vector2f(index.x + 32, index.y), sf::Vector2f(index.x + 32, index.y + 32)) < 16) {
			newpos.x = baseshape.getPosition().x;
			vel.x = -vel.x;
			collided = true;
		}
		// top
		if (distanceToLine(newpos, index, sf::Vector2f(index.x + 32, index.y)) < 16) {
			newpos.y = baseshape.getPosition().y;
			vel.y = -vel.y;
			collided = true;
		}
		// bottom
		if (distanceToLine(newpos, sf::Vector2f(index.x, index.y + 32), sf::Vector2f(index.x + 32, index.y + 32)) < 16) {
			newpos.y = baseshape.getPosition().y;
			vel.y = -vel.y;
			collided = true;
		}
	}

	baseshape.setPosition(newpos);
	return collided;
}

void Entity::tick(Tilemap tilemap)
{
	move(tilemap);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(baseshape, states);
}

float Entity::distanceToLine(sf::Vector2f point, sf::Vector2f line_1, sf::Vector2f line_2) {
	// https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line#Line_defined_by_two_points
	float numerator = abs((line_2.x - line_1.x) * (line_1.y - point.y) - (line_1.x - point.x) * (line_2.y - line_1.y));
	float denominator = sqrt((line_2.x - line_1.x) * (line_2.x - line_1.x) + (line_2.y - line_1.y) * (line_2.y - line_1.y));
	return numerator / denominator;
}

sf::Vector2f Entity::getPosition() const {
	return baseshape.getPosition();
}

float Entity::getRadius() const {
	return baseshape.getRadius();
}