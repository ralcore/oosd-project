#pragma once
#include "Entity.h"
#include "Player.h"

class Projectile;

class Enemy : public Entity
{
private:
	int randtime;
	int shoottime;
	int direction;
public:
	Enemy();
	Enemy(float posx, float posy);
	void tick(sf::Int32 frametime, Tilemap& tilemap, Player& player, std::vector<Projectile*>& projectiles);
	void runAI(sf::Int32 t, Tilemap& tilemap);
	void kill(std::vector<Enemy*>& enemies);
	void draw(sf::RenderWindow& window);
	void shoot(Player& player, std::vector<Projectile*>& projectiles);
};