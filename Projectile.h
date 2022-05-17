#pragma once
#include "Player.h"
class Projectile : public Entity
{
private:
	float movespeed;
	bool fromenemy;
	sf::Vector2f raw_vel;
public:
	Projectile();
	Projectile(float posx, float posy, float angle);
	void tick(sf::Int32 frametime, Player& player, Tilemap& tilemap, std::vector<Projectile*>& projectiles);
	void draw(sf::RenderWindow& window);
	sf::Vector2f setAngle(float angle);
	bool collisionShield(Player& player);
	bool collisionEntity(Entity& entity);
	void kill(std::vector<Projectile*>& p);
};

