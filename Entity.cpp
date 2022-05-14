#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Entity::Entity() {
	vel.x = 0;
	vel.y = 0;
	sf::Color color(0, 0, 0);
	sf::CircleShape baseshape(96);
	baseshape.setRadius(16);
	baseshape.setOrigin(16, 16);
	baseshape.setFillColor(color);
	baseshape.setRotation(0);
}

Entity::Entity(float posx, float posy, int colorr, int colorg, int colorb) {
	vel.x = 0;
	vel.y = 0;
	sf::Color color(colorr, colorg, colorb);
	sf::CircleShape shape(96);
	baseshape.setRadius(16);
	baseshape.setFillColor(color);
	baseshape.setOrigin(16, 16);
	baseshape.setPosition(posx, posy);
	baseshape.setRotation(0);
}

bool Entity::move(Tilemap tilemap)
{
	// takes vel (set by child classes), checks for collisions
	// and applies new position.
	// returns 0 if collision found and movement should not be made.

	sf::Vector2 newpos = baseshape.getPosition() + vel;
	// TODO: check for collisions with wall, return 0 if collision found
	// else: apply movement changes and return 1

	// round to nearest 32
	sf::Vector2 index = newpos / 32.f;
	index.x = floor(index.x);
	index.y = floor(index.y);
	index *= 32.f;

	for (int i = -32; i <= 32; i += 32) {
		for (int j = -32; j <= 32; j += 32) {
			sf::Vector2f currtile(index.x + i, index.y + j);
			if (tilemap.getTile(currtile) == 1) {
				// tile needs checking - check if player has collided
				// left
				if (distanceToLine(newpos, currtile, sf::Vector2f(currtile.x, currtile.y + 32)) < 16) {
					std::cout << "left collision!!!!1" << std::endl;
					newpos.x = baseshape.getPosition().x;
					vel.x = 0;
				}
				// right
				if (distanceToLine(newpos, sf::Vector2f(currtile.x + 32, currtile.y), sf::Vector2f(currtile.x + 32, currtile.y + 32)) < 16) {
					std::cout << "right collision!!!!1" << std::endl;
					newpos.x = baseshape.getPosition().x;
					vel.x = 0;
				}
				// top
				if (distanceToLine(newpos, currtile, sf::Vector2f(currtile.x + 32, currtile.y)) < 16) {
					std::cout << "top collision!!!!1" << std::endl;
					newpos.y = baseshape.getPosition().y;
					vel.y = 0;
				}
				// bottom
				if (distanceToLine(newpos, sf::Vector2f(currtile.x, currtile.y + 32), sf::Vector2f(currtile.x + 32, currtile.y + 32)) < 16) {
					std::cout << "bottom collision!!!!1" << std::endl;
					newpos.y = baseshape.getPosition().y;
					vel.y = 0;
				}
			}
		}
	}

	baseshape.setPosition(newpos);
	return true;
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