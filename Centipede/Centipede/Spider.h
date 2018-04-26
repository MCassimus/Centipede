#pragma once
#include "GameObject.h"
#include "Player.h"


class Spider : public GameObject
{
public:
	Spider(sf::RenderWindow *, int, int, Player&);
	void update();
	void setPointValue();
	void collideWith(GameObject*);
	void move();
	//int die(bool);//override die func to set score to 0 offscreen
	~Spider();
private: 
	Player *player; 
	int scuttle; //for animation
	unsigned int delay = 15;
	sf::Vector2i velocities[6];
	int count; //for direction change
	bool lastDir;
};