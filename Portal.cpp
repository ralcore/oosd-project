#include "Portal.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include <string>

Portal::Portal() {
	vel.x = 0;
	vel.y = 0;
	sf::Color color(0, 0, 0);
	baseshape.setRadius(16);
	baseshape.setOrigin(16, 16);
	baseshape.setFillColor(color);
	baseshape.setRotation(0);
}

Portal::Portal(float posx, float posy, int colorr, int colorg, int colorb, float radius) {
	vel.x = 0;
	vel.y = 0;
	sf::Color color(colorr, colorg, colorb);
	baseshape.setRadius(radius);
	baseshape.setFillColor(color);
	baseshape.setOrigin(radius, radius);
	baseshape.setPosition(posx, posy);
	baseshape.setRotation(0);
}

void Portal::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(baseshape, states);
}

void Portal::drawPortal()
{
	Portal::Portal(portalX, portalY, 0, 0, 255, 16);
}

void Portal::openPortal()
{
	Portal::drawPortal();
}