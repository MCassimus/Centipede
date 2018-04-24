#include "CentipedeManager.h"
#include "CentipedeGame.h"



CentipedeManager::CentipedeManager() {
}

void CentipedeManager::calculateEntryX() {
	do {
		entryX = rand() % 30;
	} while (!CentipedeGame::isMushroomCell(entryX, 0));
}

bool CentipedeManager::beginSpawn(unsigned int frame, unsigned int _speed) {
	bool status;

	if (done) {
		done = false;

		calculateEntryX();
		entryTime = frame;
		speed = _speed;

		status = true;
	}
	else
		status = false;

	return status;
}

//void CentipedeManager::update() {
//	if (!done && CentipedeGame::clock % speed) {
//		CentipedeGame::spawnObject<CentipedeSegment>(entryX, 0);
//	}
//}

void CentipedeManager::placeSegment() {
}
