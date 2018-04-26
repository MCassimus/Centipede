#pragma once

#include "CentipedeSegment.h"


class CentipedeGame;

class CentipedeManager {
public:
	CentipedeManager();

	void bindToGame(CentipedeGame*);

	void calculateEntryX();

	bool beginSpawn(unsigned int, unsigned int, unsigned int);

	void update();

private:
	CentipedeGame *gameHandle;
	void placeSegment();

	unsigned int entryTime, haveSpawned, entryX, speed, length;
	bool done = true;
};