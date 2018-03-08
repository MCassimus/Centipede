#include "stdafx.h"
#include "Player.h"
#include "CentipedeGame.h"



Player::Player(sf::RenderWindow * renderWindow, int x, int y) : GameObject (renderWindow, x, y)//, bullet(renderWindow)
{
	setTexture("../Sprites/player.png");
}


void Player::update()
{

	sf::Vector2i mousePosI(getNearestCellPos(getRelMousePos()));

	if ((30 - (mousePosI.y / interval.y)) > 12)
		mousePosI.y = (30-12)*interval.y;

	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
	//	bullet.goToPosition(object.getPosition());//set bullet position to my position

	//if no existing bullet and player requesting to fire bullet make bullet
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && bullet == nullptr)
	{
		bullet = new Bullet(window, currentPosition.x, currentPosition.y);
		bullet->goToPosition(object.getPosition());
	}

	//if there is currently a bullet update
	if (bullet != nullptr)
	{
		bullet->update();
		bullet->render();
	}

	object.setPosition(static_cast<sf::Vector2f>(mousePosI));

	//test player death
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			health = 0;

	//if (bullet.isActive()) 
	//	bullet.update();
	//	bullet.render();
}


Player::~Player()
{
}