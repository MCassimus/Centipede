#include "stdafx.h"
#include "Player.h"
#include "CentipedeGame.h"

Player::Player(sf::RenderWindow * renderWindow, int x, int y) : GameObject (renderWindow, x, y)
{
	setTexture("../Sprites/player.png");
	health = 3;
	bullet = new Bullet(renderWindow);
}


void Player::update()
{

	currentPosition = getNearestCellPos(getRelMousePos());
	currentPosition /= static_cast<int>(interval.x);

	if ((30 - currentPosition.y) > 12)
		currentPosition.y = 30-12;
	if (currentPosition.y > 29)
		currentPosition.y = 29;
	if (currentPosition.x < 0)
		currentPosition.x = 0;
	if (currentPosition.x > 29)
		currentPosition.x = 29;

	//std::cout << "Player is being updated now!----------------------------\n";

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !bullet->isAlive()) {
		bullet->shootFrom(currentPosition);
	}


	object.setPosition(static_cast<sf::Vector2f>(currentPosition*static_cast<int>(interval.x)));

	//test player death
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		health = 0;
}

char* Player::getType() {
	return "Player";
}


Player::~Player()
{
}