#include "stdafx.h"
#include "Player.h"
#include "CentipedeGame.h"



Player::Player(sf::RenderWindow * renderWindow, int x, int y) : GameObject (renderWindow, x, y), bullet(renderWindow, x, y)
{
	setTexture("../Sprites/player.png");
}


void Player::update()
{

	sf::Vector2i mousePosI(getNearestCellPos(getRelMousePos()));
	mousePosI /= static_cast<int>(interval.x);

	if ((30 - mousePosI.y) > 12)
		mousePosI.y = 30-12;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !bullet.isActive())
		bullet.goToPosition(static_cast<sf::Vector2i>(mousePosI));


	object.setPosition(static_cast<sf::Vector2f>(mousePosI*static_cast<int>(interval.x)));

	//test player death
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		health = 0;

	if (bullet.isActive()) {
		bullet.update();
		bullet.render();
		std::cout << "render!!\n";
	}
}


Player::~Player()
{
}