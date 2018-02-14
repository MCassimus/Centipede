#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet(sf::RenderWindow * renderWindow) : GameObject (renderWindow)
{
	window = renderWindow;
}


Bullet::~Bullet()
{
}