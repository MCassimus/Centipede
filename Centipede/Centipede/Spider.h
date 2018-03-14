#pragma once
#include "GameObject.h"
#include "Player.h"


class Spider : public GameObject
{
public:
	Spider(sf::RenderWindow *, int, int, Player&);
	void update();
	void setPointValue();
	void colideWith(GameObject*);
	~Spider();
private: 
	void findDistancePlayer();
	Player *player;
	int pointValue; 
	int distanceFromPlayer;
	bool takeHealth();
};