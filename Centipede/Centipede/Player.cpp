#include "stdafx.h"
#include "Player.h"
#include "CentipedeGame.h"
#include "CentipedeSegment.h"
#include "Scorpion.h"
#include "Spider.h"

Player::Player(int x, int y) : GameObject (x, y)
{
	setTexture("../Sprites/player.png");
	health = 3;
}


void Player::update(CentipedeGame *gameHandle)
{
<<<<<<< HEAD

	/*
	//setVelocity(sf::Vector2i(getNearestCellPos(getRelMousePos()).x - currentPosition.x, getNearestCellPos(getRelMousePos()).y-currentPosition.y));

	
=======
	setVelocity(sf::Vector2i(getNearestCellPos(getRelMousePos()).x - currentPosition.x, getNearestCellPos(getRelMousePos()).y-currentPosition.y));
	if (!obstructed(1))
		currentPosition.x = currentPosition.x + velocity.x;
	if (!obstructed(0))
		currentPosition.y = currentPosition.y + velocity.y;
>>>>>>> 0f3f565c4479e80a7642366667bba3130106bca0



	//currentPosition = getNearestCellPos(getRelMousePos());
	currentPosition /= static_cast<int>(interval.x);
	

	if ((30 - currentPosition.y) > 12)
		currentPosition.y = 30-12;
	if (currentPosition.y > 29)
		currentPosition.y = 29;
	if (currentPosition.x < 0)
		currentPosition.x = 0;
	if (currentPosition.x > 29)
		currentPosition.x = 29;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !Bullet::liveBullet)
	{
		CentipedeGame::spawnObject<Bullet>(currentPosition.x, currentPosition.y);
	}

	object.setPosition(static_cast<sf::Vector2f>(currentPosition*static_cast<int>(interval.x)));
	
	*/
}


char* Player::getType() {
	return "Player";
}

void Player::collideWith(GameObject * other)
{
	if (dynamic_cast<CentipedeSegment *>(other) != nullptr)
		health--;
	else if (dynamic_cast<Flea *>(other) != nullptr)
		health--;
	else if (dynamic_cast<Scorpion *>(other) != nullptr)
		health--;
	else if (dynamic_cast<Spider *>(other) != nullptr)
		health--;

	//play a death anim here
}


bool Player::obstructed(bool isX)
{
	int directionX;
	if (velocity.x + velocity.x >= velocity.x + 1)
		directionX = 1;
	else
		directionX = -1;

	int directionY;
	if (velocity.y + velocity.y >= velocity.y + 1)
		directionY = 1;
	else
		directionY = -1;
	
	if (isX)
		if (CentipedeGame::isMushroomCell(currentPosition.x + directionX, currentPosition.y)
			&& currentPosition.x + directionX >= 0 && currentPosition.x + directionX <= 29 && currentPosition.y >= 0 && currentPosition.y <= 29)
			return true;
		else
			return false;
	else
		if (CentipedeGame::isMushroomCell(currentPosition.x , currentPosition.y + directionY)
			&& currentPosition.x >= 0 && currentPosition.x <= 29 && currentPosition.y + directionY >= 0 && currentPosition.y + directionY <= 29)
			return true;
		else
			return false;
}