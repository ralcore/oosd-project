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

void Entity::move()
{
	// TODO: check for collisions with wall
	// apply movement
	shape.setPosition(shape.getPosition().x + vel.x, shape.getPosition().y + vel.y);
	std::cout << std::to_string(shape.getPosition().x) + "\n";
	std::cout << std::to_string(shape.getPosition().y) + "\n";
}

void Entity::tick()
{
	move();
}

std::vector<std::shared_ptr<sf::Drawable>> Entity::getDrawables()
{
	std::vector<std::shared_ptr<sf::Drawable>> drawables;
	auto ptr = std::make_shared<sf::CircleShape>(shape);
	drawables.push_back(ptr);
	return drawables;
}