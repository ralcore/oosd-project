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
	Entity::move();

	if (randtime == 0 or Entity::move() == 0)
	{
		randtime = rand() % 1000;

		direction = rand() % 4;
	}

	std::cout << std::to_string(randtime) + " " + std::to_string(direction) + " ";

	sf::Vector2<float> a(0, 0);
	const float ACC = 0.015;



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

		const float FRIC = 0.015;
		a.x += (0 - vel.x * FRIC);
		a.y += (0 - vel.y * FRIC);

		vel.x = vel.x + t * a.x;
		vel.y = vel.y + t * a.y;

		randtime--;

	}
}