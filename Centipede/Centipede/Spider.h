#pragma once
#include "GameObject.h"


class Spider : public GameObject
{
public:
	Spider(sf::RenderWindow *, int, int);
	void update();
	void setPointValue();
	~Spider();
private: 
	int pointValue; 
	int distanceFromPlayer;
	bool takeHealth();
};