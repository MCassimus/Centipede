#pragma once
#include "GameObject.h";


class CentipedeSegment: public GameObject
{
public:
	CentipedeSegment();
	void update();
	~CentipedeSegment();
private:
	int pointValue;
	int dir;
	bool isHead;
};

