#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(sf::RenderWindow *);
	void update();
	~Player();
private:
	int health = 3;
	std::vector<sf::RectangleShape> bullets;
};