#pragma once
#include "Entity.h"

class Player : public Entity
{
private:
	sf::RectangleShape shield;
	int health;

public:
	Player();
	Player(float posx, float posy);
	void tick(sf::Int32 frametime, Tilemap tilemap, sf::RenderWindow& window);
	void handleInput(sf::Int32 t);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float getAngle();
	sf::Vector2f getShieldOrigin();
	void hurt();
};

