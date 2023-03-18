#include "Pacman.h"

/*Double dispatching to know what kind of object it is.*/
void Pacman::handleCollision(GameObject& object)
{
	if (&object == this) return;
	object.handleCollision(*this);
}

/*Returns to previous position.*/
void Pacman::handleCollision(Wall& wall)
{
	this->setPosition(this->m_prevPosition);
}

void Pacman::handleCollision(Pacman& pacman)
{}

void Pacman::handleCollision(SuperPacman & superPacman)
{
}

/*Returns to previous position.*/
void Pacman::handleCollision(Ghost& ghost)
{
	this->setPosition(this->m_prevPosition);
}

/* Returns to previous position. */
void Pacman::handleCollision(Key& Key)
{
	if (Key.isDisposed())
	{
		this->m_gotKey = true; 
	}
}

/* Returns to previous position. */
void Pacman::handleCollision(Gate& gate)
{
	if (!this->m_gotKey)
		this->setPosition(this->m_prevPosition);
	else 
	{
		this->m_gotKey = false;
	}
}

void Pacman::handleCollision(Food& food)
{
	food.handleCollision(*this);
}

void Pacman::handleCollision(TimeGift& gift)
{}

void Pacman::handleCollision(LifeGift& gift)
{
}

void Pacman::handleCollision(FreezeGift& gift)
{
}

void Pacman::handleCollision(SuperGift& gift)
{
}
