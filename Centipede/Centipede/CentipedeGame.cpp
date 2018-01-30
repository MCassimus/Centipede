#include "stdafx.h"
#include "CentipedeGame.h"


CentipedeGame::CentipedeGame(sf::RenderWindow * renderWindow)
{
	window = renderWindow;
}


CentipedeGame::~CentipedeGame()
{
}


bool CentipedeGame::update()
{
	return true;
}


void CentipedeGame::draw()
{
	return;
}


bool CentipedeGame::isMushroomCell(unsigned int x, unsigned int y)
{
	return false;
}


void CentipedeGame::resolveCollision()
{
	return;
}


void CentipedeGame::setCell(unsigned int x, unsigned int y, GameObject * object)
{
	return;
}