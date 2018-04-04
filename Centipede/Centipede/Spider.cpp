#include "stdafx.h"
#include "Spider.h"


Spider::Spider(sf::RenderWindow * renderWindow, int x, int y, Player& p) : GameObject(renderWindow, x,  y)
{
	currentPosition.x = x;
	currentPosition.y = y;
	object.setOrigin(0, -4);
	setTexture("../Sprites/Spider/spider0.png");
	pointValue = 0;
	player = &p;
	scuttle = 0;
	velocities[0] = sf::Vector2i(0, -1);
	velocities[1] = sf::Vector2i(1, -1);
	velocities[2] = sf::Vector2i(1, 1);
	velocities[3] = sf::Vector2i(0, 1);
	velocities[4] = sf::Vector2i(-1, 1);
	velocities[5] = sf::Vector2i(-1, -1);
	if (x < 15)
		setVelocity(velocities[2]);
	else
		setVelocity(velocities[4]);
	count = 0;
}


static unsigned int frame = 0;
void Spider::update()
{
	setPointValue();
	std::cout << pointValue<<"\n";
	if (frame++ == frameMax)
	{
		if (scuttle++ >= 4)
			scuttle = 0;

		if (scuttle == 0)
			setTexture("../Sprites/Spider/Spider0.png");
		else if (scuttle == 1)
			setTexture("../Sprites/Spider/Spider1.png");
		else if (scuttle == 2)
			setTexture("../Sprites/Spider/Spider2.png");
		else if(scuttle ==3)
			setTexture("../Sprites/Spider/Spider3.png");
		else
			setTexture("../Sprites/Spider/Spider3.png");

		#pragma region toomuch
		if (getVelocity() == velocities[2])
		{
			lastDir = 0;
			count++;
			
			if (rand() % 6 == 1)
			{
				setVelocity(velocities[1]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				setVelocity(velocities[0]);
				count = 0;
			}

			if (count >= 5)
			{
				setVelocity(velocities[1]);
				count = 0;
			}

			if (currentPosition.x > 30)//bouderys
			{
				pointValue = 0;
				health = 0;
			}
			else if (currentPosition.y > 30)
			{
				count = 0;
				setVelocity(velocities[1]);
			}
		}

		if (getVelocity() == velocities[1])
		{
			lastDir = 0;
			count++;

			if (rand() % 6 == 1)
			{
				setVelocity(velocities[2]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				setVelocity(velocities[3]);
				count = 0;
			}

			if (count >= 5)
			{
				setVelocity(velocities[2]);
				count = 0;
			}
			if (currentPosition.x > 30)//bouderys
			{
				pointValue = 0;
				health = 0;
			}
			else if (currentPosition.y < 17)
			{
				count = 0;
				setVelocity(velocities[2]);
			}
		}
		
		if (getVelocity() == velocities[4])
		{
			lastDir = 1;
			count++;

			if (rand() % 6 == 1)
			{
				setVelocity(velocities[5]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				setVelocity(velocities[0]);
				count = 0;
			}

			if (count >= 5)
			{
				setVelocity(velocities[5]);
				count = 0;
			}
			
			if (currentPosition.x < 0)//bouderys
			{
				pointValue = 0;
				health = 0;
			}
			else if (currentPosition.y > 30)
			{
				count = 0;
				setVelocity(velocities[5]);
			}
		}

		if (getVelocity() == velocities[5])
		{
			lastDir = 1;
			count++;

			if (rand() % 6 == 1)
			{
				setVelocity(velocities[4]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				setVelocity(velocities[3]);
				count = 0;
			}

			if (count >= 5)
			{
				setVelocity(velocities[4]);
				count = 0;
			}
			if (currentPosition.x < 0)//bouderys
			{
				pointValue = 0;
				health = 0;
			}
			else if (currentPosition.y < 17)
			{
				count = 0;
				setVelocity(velocities[2]);
			}
		}

		if (getVelocity() == velocities[0])
		{
			count++;

			if (rand() % 6 == 1)
			{
				setVelocity(velocities[3]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				if(lastDir==0)
					setVelocity(velocities[2]);
				else
					setVelocity(velocities[4]);
				count = 0;
			}

			if (count >= 5)
			{
				if (lastDir == 0)
					setVelocity(velocities[2]);
				else
					setVelocity(velocities[4]);
				count = 0;
			}
		}

		if (getVelocity() == velocities[3])
		{
			count++;

			if (rand() % 6 == 1)
			{
				setVelocity(velocities[0]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				if (lastDir == 0)
					setVelocity(velocities[1]);
				else
					setVelocity(velocities[5]);
				count = 0;
			}

			if (count >= 5)
			{
				if (lastDir == 0)
					setVelocity(velocities[1]);
				else
					setVelocity(velocities[5]);
				count = 0;
			}
		}
		#pragma endregion

		currentPosition.x += velocity.x;
		currentPosition.y += velocity.y;

		frame = 0;
	}
}


void Spider::setPointValue()
{
	if(((player->getPosition().x <= currentPosition.x + 1)&&(player->getPosition().x >= currentPosition.x -1)))
		if (((player->getPosition().y <= currentPosition.y + 1) && (player->getPosition().y >= currentPosition.y - 1)))
		{
			std::cout << "three hundo \n";
			pointValue = 300;
			return;
		}
	
	else if (((player->getPosition().x <= currentPosition.x + 4) && (player->getPosition().x >= currentPosition.x - 4)))
		if (((player->getPosition().y <= currentPosition.y + 4) && (player->getPosition().y >= currentPosition.y - 4)))
		{
			std::cout << "six hundo \n";
			pointValue = 600;
			return;
		}
		
	else
	{
		std::cout << "nine hundo \n";
		pointValue = 900;
		return;
	}
}


void Spider::collideWith(GameObject* other)
{
	if (dynamic_cast<Bullet*>(other) != nullptr)
		health = 0;
	else if (dynamic_cast<Player*>(other) != nullptr)
		health = 0;
}


Spider::~Spider()
{
}