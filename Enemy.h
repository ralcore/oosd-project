#pragma once
#include "Entity.h"

class Enemy : public Entity
{
private:
	int randtime;
	int direction;
public:
	Enemy();
	Enemy(float posx, float posy);
	void tick(sf::Int32 frametime, Tilemap& tilemap);
	void runAI(sf::Int32 t, Tilemap& tilemap);
};