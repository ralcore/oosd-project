#include "Enemy.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

// creates default red entity
Enemy::Enemy() : Entity(50, 50, 255, 0, 0, 16), randtime(0), direction(0)
{
	//creates a random seed
	srand((unsigned)time(NULL));
}

// creates default red entity in given location
Enemy::Enemy(float posx, float posy) : Entity(posx, posy, 255, 0, 0, 16), randtime(0), direction(0)
{
	srand((unsigned)time(NULL));
}

//calls the runAI function every frame
void Enemy::tick(sf::Int32 frametime, Tilemap& tilemap)
{
	runAI(frametime, tilemap);
}

void Enemy::runAI(sf::Int32 t, Tilemap& tilemap)
{
	//calls the move function from the Entity class
	Entity::move(tilemap);

	//if the amount of time the enemy should move for is zero or the enemy has hit a wall, pick a random time and a random direction
	if (randtime == 0 or Entity::move(tilemap) == 1)
	{
		randtime = rand() % 1000;

		direction = rand() % 4;
	}

	std::cout << std::to_string(randtime) + " " + std::to_string(direction) + " ";

	//getting the enemies current position and setting the acceleration
	sf::Vector2<float> a(0, 0);
	const float ACC = 0.015;


	//if the enemys movement time is above zero it will move in the appropriate direction
	if (randtime != 0)
	{
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

		//calculating enemy friction
		const float FRIC = 0.030;
		a.x += (0 - vel.x * FRIC);
		a.y += (0 - vel.y * FRIC);

		//calculating enemy velocity
		vel.x = vel.x + t * a.x;
		vel.y = vel.y + t * a.y;

		//decreasing the movement time by 1 every frame
		randtime--;

	}
}