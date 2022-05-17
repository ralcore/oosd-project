#include "Projectile.h"
#include <iostream>
// creates default white projectile
Projectile::Projectile() : Entity(64, 64, 255, 0, 0, 4), movespeed(0.01), fromenemy(true)
{
	raw_vel = setAngle(0);
}

// creates default white entity in given location at given angle
Projectile::Projectile(float posx, float posy, float angle) : Entity(posx, posy, 255, 255, 255, 4), movespeed(0.01), fromenemy(true)
{
	raw_vel = setAngle(angle);
}

void Projectile::tick(sf::Int32 frametime, Player& player, Tilemap& tilemap, std::vector<Projectile*>& projectiles)
{
	// adjust vel for framerate
	vel = raw_vel * (float)frametime;

	// run move function, if collided with wall kill
	if (Entity::move(tilemap)) {
		kill(projectiles);
		return;
	}

	// check for shield collision
	if (collisionShield(player)) {
		raw_vel = setAngle(player.getAngle());
		fromenemy = false;
	}

	// check for player collision
	if (collisionEntity(player)) {
		// hurt player
		player.hurt();
		kill(projectiles);
		return;
	}
	// check for enemies collision (same code as player)
}

void Projectile::draw(sf::RenderWindow& window)
{
	window.draw(baseshape);
}

sf::Vector2f Projectile::setAngle(float angle)
{
	baseshape.setRotation(angle);
	sf::Vector2f vel;
	const float pi = 3.14159;
	// convert angle and movespeed to velocity vector
	vel.x = sin(baseshape.getRotation() * pi/180) * movespeed;
	vel.y = 0 - cos(baseshape.getRotation() * pi/180) * movespeed;
	return vel;
}

bool Projectile::collisionShield(Player& player)
{
	// calculates collisions with the player's shield using a radius distance check + arc

	if (!fromenemy) {
		// cannot reflect own projectiles
		return false;
	}

	sf::Vector2f player_pos(player.getPosition());
	sf::Vector2f proj_pos(baseshape.getPosition());
	float shield_distance(player.getShieldOrigin().y);
	float player_angle(player.getAngle());
	const float pi(3.14159);
	const int shield_range(32);

	// calculate position of centre of shield
	sf::Vector2f shield_pos;
	shield_pos.x = player_pos.x + shield_distance * cos((player_angle - 90) * pi/180);
	shield_pos.y = player_pos.y + shield_distance * sin((player_angle - 90) * pi/180);

	// calculate distance
	sf::Vector2f diff_pos(shield_pos - proj_pos);
	float distance(sqrt(pow(diff_pos.x, 2.f) + pow(diff_pos.y, 2.f)));

	if (distance >= shield_range) {
		return false;
	}

	return true;
}

bool Projectile::collisionEntity(Entity& entity) {

	// checks entity for collision with projectile using radius
	sf::Vector2f ent_pos(entity.getPosition());
	sf::Vector2f proj_pos(baseshape.getPosition());
	sf::Vector2f diff_pos(ent_pos - proj_pos);
	float distance(sqrt(pow(diff_pos.x, 2.f) + pow(diff_pos.y, 2.f)));

	return (distance < entity.getRadius() + baseshape.getRadius()) ? true : false;

}

void Projectile::kill(std::vector<Projectile*>& p) {
	// remove pointer from vec
	p.erase(std::remove(p.begin(), p.end(), this), p.end());
	// destroy self
	delete this;
	return;
}