#include "CentipedeManager.h"



CentipedeManager::CentipedeManager() {
	return;
}

void CentipedeManager::calculateEntryX() {
	do {
		entryX = rand() % 30;
	} while (!CentipedeGame::isMushroomCell(entryX, 0));
}
