#include "stdafx.h"
#include "Player.h"
#include "CentipedeGame.h"


Player::Player(sf::RenderWindow * renderWindow) : GameObject (renderWindow)
{
	setTexture("../Sprites/player.png");
}


void Player::update()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition();

	//current position based on mouse cursor, snap  grid through multiplication of 30
	currentPosition = sf::Vector2u(mousePos.x / window->getSize().x * 30, mousePos.y / window->getSize().y * 30);

	printf("x : %i\n y : %i\n", currentPosition.x, currentPosition.y);
}


Player::~Player()
{
}