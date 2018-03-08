#include "stdafx.h"
#include "CentipedeSegment.h"


CentipedeSegment::CentipedeSegment(sf::RenderWindow * renderWindow, int x, int y) : GameObject(renderWindow, x,  y)
{
	pointValue = 10;
	isHead = false;
}


CentipedeSegment::~CentipedeSegment()
{
}


void CentipedeSegment::update()
{
	setPixels();
	return;
}