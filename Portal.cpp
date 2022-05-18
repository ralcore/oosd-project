#include "Portal.h"
#include "iostream"
#include <SFML/Graphics.hpp>

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

bool Portal::collisionPortal(Player& player) {

	// checks player for collision with portal using radius

	portalX = 304;
	portalY = 304;

	sf::Vector2f player_pos(player.getPosition());
	sf::Vector2f portal_pos(portalX, portalY);
	sf::Vector2f diff_pos(player_pos - portal_pos);
	float distance(sqrt(pow(diff_pos.x, 2.f) + pow(diff_pos.y, 2.f)));

	return (distance < 64 + baseshape.getRadius()) ? true : false;

}

