#pragma once

#include "CentipedeGame.h"
#include "CentipedeSegment.h"

class CentipedeManager {
public:
	CentipedeManager();

	void calculateEntryX();

private:
	unsigned int entryTime;
	unsigned int entryX;
};

