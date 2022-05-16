#pragma once
#include "Player.h"
class Projectile : public Entity
{
private:
	int movespeed;
public:
	Projectile();
	Projectile(float posx, float posy, float angle);
	void tick(sf::Int32 frametime, Player& player, Tilemap& tilemap);
	void draw(sf::RenderWindow& window);
	sf::Vector2f initVel();
};

