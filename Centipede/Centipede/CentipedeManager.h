#pragma once

#include "CentipedeSegment.h"

class CentipedeManager {
public:
	CentipedeManager();

	void calculateEntryX();

	bool beginSpawn(unsigned int, unsigned int);

private:
	void placeSegment();

	void update();

	unsigned int entryTime, haveSpawned, entryX, speed;
	bool done;
};