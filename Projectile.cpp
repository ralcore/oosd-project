#include "Projectile.h"
// creates default white projectile
Projectile::Projectile() : Entity(64, 64, 255, 0, 0), movespeed(2)
{
	vel = initVel();
}

// creates default white entity in given location at given angle
Projectile::Projectile(float posx, float posy, float angle) : Entity(posx, posy, 255, 255, 255), movespeed(2)
{
	baseshape.setRotation(angle);
	vel = initVel();
}

void Projectile::tick(sf::Int32 frametime, Player& player, Tilemap& tilemap)
{
	// run move function
	if (Entity::move(tilemap)) {
		// if returns false (? check code) kill proj
	}
	// check for shield collision
	// check for player collision
	// check for enemies collision (same code as player)
}

void Projectile::draw(sf::RenderWindow& window)
{
	window.draw(baseshape);
}

sf::Vector2f Projectile::initVel()
{
	sf::Vector2f vel;
	// convert angle and movespeed to velocity vector
	vel.x = sin(baseshape.getRotation()) * movespeed;
	vel.y = cos(baseshape.getRotation()) * movespeed;
	return vel;
}