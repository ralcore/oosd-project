#include "Enemy.h"
#include "Projectile.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

// creates default red entity
Enemy::Enemy() : Entity(50, 50, 255, 0, 0, 16), randtime(0), direction(0), shoottime(500)
{
	srand((unsigned)time(NULL));
}

// creates default red entity in given location
Enemy::Enemy(float posx, float posy) : Entity(posx, posy, 255, 0, 0, 16), randtime(0), direction(0), shoottime(500)
{
	srand((unsigned)time(NULL));
}

void Enemy::tick(sf::Int32 frametime, Tilemap& tilemap, Player& player, std::vector<Projectile*>& projectiles)
{
	runAI(frametime, tilemap);

	if (shoottime <= 0) {
		shoot(player, projectiles);
	}
	else {
		shoottime--;
	}

	std::cout << "shoottime: " << shoottime << std::endl;
}

void Enemy::runAI(sf::Int32 t, Tilemap& tilemap)
{
	Entity::move(tilemap);

	if (randtime == 0)
	{
		randtime = rand() % 1000;

		direction = rand() % 4;
	}

	if (Entity::move(tilemap) == 1)
	{
		if (direction % 2 == 0) {
			direction += 1;
		}
		else {
			direction -= 1;
		}
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

		const float FRIC = 0.030;
		a.x += (0 - vel.x * FRIC);
		a.y += (0 - vel.y * FRIC);

		vel.x = vel.x + t * a.x;
		vel.y = vel.y + t * a.y;

		randtime--;

	}
}

void Enemy::kill(std::vector<Enemy*>& e)
{
	// remove pointer from vec
	e.erase(std::remove(e.begin(), e.end(), this), e.end());
	// destroy self
	delete this;
	return;
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(baseshape);
}

void Enemy::shoot(Player& player, std::vector<Projectile*>& projectiles)
{

	const float pi(3.14159);
	// get player position relative to enemy position
	sf::Vector2f p_pos = player.getPosition();
	p_pos -= baseshape.getPosition();
	// account for inverted y axis
	p_pos.y = 0 - p_pos.y;

	// get angle to p_pos
	float ang = atan2f(p_pos.x, p_pos.y) / (pi/180);
	// account for atan2 returning relative to x axis, not y

	// create projectile at position
	Projectile projectile(baseshape.getPosition().x, baseshape.getPosition().y, ang);
	projectiles.push_back(new Projectile(projectile));
	shoottime = 500;
}