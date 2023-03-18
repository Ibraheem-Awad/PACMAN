#include "SuperPacman.h"

/*Double dispatching to know what kind of object it is.*/
void SuperPacman::handleCollision(GameObject& object)
{
	if (&object == this) return;
	object.handleCollision(*this);
}

/*Returns to previous position.*/
void SuperPacman::handleCollision(Wall& wall)
{
	this->setPosition(this->m_prevPosition);
}

void SuperPacman::handleCollision(Pacman& pacman)
{}

void SuperPacman::handleCollision(SuperPacman& superPacman)
{
}

/*Returns to previous position.*/
void SuperPacman::handleCollision(Ghost& ghost)
{

}

/* Returns to previous position. */
void SuperPacman::handleCollision(Key& Key)
{
	if (Key.isDisposed())
	{
		this->m_gotKey = true;
	}
}

/* Returns to previous position. */
void SuperPacman::handleCollision(Gate& gate)
{
	this->m_gotKey = false;
}

void SuperPacman::handleCollision(Food& food)
{
	food.handleCollision(*this);
}

void SuperPacman::handleCollision(TimeGift& gift)
{
}

void SuperPacman::handleCollision(LifeGift& gift)
{
}

void SuperPacman::handleCollision(FreezeGift& gift)
{
}

void SuperPacman::handleCollision(SuperGift& gift)
{
}
