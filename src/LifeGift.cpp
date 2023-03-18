#include "LifeGift.h"

void LifeGift::handleCollision(GameObject& object)
{}

void LifeGift::handleCollision(Wall& wall)
{}

void LifeGift::handleCollision(Pacman& pacman)
{
	this->m_isDisposed = true;
	this->setAteLifeGift(true);
}

void LifeGift::handleCollision(SuperPacman& superPacman)
{
	this->m_isDisposed = true;
	this->setAteLifeGift(true);
}

/*Ghost encountered a wall*/
void LifeGift::handleCollision(Ghost& ghost)
{
}

void LifeGift::handleCollision(Key& Key)
{}

void LifeGift::handleCollision(Gate& gate)
{}

void LifeGift::handleCollision(Food& food)
{}

void LifeGift::handleCollision(TimeGift& gift)
{
}

void LifeGift::handleCollision(LifeGift& gift)
{
}

void LifeGift::handleCollision(FreezeGift& gift)
{
}

void LifeGift::handleCollision(SuperGift& gift)
{
}
