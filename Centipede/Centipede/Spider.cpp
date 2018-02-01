#include "stdafx.h"
#include "Spider.h"


Spider::Spider(sf::RenderWindow * renderWindow) : GameObject(renderWindow)
{
	sf::Sprite spiderSprite;
	sf::Texture spiderTexture;

	if (!spiderTexture.loadFromFile("spider.png"))
	
	spiderSprite.setTexture(spiderTexture);
}


void Spider::update()
{
	return;
}

int Spider::returnPointValue(int distanceFromPlayer)
{

}
bool Spider::takeHealth()
{

}


Spider::~Spider()
{
}