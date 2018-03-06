#include "stdafx.h"
#include <iostream>
#include "CentipedeGame.h"
#include "Mushroom.h"
#include "Player.h"
#include "Scorpion.h"

bool CentipedeGame::frame = false;
std::vector<GameObject *> CentipedeGame::map[30][30][2] = {};


CentipedeGame::CentipedeGame(sf::RenderWindow * renderWindow, const sf::Vector2u oWD) : originalWindowDimensions(oWD)
{
	GameObject::oWD = oWD;
	window = renderWindow;
	std::cout << map[29][15][frame].size();
	reset();
}


CentipedeGame::~CentipedeGame()
{
}


bool CentipedeGame::update()
{
	static bool liveFlea = false;
	//frame = !frame;

	resolveCollisions();

	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x) 
			for (int i = 0; i < map[y][x][frame].size(); ++i)
				map[y][x][frame].at(i)->update();

	//remove items with 0 health
	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x)
			for (int i = 0; i < map[y][x][frame].size(); ++i)
				if (map[y][x][frame].at(i)->getHealth() == 0)
				{
					//check if object removed is flea
					if (liveFlea && dynamic_cast<Flea *>(CentipedeGame::map[y][x][CentipedeGame::frame].at(i)) != nullptr)
						liveFlea = false;

					map[y][x][frame].erase(map[y][x][frame].begin() + i);
				}

	//check if flea needs to be spawned
	int mushroomCount = 0;
	for (int y = 28; y > 17; y--)
		for (int x = 0; x < 29; x++)
			if (isMushroomCell(x, y))
				mushroomCount++;

	if (mushroomCount < 5 && !liveFlea)
	{
 		//placeObject(rand() % 29, 0, new Flea(window));
		liveFlea = true;
	}

	draw();
	return true;//return true while player alive
}


void CentipedeGame::draw()
{
	window->clear();

	sf::VertexArray linePoints(sf::Lines);

	for (int y = 0; y < originalWindowDimensions.y; y+=originalWindowDimensions.y/30) {
		linePoints.append(sf::Vector2f(0, y));
		linePoints.append(sf::Vector2f(originalWindowDimensions.x, y));
	}
	for (int x = 0; x < originalWindowDimensions.x; x+=originalWindowDimensions.x/30) {
		linePoints.append(sf::Vector2f(x, 0));
		linePoints.append(sf::Vector2f(x, originalWindowDimensions.y));
	}

	window->draw(linePoints);

	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x)
			for (int i = 0; i < map[y][x][frame].size(); ++i)
				map[y][x][frame].at(i)->render();

	window->display();
}


bool CentipedeGame::isMushroomCell(unsigned int x, unsigned int y)
{
	if (x < 30 && y < 30)
		for (int i = 0; i < CentipedeGame::map[y][x][CentipedeGame::frame].size(); i++)
			if (dynamic_cast<Mushroom *>(CentipedeGame::map[y][x][CentipedeGame::frame].at(i)) != nullptr)
				return true;
	return false;
}


//start a level
void CentipedeGame::reset()
{
	placeObject(15, 29, new Player(window));
	placeObject(15, 15, new Scorpion(window));
	//placeObject(rand() % 29, rand() % 29, new Mushroom(window));
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