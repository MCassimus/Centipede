#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include "CentipedeGame.h"


Player::Player()
{
}


Player::Player(sf::RenderWindow * renderWindow) : GameObject (renderWindow)
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
	sf::Vector2i mousePosI(mousePos);

	std::cout << "mouse position:" << mousePos.x << ", " <<
		mousePos.y << std::endl;

	std::cout << "window dimensions:" << window->getSize().x << ", " <<
		window->getSize().y << std::endl;

	std::cout << "intervals:" << interval.x << ", " <<
		interval.y << std::endl;

	std::cout << "player position:" << mousePosI.x - (mousePosI.x%interval.x) << ", " <<
		mousePos.y - (mousePosI.y%interval.y) << std::endl;

	object.setPosition(mousePos.x-(mousePosI.x%interval.x), mousePosI.y-(mousePosI.y%interval.y));
}


Player::~Player()
{
}