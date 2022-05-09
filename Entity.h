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
	bool move();
	void die();
	Entity();
	Entity(float posx, float posy, int colorr, int colorg, int colorb);
};

