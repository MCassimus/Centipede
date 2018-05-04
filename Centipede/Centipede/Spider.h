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
<<<<<<< HEAD
	unsigned int die(bool&, CentipedeGame*);
	char* getName() { return "Spider";  }
=======
	unsigned int die(bool &, CentipedeGame *);
>>>>>>> 4390e2108a9e97653fce7b67d1ea7e09769f5294
	~Spider();
private:
	std::shared_ptr<Player> player;
	unsigned int delay = 15;
	bool dir;
};