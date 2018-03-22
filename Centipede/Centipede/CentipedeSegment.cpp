#include "stdafx.h"
#include "CentipedeSegment.h"
#include "CentipedeGame.h"
#include "Mushroom.h"


CentipedeSegment::CentipedeSegment(sf::RenderWindow * renderWindow, int x, int y) : GameObject(renderWindow, x,  y)
{
	pointValue = 10;
	isHead = true;
	health = 1;
	isPoisoned = false;

	setTexture("../Sprites/centipedeSegment.png");

	velocity = sf::Vector2i(rand() % 2 == 1 ? -1 : 1, 0);
}


CentipedeSegment::~CentipedeSegment()
{
}


void CentipedeSegment::update()
{
	static bool movedDown = false;
	if (CentipedeGame::clock % 8 == 0)
	{
		if (!movedDown)
		{

			if (CentipedeGame::isMushroomCell(currentPosition.x + velocity.x, currentPosition.y + velocity.y) || currentPosition.x == 0 || currentPosition.x == 29)
			{
				currentPosition.y++;
				movedDown = true;
			}
		}
		else
			movedDown = false;


		if (movedDown && !isPoisoned)
		{
			velocity.x *= -1;
			//movedDown = false;
		}
		else
		{
			//apply velocity
			currentPosition.x += velocity.x;
			currentPosition.y += velocity.y;
		}

			////if edge of screen 
		//if (!movedDown && currentPosition.x == 0 || currentPosition.x == 29)
		//{
		//	//flip velocity and move down a row
		//	currentPosition.y++;
		//	velocity.x *= -1;
		//}

		////test if can move
		//if (CentipedeGame::isMushroomCell(currentPosition.x + velocity.x, currentPosition.y + velocity.y))
		//{
		//	currentPosition.y++;
		//	movedDown = true;
		//}

		////apply velocity
		//currentPosition.x += velocity.x;
		//currentPosition.y += velocity.y;

		//if(velocity.y != 0 && currentPosition.y == 17)
		//	velocity = sf::Vector2i(rand() % 2 == 1 ? -1 : 1, 0);
	}

	if (isHead)
		setTexture("../Sprites/centipedeHead.png");
}


void CentipedeSegment::collideWith(GameObject * other)
{
	if (dynamic_cast<Bullet *>(other) != nullptr)
		health --;
}