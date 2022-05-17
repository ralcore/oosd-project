#include "Enemy.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

// creates default red entity
Enemy::Enemy() : Entity(50, 50, 255, 0, 0), randtime(0), direction(0)
{
	srand((unsigned)time(NULL));
}

// creates default red entity in given location
Enemy::Enemy(float posx, float posy) : Entity(posx, posy, 255, 0, 0), randtime(0), direction(0)
{
	srand((unsigned)time(NULL));
}

void Enemy::tick(sf::Int32 frametime)
{
	runAI(frametime);
}

void Enemy::runAI(sf::Int32 t)
{
	//calls the move function in the Entity class
	Entity::move();

	//when the amount of time the enemy moves in one direction for is up or the enemy collides with a wall, a new rand time the enemy moves for and 
	//a new random direction will be created

	if (randtime == 0 or Entity::move() == 1)
	{
		randtime = rand() % 1000;

		direction = rand() % 4;
	}

	//sets the enemies current coordinares to a and sets the acceleration value to a constant
	sf::Vector2<float> a(0, 0);
	const float ACC = 0.015;


	//loop executes every time the enemy's movement time is not zero
	if (randtime != 0)
	{
		//moves the enemy's coordinates in the appropriate direction every frame depending on the value of the direction variable
		switch (direction)
		{
			case 0:
				a.x -= ACC;
				break;

			case 1:
				a.x += ACC;
				break;

			case 2:
				a.y -= ACC;
				break;

			case 3:
				a.y += ACC;
				break;
		}

		//calculates enemy friction
		const float FRIC = 0.015;
		a.x += (0 - vel.x * FRIC);
		a.y += (0 - vel.y * FRIC);


		//calculates enemy velocity
		vel.x = vel.x + t * a.x;
		vel.y = vel.y + t * a.y;

		//decrements the time the enemy should move in that direction
		randtime--;

	}
}