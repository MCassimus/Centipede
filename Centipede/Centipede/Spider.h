#pragma once
#include "GameObject.h"


class Spider : public GameObject
{
public:
	Spider(sf::RenderWindow *);
	void update();
	int returnPointValue(int);
	~Spider();
private: 
	int pointValue = 300; 
	int distanceFromPlayer;
	bool takeHealth();
};