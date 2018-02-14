#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include "CentipedeGame.h"


Player::Player(sf::RenderWindow * renderWindow) : GameObject (renderWindow)
{
	setTexture("Sprites/player.png");
}


void Player::update()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

	std::cout << mousePos.x << ',' << mousePos.y << '\n';

	int intervalX = window->getSize().x/30;
	int intervalY = window->getSize().y/30;

	std::cout << intervalX << '\n';

	//current position based on mouse cursor, snap  grid through multiplication of 30
	object.setPosition(mousePos.x-(mousePos.x%intervalX), mousePos.y-(mousePos.y%intervalY));

	//printf("x : %i\n y : %i\n", currentPosition.x, currentPosition.y);
}


Player::~Player()
{
}