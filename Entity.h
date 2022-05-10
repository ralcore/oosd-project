#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
protected:
	sf::CircleShape baseshape;
	sf::Color color;
	sf::Vector2<float> vel;

public:
	virtual void tick();
	bool move();
	void die();
	Entity();
	Entity(float posx, float posy, int colorr, int colorg, int colorb);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

