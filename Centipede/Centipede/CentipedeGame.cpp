#include "stdafx.h"
#include "CentipedeGame.h"
#include "Mushroom.h"
#include "Player.h"
#include "Scorpion.h"
#include "CentipedeSegment.h"
#include "Spider.h"
#include <iostream>

bool CentipedeGame::frame = false;
std::vector<GameObject *> CentipedeGame::map[30][30][2] = {};
unsigned int CentipedeGame::clock = 0, CentipedeGame::score = 0;
int CentipedeGame::playerLives = -1;


CentipedeGame::CentipedeGame(sf::RenderWindow * renderWindow, const sf::Vector2u oWD) : originalWindowDimensions(oWD), linePoints(sf::Lines, 30 * 30)
{
	GameObject::oWD = oWD;
	window = renderWindow;
	generateGrid();
	reset();

	


	scoreArea.create(renderWindow->getSize().x, renderWindow->getSize().x * .05);
	playerArea.create(renderWindow->getSize().x, renderWindow->getSize().y);

	playerAreaSprite.setTexture(playerArea.getTexture());
	scoreAreaSprite.setTexture(scoreArea.getTexture());

	playerAreaSprite.move(0, renderWindow->getSize().x * .05);

	arcadeFont.loadFromFile("../ARCADECLASSIC.TTF");
	scoreDisplay.setFont(arcadeFont);
	scoreDisplay.setCharacterSize(18);
	
	lifeTexture.loadFromFile("../Sprites/player.png");
	for (int i = 0; i < 6; i++)
	{
		lives[i].setTexture(lifeTexture);
		lives[i].setPosition(10 + 20 * i, 0);
	}
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
	static bool liveScorpion = false;

	std::cout << "-----New frame, clock = " << clock << "-----\n";

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
				placeObject(map[y][x][!frame].at(i)->getPosition().x, map[y][x][!frame].at(i)->getPosition().y, map[y][x][!frame].at(i));
	#pragma endregion

	//clear the old map

	for (int y = 0; y < 30; y++)
		for (int x = 0; x < 30; x++) 
			map[y][x][!frame].clear();

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

	//update player health
	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x)
			for (int i = 0; i < map[y][x][frame].size(); ++i)
				if (dynamic_cast<Player *> (map[y][x][frame].at(i)) != nullptr)
					playerLives = map[y][x][frame].at(i)->getHealth();

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
	if (!liveScorpion && rand() % 1000 < 5)
	{
		int xRandPos = rand() % 30 < 15 ? 0 : 29;
		int yRandPos = rand() % 17;
		placeObject(xRandPos, yRandPos, new Scorpion(window, xRandPos, yRandPos));
		liveScorpion = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		for (int y = 0; y < 30; ++y)
			for (int x = 0; x < 30; ++x)
				for (int i = 0; i < map[y][x][frame].size(); ++i)
					if (dynamic_cast<Mushroom *> (map[y][x][frame].at(i)) != nullptr)
						dynamic_cast<Mushroom *> (map[y][x][frame].at(i))->resetHeath();

	//Centipede spawning

	manageCentipedePopulation();
	
	draw();
	
	++clock;

	return playerLives > 0;//return true while player alive
}


static bool grid = false;
void CentipedeGame::draw()
{
	//this is temp
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		grid = !grid;

	//window->clear();
	scoreArea.clear();
	playerArea.clear();

	//update score and draw to render texture
	scoreDisplay.setFillColor(sf::Color::Red);
	scoreDisplay.setString("Score " + std::to_string(score));
	scoreDisplay.setOrigin(scoreDisplay.getLocalBounds().width / 2, scoreDisplay.getLocalBounds().height/ 2);
	scoreDisplay.setPosition(scoreAreaSprite.getTexture()->getSize().x / 2, 0);

	scoreArea.draw(scoreDisplay);
	//draw lives
	drawLives();

	if(grid)
		playerArea.draw(linePoints);

	playerArea.display();
	scoreArea.display();

	//draw all objects in map
	for (int y = 0; y < 30; ++y)
		for (int x = 0; x < 30; ++x)
			for (int i = 0; i < map[y][x][frame].size(); ++i)
				map[y][x][frame].at(i)->render(playerArea);
	
	window->draw(playerAreaSprite);
	window->draw(scoreAreaSprite);
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

	placeObject(15, 29, new Player(window, 15, 29));//spawn player

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

void CentipedeGame::generateGrid() {
	int scalar = originalWindowDimensions.x / 30;
	sf::Color col(20, 20, 20);

	for (int i = 0, index = 0; i < 30; ++i, index += 4) {
		linePoints[index + 0] = sf::Vector2f(0, i*scalar);
		linePoints[index + 1] = sf::Vector2f(originalWindowDimensions.x, i*scalar);
		linePoints[index + 2] = sf::Vector2f(i*scalar, 0);
		linePoints[index + 3] = sf::Vector2f(i*scalar, originalWindowDimensions.y);

		for (int offset = 0; offset < 4; ++offset)
			linePoints[index + offset].color = col;
	}
}

unsigned int CentipedeGame::getCountOf(char* type, unsigned int startX = 0, unsigned int startY = 0, unsigned int endX = 30, unsigned int endY = 30) {
	unsigned int count = 0;
	for (int y = startY; y < endY; ++y)//check mushrooms in player position
		for (int x = startX; x < endX; ++x)
			for (int i = 0; i < CentipedeGame::map[y][x][CentipedeGame::frame].size(); i++)
				if (!std::strcmp(CentipedeGame::map[y][x][CentipedeGame::frame].at(i)->getType(), type))
					++count;

	return count;
}

void CentipedeGame::manageCentipedePopulation() {
	if (activeCentipede) {
		//check if centipede has died
		activeCentipede = getCountOf("CentipedeSegment", 0, 0, 30, 30) > 0;
	}
	else {

		CentipedeSegment *last = nullptr, *current = nullptr;
		for (int i = 0, x; i < 5; ++i) {

			current = new CentipedeSegment(window, i, 0, last);
			placeObject(i, 0, current);
			last = current;
		}
		current->setAsHead();
		activeCentipede = true;
		//begin spawning centipede
	}
}


void CentipedeGame::drawLives()
{
	for(int i=0; i < playerLives; i++)
		scoreArea.draw(lives[i]);
	return;
}