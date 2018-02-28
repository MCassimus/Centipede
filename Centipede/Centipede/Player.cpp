#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include "CentipedeGame.h"



Player::Player(sf::RenderWindow * renderWindow) : GameObject (renderWindow), bullet(renderWindow)
{
	setTexture("../Sprites/player.png");
	originalDimensions = window->getSize();
	interval = originalDimensions/static_cast<unsigned int>(30);
}


void Player::update()
{
	sf::Vector2f mousePos(sf::Mouse::getPosition(*window));
	float scalar = static_cast<float>(originalDimensions.x) / window->getSize().x;
	mousePos *= scalar;
	sf::Vector2u mousePosI(mousePos);

	mousePosI = getNearestCellPos(mousePosI);

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

sf::Vector2u Player::getNearestCellPos(sf::Vector2u position) {
	position.x -= (position.x%interval.x);
	position.y -= (position.y%interval.y);
	return position;
}


Player::~Player()
{
}