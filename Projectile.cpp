#include "Projectile.h"
#include <iostream>
// creates default white projectile
Projectile::Projectile() : Entity(64, 64, 255, 0, 0), movespeed(1), fromenemy(true)
{
	raw_vel = setAngle(0);
}

// creates default white entity in given location at given angle
Projectile::Projectile(float posx, float posy, float angle) : Entity(posx, posy, 255, 255, 255), movespeed(1), fromenemy(true)
{
	raw_vel = setAngle(angle);
}

void Projectile::tick(sf::Int32 frametime, Player& player, Tilemap& tilemap)
{
	// adjust vel for framerate
	vel = raw_vel * (float)frametime;

	// run move function
	if (Entity::move(tilemap)) {
		// if returns true (? check code) kill proj
	}

	// check for shield collision
	if (collisionShield(player)) {
		setAngle(player.getAngle());
		fromenemy = false;
	}

	// check for player collision
	// check for enemies collision (same code as player)
}

void Projectile::draw(sf::RenderWindow& window)
{
	window.draw(baseshape);
	window.draw(point);
}

sf::Vector2f Projectile::setAngle(float angle)
{
	baseshape.setRotation(angle);
	sf::Vector2f vel;
	// convert angle and movespeed to velocity vector
	vel.x = sin(baseshape.getRotation()) * movespeed;
	vel.y = cos(baseshape.getRotation()) * movespeed;
	return vel;
}

bool Projectile::collisionShield(Player& player)
{
	if (!fromenemy) {
		// cannot reflect own projectiles
		return false;
	}

	sf::Vector2f player_pos = player.getPosition();
	sf::Vector2f shield_orig = player.getShieldOrigin();
	// converting angle to radians
	float player_ang = player.getAngle() * 2.0 * acos(0.0) / 180.0;

	std::cout << player_ang;

	sf::Vector2f proj_pos = baseshape.getPosition();

	// normalise proj position
	sf::Vector2f proj_n;
	proj_n -= player_pos;
	proj_n.x = (proj_n.x * cos(player_ang) - proj_n.y * sin(player_ang));
	proj_n.y = (proj_n.x * sin(player_ang) + proj_n.y * cos(player_ang));

	point.setPosition(proj_n);
	point.setFillColor(sf::Color(0, 0, 255));
	point.setRadius(8);

	std::cout << "pos: " << proj_n.x << ", " << proj_n.y << std::endl;

	// shield hitbox is now (0,0) to (32, 8)
	if (proj_n.x >= 0 && proj_n.x <= 32 && proj_n.y >= 0 && proj_n.y <= 8) {
		return true;
	}
	else {
		return false;
	}
}