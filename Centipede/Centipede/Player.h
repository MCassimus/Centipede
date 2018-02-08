#pragma once
#include "GameObject.h"


class Player
{
public:
	Player(sf::RenderWindow *);
	void update();
	~Player();
private:
	int health;
	std::vector<sf::RectangleShape> bullets;
};