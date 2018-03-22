#include "stdafx.h"
#include "CentipedeGame.h"
#include "Mushroom.h"
#include "Player.h"
#include "Scorpion.h"
#include "CentipedeSegment.h"
#include "Spider.h"

bool CentipedeGame::frame = false;
std::vector<GameObject *> CentipedeGame::map[30][30][2] = {};
unsigned int CentipedeGame::clock = 0, CentipedeGame::score = 0;


CentipedeGame::CentipedeGame(sf::RenderWindow * renderWindow, const sf::Vector2u oWD) : originalWindowDimensions(oWD)
{
	GameObject::oWD = oWD;
	window = renderWindow;

	reset();
}


CentipedeGame::~CentipedeGame()
{
	for (int y = 0; y < 30; y++)
		for (int x = 0; x < 30; x++)
			for (int i = 0; i < map[y][x][frame].size(); ++i)
			{
				delete map[y][x][frame].at(i);
				map[y][x][frame].erase(i + map[y][x][frame].begin());
			}
				
}


bool CentipedeGame::update()
{
	static bool liveFlea = false;
	static bool playerLife = true;
	static bool liveScorpion = false;

	#pragma region updateObjects
	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x) 
			for (int i = 0; i < map[y][x][frame].size(); ++i)
				map[y][x][frame].at(i)->update();
	#pragma endregion	

	frame = !frame;

	//migrates map from frame a to frame b
	#pragma region moveMap
	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x)
			for (int i = 0; i < map[y][x][!frame].size(); ++i)
			{
				placeObject(map[y][x][!frame].at(i)->getPosition().x, map[y][x][!frame].at(i)->getPosition().y, map[y][x][!frame].at(i));
			}
	#pragma endregion

	for (int y = 0; y < 30; y++)
		for (int x = 0; x < 30; x++) {
			map[y][x][!frame].clear();
		}

	resolveCollisions();

	//remove items with 0 health
	#pragma region mapCleanup
	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x)
			for (int i = 0; i < map[y][x][frame].size(); ++i)
			{
				if (map[y][x][frame].at(i)->getHealth() == 0)
				{
					//check if object removed is flea
					if (liveFlea && dynamic_cast<Flea *>(CentipedeGame::map[y][x][CentipedeGame::frame].at(i)) != nullptr)
						liveFlea = false;
					if (liveScorpion && dynamic_cast<Scorpion *>(CentipedeGame::map[y][x][CentipedeGame::frame].at(i)) != nullptr)
						liveScorpion = false;

					kill(map[y][x][frame].at(i));
					map[y][x][frame].erase(map[y][x][frame].begin() + i);
				}
			}
	#pragma endregion

	//check if flea needs to be spawned
	#pragma region fleaCheck
	int mushroomCount = 0;
	for (int y = 28; y > 17; y--)//check mushrooms in player position
		for (int x = 0; x < 29; x++)
			if (isMushroomCell(x, y))
				++mushroomCount;

	if (mushroomCount < 5 && !liveFlea)
	{
		int xpos = rand() % 29;
 		placeObject(xpos , 0, new Flea(window, xpos, 0));
		liveFlea = true;
	}
	#pragma endregion

	//Scorpion spawning
	if (!liveScorpion && rand() % 100 < 5)
	{
		int xRandPos = rand() % 30 < 15 ? 0 : 29;
		int yRandPos = rand() % 17;
		placeObject(xRandPos, yRandPos, new Scorpion(window, xRandPos, yRandPos));
		liveScorpion = true;
	}


	draw();
	
	//reset game on press of w key
	//this really has no actually purpose except to look cool
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//clear map
		for (int y = 0; y < 30; y++)
			for (int x = 0; x < 30; x++)
				map[y][x][frame].clear();

		reset();
	}
	
	++clock;

	return playerLife;//return true while player alive
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
	int yRandPos;
	int xRandPos = rand() % 30;

	placeObject(15, 29, new Player(window, 15, 29));//spawn player
	placeObject(xRandPos, 0, new CentipedeSegment(window, xRandPos, 0));

	Player * player = nullptr;

	//find player
	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x)
			for (int i = 0; i < map[y][x][frame].size(); ++i)
				if (dynamic_cast<Player *>(map[y][x][frame].at(i)) != nullptr)
					player = dynamic_cast<Player *>(map[y][x][frame].at(i));

	placeObject(0, 20, new Spider(window, 0, 20, *player));
	
	//randomly place mushrooms on map on startup
	for (int y = 0; y < 29; ++y)
		for (int x = 0; x < 30; ++x)
			if(rand() % (rand() % 35 + 1) == 1)
				placeObject(x, y, new Mushroom(window, x, y));
}


void CentipedeGame::resolveCollisions()
{
	//if any index in map has more than 1 object in vector, resolve collisions
	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x) 
			if (map[y][x][frame].size() > 1)//at coord
				for (int i = 0; i < map[y][x][frame].size(); ++i)
					for (int j = 0; j < map[y][x][frame].size(); ++j)
						if(i != j)
							map[y][x][frame].at(i)->collideWith(map[y][x][frame].at(j));
}


void CentipedeGame::placeObject(unsigned int x, unsigned int y, GameObject * object)
{
	if (x < 30 && y < 30)//keep object in bounds of array
		map[y][x][frame].push_back(object);
	else
		CentipedeGame::kill(object);
}

void CentipedeGame::kill(GameObject *thing) {
	bool readyToDie;
	score += thing->die(readyToDie);
	if (readyToDie)
		delete thing;

	std::cout << "score is now " << score << std::endl;
}