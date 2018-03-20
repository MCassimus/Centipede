#include "stdafx.h"
#include "Spider.h"


Spider::Spider(sf::RenderWindow * renderWindow, int x, int y, Player& p) : GameObject(renderWindow, x,  y)
{
	currentPosition.x = x;
	currentPosition.y = y;
	setTexture("spider.png");
	pointValue = 0;
	player = &p;
	scuttle = 0;
	velocity[0] = sf::Vector2i(0, -1);
	velocity[1] = sf::Vector2i(1, -1);
	velocity[2] = sf::Vector2i(1, 1);
	velocity[3] = sf::Vector2i(0, 1);
	velocity[4] = sf::Vector2i(-1, 1);
	velocity[5] = sf::Vector2i(-1, -1);
	if (x < 15)
		setVelocity(velocity[2]);
	else
		setVelocity(velocity[4]);
	count = 0;
}


static unsigned int frame = 0;
void Spider::update()
{
	setPointValue();
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

		if (getVelocity() == velocity[2])
		{
			lastDir = 0;
			count++;
			
			if (rand() % 6 == 1)
			{
				setVelocity(velocity[1]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				setVelocity(velocity[0]);
				count = 0;
			}

			if (count >= 5)
			{
				setVelocity(velocity[1]);
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
				setVelocity(velocity[1]);
			}
		}

		if (getVelocity() == velocity[1])
		{
			lastDir = 0;
			count++;

			if (rand() % 6 == 1)
			{
				setVelocity(velocity[2]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				setVelocity(velocity[3]);
				count = 0;
			}

			if (count >= 5)
			{
				setVelocity(velocity[2]);
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
				setVelocity(velocity[2]);
			}
		}
		
		if (getVelocity() == velocity[4])
		{
			lastDir = 1;
			count++;

			if (rand() % 6 == 1)
			{
				setVelocity(velocity[5]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				setVelocity(velocity[0]);
				count = 0;
			}

			if (count >= 5)
			{
				setVelocity(velocity[5]);
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
				setVelocity(velocity[5]);
			}
		}
		if (getVelocity() == velocity[5])
		{
			lastDir = 1;
			count++;

			if (rand() % 6 == 1)
			{
				setVelocity(velocity[4]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				setVelocity(velocity[3]);
				count = 0;
			}

			if (count >= 5)
			{
				setVelocity(velocity[4]);
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
				setVelocity(velocity[2]);
			}
		}
		if (getVelocity() == velocity[0])
		{
			count++;

			if (rand() % 6 == 1)
			{
				setVelocity(velocity[3]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				if(lastDir==0)
					setVelocity(velocity[2]);
				else
					setVelocity(velocity[4]);
				count = 0;
			}

			if (count >= 5)
			{
				if (lastDir == 0)
					setVelocity(velocity[2]);
				else
					setVelocity(velocity[4]);
				count = 0;
			}
		}
		if (getVelocity() == velocity[3])
		{
			count++;

			if (rand() % 6 == 1)
			{
				setVelocity(velocity[0]);
				count = 0;
			}
			else if (rand() % 6 == 1)
			{
				if (lastDir == 0)
					setVelocity(velocity[1]);
				else
					setVelocity(velocity[5]);
				count = 0;
			}

			if (count >= 5)
			{
				if (lastDir == 0)
					setVelocity(velocity[1]);
				else
					setVelocity(velocity[5]);
				count = 0;
			}
		}

		frame = 0;
	}
	return;
}


void Spider::setPointValue()
{
	if (distanceFromPlayer > 4) //if more than 4 levels away
		pointValue = 900;
	else if (distanceFromPlayer < 4 || distanceFromPlayer == 4) //no more than 4 levels
		pointValue = 600;
	else if (distanceFromPlayer == 1) //no more than 1 level away 
		pointValue = 300;

	return;
}


void Spider::findDistancePlayer()
{
	if(((player->getPosition().x <= currentPosition.x + 1)&&(player->getPosition().x >= currentPosition.x -1)))
		if (((player->getPosition().y <= currentPosition.y + 1) && (player->getPosition().y >= currentPosition.y - 1)))
		{
			pointValue = 300;
			return;
		}
	
	else if (((player->getPosition().x <= currentPosition.x + 4) && (player->getPosition().x >= currentPosition.x - 4)))
		if (((player->getPosition().y <= currentPosition.y + 4) && (player->getPosition().y >= currentPosition.y - 4)))
		{
			pointValue = 600;
			return;
		}
		
	else
	{
		pointValue = 900;
		return;
	}
}


void Spider::colideWith(GameObject* other)
{
	if (dynamic_cast<Bullet*>(other) != nullptr)
		health = 0;
	else if (dynamic_cast<Player*>(other) != nullptr)
		health = 0;
	return;
}


Spider::~Spider()
{
}