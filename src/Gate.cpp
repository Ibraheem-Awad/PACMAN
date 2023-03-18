#include "Gate.h"

Gate::~Gate()
{}

/* Will never trigger. */
void Gate::handleCollision(GameObject& object)
{}

void Gate::handleCollision(Gate& Gate)
{}

void Gate::handleCollision(Food & food)
{}

void Gate::handleCollision(TimeGift & gift)
{}

void Gate::handleCollision(LifeGift & gift)
{}

void Gate::handleCollision(FreezeGift & gift)
{}

void Gate::handleCollision(SuperGift & gift)
{
}

/* Will never collide. */
void Gate::handleCollision(Key& Key)
{}

/* Will never collide. */
void Gate::handleCollision(Wall& wall)
{}

/*Ghost handles this collision */
void Gate::handleCollision(Ghost& ghost)
{
	ghost.handleCollision(*this);
}
void Gate::handleCollision(Pacman& pacman)
{
	if (pacman.getKeyInfo())
		this->m_isDisposed = true;

	pacman.handleCollision(*this);
}

void Gate::handleCollision(SuperPacman& superPacman)
{
	this->m_isDisposed = true;
	superPacman.handleCollision(*this);
}
