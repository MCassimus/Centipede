#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include "CentipedeGame.h"



Player::Player(sf::RenderWindow * renderWindow) : GameObject (renderWindow), bullet(renderWindow)
{
	setTexture("../Sprites/player.png");
}


void Player::update()
{
	sf::Vector2i mousePosI(getNearestCellPos(getRelMousePos()));

	if ((30 - (mousePosI.y / interval.y)) > 12) {
		mousePosI.y = (30-12)*interval.y;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		//set bullet position to my position
	}

	object.setPosition(static_cast<sf::Vector2f>(mousePosI));

	bullet.update();
	if (bullet.isActive()) bullet.render();
}


Player::~Player()
{
}