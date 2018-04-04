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
	~Spider();
private: 
	Player *player;
	int pointValue; 
	int scuttle; //for animation
	unsigned int frameMax = 40;
	sf::Vector2i velocities[6];
	int count; //for direction change
	bool lastDir;
};