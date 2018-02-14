#include "stdafx.h"
#include <iostream>
#include "CentipedeGame.h"
#include "Mushroom.h"
#include "Player.h"

bool CentipedeGame::frame = false;
std::vector<GameObject *> CentipedeGame::map[30][30][2] = {};


CentipedeGame::CentipedeGame(sf::RenderWindow * renderWindow) : player(renderWindow)
{
	window = renderWindow;
	placeObject(15, 29, &player);
	std::cout << map[29][15][frame].size();
	reset();
}


CentipedeGame::~CentipedeGame()
{
}


bool CentipedeGame::update()
{

	std::cout << "new frame\n";

	//frame = !frame;

	resolveCollisions();

	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x) {
			//std::cout << "at coordinates (" << x << ", " << y << ") ";
			//std::cout << "i have " << map[frame][y][x].size() << " elements\n";
			for (int i = 0; i < map[y][x][frame].size(); ++i) {
				std::cout << "updating element at coordinates (" << x << ", " << y << ", " << i << ")\n";
				map[y][x][frame].at(i)->update();
			}
		}


	draw();

	std::cout << "done drawing\n";
	return true;//return true while player alive
}


void CentipedeGame::draw()
{
	window->clear();

	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x)
			for (int i = 0; i < map[y][x][frame].size(); ++i)
				map[y][x][frame].at(i)->render();

	window->display();
}


bool CentipedeGame::isMushroomCell(unsigned int x, unsigned int y)
{
	for (int i = 0; i < CentipedeGame::map[y][x][CentipedeGame::frame].size(); i++)
		if (dynamic_cast<Mushroom *>(CentipedeGame::map[y][x][CentipedeGame::frame].at(i)) != nullptr)
			return true;
	return false;
}


//start a level
void CentipedeGame::reset()
{
	placeObject(15, 30,  new Player(window));
}


void CentipedeGame::resolveCollisions()
{
	std::vector<GameObject*> *gameObjects;
	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x) {
			gameObjects = &map[y][x][frame];
			if (gameObjects->size() > 1)
				for (int i = 0; i < gameObjects->size(); ++i)
					map[y][x][frame].at(i)->collideWith(gameObjects);
		}
}


void CentipedeGame::placeObject(unsigned int x, unsigned int y, GameObject * object)
{
	if(x < 30 && y < 30)//keep object in bounds of array
		map[y][x][frame].push_back(object);
}