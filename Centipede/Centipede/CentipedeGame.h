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
private:
	bool isMushroomCell(unsigned int, unsigned int);
	void resolveCollision();
	void setCell(unsigned int, unsigned int, GameObject *);
	std::vector<GameObject *> map[2][30][30];
	bool frame = 0;
	sf::RenderWindow * window = nullptr;
};