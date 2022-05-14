#pragma once
#include <SFML/Graphics.hpp>
#include "Tilemap.h"

class Entity : public sf::Drawable
{
protected:
	sf::CircleShape baseshape;
	sf::Color color;
	sf::Vector2<float> vel;

public:
	virtual void tick(Tilemap tilemap);
	bool move(Tilemap tilemap);
	Entity();
	Entity(float posx, float posy, int colorr, int colorg, int colorb);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float distanceToLine(sf::Vector2f point, sf::Vector2f line_a, sf::Vector2f line_b);
};

