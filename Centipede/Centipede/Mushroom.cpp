#include "stdafx.h"
#include "Mushroom.h"


Mushroom::Mushroom()
{
	pointValue=1;
	poisoned=false;
	health=4;
}


Mushroom::~Mushroom()
{
}


void Mushroom::setPoisoned(bool isPoisoned)
{
	poisoned = isPoisoned;
	return;
}


void Mushroom::update()
{

	return;
}


bool Mushroom::getPoisoned()
{

	return false;
}