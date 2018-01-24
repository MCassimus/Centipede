#pragma once
#include "GameObject.h";

class Mushroom: public GameObject
{
public:
	Mushroom();
	~Mushroom();
	void update();
	bool getPoisoned();
private:
	void setPoisoned(bool );
	int pointValue;
	bool poisoned;
	int health;
};