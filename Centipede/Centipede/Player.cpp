#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include "CentipedeGame.h"


Player::Player(sf::RenderWindow * renderWindow) : GameObject (renderWindow)
{
	setTexture("../Sprites/player.png");
<<<<<<< HEAD
	std::cout << "I have been born!\n";
=======
	printf("Why no work");
>>>>>>> 3b76c4fdf483e40bc59efde2b7a3f23cb039b944
}


void Player::update()
{
	printf("update");
	//sf::Vector2i mousePos = sf::Mouse::getPosition();

<<<<<<< HEAD
	std::cout << "i liiiive!\n\n\n\n\n\n";

	//current position based on mouse cursor, snap  grid through multiplication of 30
	currentPosition = sf::Vector2u(mousePos.x / window->getSize().x * 30, mousePos.y / window->getSize().y * 30);
=======
	////current position based on mouse cursor, snap  grid through multiplication of 30
	//currentPosition = sf::Vector2u(mousePos.x / window->getSize().x * 30, mousePos.y / window->getSize().y * 30);
>>>>>>> 3b76c4fdf483e40bc59efde2b7a3f23cb039b944

	//printf("x : %i\n y : %i\n", currentPosition.x, currentPosition.y);
}


Player::~Player()
{
}