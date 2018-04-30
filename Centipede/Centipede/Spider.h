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
	unsigned int die(bool &);
	~Spider();
private: 
	Player *player; 
	unsigned int delay = 15;
	bool dir;
};