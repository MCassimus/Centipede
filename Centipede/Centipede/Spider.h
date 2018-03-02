#pragma once
#include "GameObject.h"


class Spider : public GameObject
{
public:
	Spider(sf::RenderWindow *);
	void update();
	void setPointValue();
	~Spider();
private: 
	int pointValue; 
	int distanceFromPlayer;
	bool takeHealth();
};