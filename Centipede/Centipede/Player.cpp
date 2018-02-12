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

	
}


Player::~Player()
{
}