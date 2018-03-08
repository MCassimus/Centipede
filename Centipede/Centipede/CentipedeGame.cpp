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

	#pragma region updateObjects
	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x) 
			for (int i = 0; i < map[y][x][frame].size(); ++i)
				map[y][x][frame].at(i)->update();
	#pragma endregion	

	//remove items with 0 health
	#pragma region mapCleanup
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
	#pragma endregion

	//check if flea needs to be spawned
	#pragma region fleaCheck
	int mushroomCount = 0;
	for (int y = 28; y > 17; y--)
		for (int x = 0; x < 29; x++)
			if (isMushroomCell(x, y))
				mushroomCount++;

	if (mushroomCount < 5 && !liveFlea)
	{
 		placeObject(rand() % 29, 0, new Flea(window));
		liveFlea = true;
	}
	#pragma endregion

	draw();
	return true;//return true while player alive
}


static bool grid = false;
void CentipedeGame::draw()
{
	//this is temp
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		grid = !grid;

	window->clear();

	if (grid)
	{
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
	}

	//draw all objects in map
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
	placeObject(15, 29, new Player(window));//spawn player
	placeObject(15, 15, new Scorpion(window));
	
	//randomly place mushrooms on map on startup
	for (int y = 0; y < 29; ++y)
		for (int x = 0; x < 30; ++x)
			if(rand() % 6 == 1)
				placeObject(x, y, new Mushroom(window, sf::Vector2f(GameObject::interval.x* x, GameObject::interval.y*y)));
}


void CentipedeGame::resolveCollisions()
{
	//if any index in map has more than 1 object in vector, resolve collisions
	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x) 
			if (map[y][x][frame].size() > 1)
				for (int i = 0; i < map[y][x][frame].size(); ++i)
					map[y][x][frame].at(i)->collideWith(&map[y][x][frame]);
}


void CentipedeGame::placeObject(unsigned int x, unsigned int y, GameObject * object)
{
	if(x < 30 && y < 30)//keep object in bounds of array
		map[y][x][frame].push_back(object);
}