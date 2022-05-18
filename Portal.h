#pragma once
#include <SFML/Graphics.hpp>
#include "Tilemap.h"
#include <string>

class Portal : public sf::Drawable
{
private:
	int portalX;
	int portalY;

protected:
	sf::CircleShape baseshape;
	sf::Color color;
	sf::Vector2<float> vel;

public:
	Portal();
	Portal(float posx, float posy, int colorr, int colorg, int colorb, float radius);
	void draw(sf::RenderWindow& window);
	void drawPortal();
	void openPortal();
};