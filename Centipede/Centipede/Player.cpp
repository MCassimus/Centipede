#include "stdafx.h"
#include "Player.h"
#include "CentipedeGame.h"
#include "CentipedeSegment.h"
#include "Scorpion.h"
#include "Spider.h"

Player::Player(int x, int y) : GameObject(x, y)
{
	setTexture("../Sprites/player.png");
	health = 3;
}


void Player::update(CentipedeGame *gameHandle)
{
	/*setVelocity(sf::Vector2i(getNearestCellPos(getRelMousePos()).x - currentPosition.x, getNearestCellPos(getRelMousePos()).y-currentPosition.y));

	currentPosition = getNearestCellPos(gameHandle->getRelMousePos());
	currentPosition /= static_cast<int>(interval.x);
	if (!mushroom in way)
	goto mouse
	else
	 go untill hit mushroom
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
		gameHandle->spawnObject<Bullet>(currentPosition.x, currentPosition.y);
	}
	object.setPosition(static_cast<sf::Vector2f>(currentPosition*static_cast<int>(interval.x)));	*/
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