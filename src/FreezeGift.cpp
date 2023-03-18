#include "FreezeGift.h"

void FreezeGift::handleCollision(GameObject& object)
{}

void FreezeGift::handleCollision(Wall& wall)
{}

void FreezeGift::handleCollision(Pacman& pacman)
{
	this->m_isDisposed = true;
	this->setAteFreezeGift(true);
}

void FreezeGift::handleCollision(SuperPacman& superPacman)
{
	this->m_isDisposed = true;
	this->setAteFreezeGift(true);
}

/*Ghost encountered a wall*/
void FreezeGift::handleCollision(Ghost& ghost)
{
}

void FreezeGift::handleCollision(Key& Key)
{}

void FreezeGift::handleCollision(Gate& gate)
{}

void FreezeGift::handleCollision(Food& food)
{}

void FreezeGift::handleCollision(TimeGift& gift)
{
}

void FreezeGift::handleCollision(LifeGift& gift)
{
}

void FreezeGift::handleCollision(FreezeGift& gift)
{
}

void FreezeGift::handleCollision(SuperGift& gift)
{
}
