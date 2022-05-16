#pragma once
#include "Player.h"
class Projectile : public Entity
{
private:
	bool fromenemy;
	int movespeed;
	sf::Vector2f raw_vel;
	sf::CircleShape point;
public:
	Projectile();
	Projectile(float posx, float posy, float angle);
	void tick(sf::Int32 frametime, Player& player, Tilemap& tilemap);
	void draw(sf::RenderWindow& window);
	sf::Vector2f setAngle(float angle);
	bool collisionShield(Player& player);
};

