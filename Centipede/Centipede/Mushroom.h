#pragma once
#include "GameObject.h";


class Mushroom: public GameObject
{
public:
	Mushroom();
	void update();
	bool getPoisoned();
	~Mushroom();
private:
	void setPoisoned(bool );
	int pointValue;
	bool poisoned;
	int health;
};