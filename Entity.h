#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
protected:
	sf::CircleShape shape;
	sf::Color color;
	sf::Vector2<float> vel;

public:
	virtual void tick();
	virtual std::vector<std::shared_ptr<sf::Drawable>> getDrawables();
	void move();
	void die();
	void shoot();
	Entity();
	Entity(float posx, float posy, int colorr, int colorg, int colorb);
};

