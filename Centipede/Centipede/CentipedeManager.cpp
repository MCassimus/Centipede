#include "CentipedeManager.h"
#include "CentipedeSegment.h"
#include <iostream>
#include "CentipedeGame.h"

CentipedeManager::CentipedeManager() {

	gameHandle = nullptr;
}

void CentipedeManager::bindToGame(CentipedeGame *handle) {
	gameHandle = handle;
}

void CentipedeManager::calculateEntryX() {
	do {
		entryX = rand() % 30;
	} while (CentipedeGame::isMushroomCell(entryX, 0));
}

bool CentipedeManager::beginSpawn(unsigned int frame, unsigned int _speed, unsigned int _length) {

	bool status;

	if (done) {

		done = false;

		calculateEntryX();
		entryTime = frame;
		speed = _speed;
		haveSpawned = 0;
		length = _length;

		status = true;
	}
	else
		status = false;

	return status;
}

void CentipedeManager::update() {
	if (!done && (CentipedeGame::clock % speed == 0)) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
		segments.push_back(gameHandle->spawnObject<CentipedeSegment>(entryX, 0));
=======
>>>>>>> b23df992cb2a6fd59b162bbf0cf60d8c8f428ea0

		gameHandle->doNothing();
		if (gameHandle != nullptr) {
			std::cout << haveSpawned << ',' << length << std::endl;
			gameHandle->spawnObject<CentipedeSegment>(entryX, 0);
		}
>>>>>>> 0f3f565c4479e80a7642366667bba3130106bca0
		if (++haveSpawned >= length)
			done = true;
	}
}

void CentipedeManager::placeSegment() {
}
