#include "stdafx.h"
#include "CentipedeGame.h"


CentipedeGame::CentipedeGame(sf::RenderWindow * renderWindow)
{
	window = renderWindow;
}


CentipedeGame::~CentipedeGame()
{
}


//main game loop
bool loop()
{
	return true;//returns true while game should be running
}


//reset game
void reset()
{
	return;
}