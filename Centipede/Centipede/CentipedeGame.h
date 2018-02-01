#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <vector>
#include "GameObject.h"

class CentipedeGame
{
public:
	CentipedeGame(sf::RenderWindow *);
	~CentipedeGame();
	bool update();
	void draw();
	static bool isMushroomCell(unsigned int, unsigned int);
private:
	void resolveCollision();
	void placeObject(unsigned int, unsigned int, GameObject *);
	static std::vector<GameObject *> map[2][30][30];
	static bool frame;
	sf::RenderWindow * window = nullptr;
};