#include "stdafx.h"
#include "CentipedeGame.h"
#include <typeinfo.h>
#include "Mushroom.h"


CentipedeGame::CentipedeGame(sf::RenderWindow * renderWindow)
{
	window = renderWindow;
	frame = false;
}


CentipedeGame::~CentipedeGame()
{
}


bool CentipedeGame::update()
{
	frame = !frame;

	return true;
}


void CentipedeGame::draw()
{
	for (int y = 0; y < 30; y++)
		for (int x = 0; x < 30; x++)
			for (int i = 0; i < map[frame][x][y].size(); i++)
				map[frame][x][y].at(i)->render();

}


bool CentipedeGame::isMushroomCell(unsigned int x, unsigned int y)
{
	for (int i = 0; i < map[frame][x][y].size(); i++)
		if (dynamic_cast<Mushroom>(map[frame][x][y]) != nullptr)
			return true;
	return false;
}


void CentipedeGame::resolveCollision()
{
	return;	
}


void CentipedeGame::placeObject(unsigned int x, unsigned int y, GameObject * object)
{
	if(x < 30 && y < 30)//keep object in bounds of array
		map[frame][x][y].push_back(object);
}