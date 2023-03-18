#include "Food.h"

Food::~Food()
{
}

/* Will never trigger. */
void Food::handleCollision(GameObject& object)
{}

void Food::handleCollision(Food& Food)
{}


void Food::handleCollision(TimeGift & gift)
{}

void Food::handleCollision(LifeGift & gift)
{}

void Food::handleCollision(FreezeGift & gift)
{}

void Food::handleCollision(SuperGift & gift)
{
}

/* Will never collide. */
void Food::handleCollision(Gate& gate)
{}

/* Will never collide. */
void Food::handleCollision(Key& Key)
{}

/* Will never collide. */
void Food::handleCollision(Wall& wall)
{}

void Food::handleCollision(Pacman& pacman)
{
	this->m_isDisposed = true;
	this->setAteFood(true);
}

void Food::handleCollision(SuperPacman& superPacman)
{
	this->m_isDisposed = true;
	this->setAteFood(true);
}

/*Ghost handles this collision */
void Food::handleCollision(Ghost& ghost)
{}
