#include "TimeGift.h"

void TimeGift::handleCollision(GameObject& object)
{}

void TimeGift::handleCollision(Wall& wall)
{}
void TimeGift::handleCollision(Pacman& pacman)
{
	this->m_isDisposed = true;
	this->setAteTimeGift(true);
}
void TimeGift::handleCollision(SuperPacman& superPacman)
{
	this->m_isDisposed = true;
	this->setAteTimeGift(true);
}
void TimeGift::handleCollision(Ghost& ghost)
{
}

void TimeGift::handleCollision(Key& Key)
{}

void TimeGift::handleCollision(Gate& gate)
{}

void TimeGift::handleCollision(Food & food)
{
}

void TimeGift::handleCollision(TimeGift& gift)
{
}

void TimeGift::handleCollision(LifeGift& gift)
{
}

void TimeGift::handleCollision(FreezeGift& gift)
{
}

void TimeGift::handleCollision(SuperGift& gift)
{
}
