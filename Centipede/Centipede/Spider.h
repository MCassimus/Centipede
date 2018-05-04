#pragma once
#include "GameObject.h"
#include "Player.h"
#include <memory>


class Spider : public GameObject
{
public:
	Spider(int, int);
	void setTarget(std::shared_ptr<Player>);
	void update(CentipedeGame *gameHandle);
	void setPointValue();
	void collideWith(GameObject*);
	void move();
	unsigned int die(bool&, CentipedeGame*);
	char* getName() { return "Spider";  }
private:
	std::shared_ptr<Player> player;
	unsigned int delay = 15;
	bool dir;
};