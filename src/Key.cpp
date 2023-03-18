#include "Key.h"

Key::~Key()
{
}

/* Will never trigger. */
void Key::handleCollision(GameObject& object)
{}

void Key::handleCollision(Key& key)
{}

/* Will never collide. */
void Key::handleCollision(Gate& gate)
{}

void Key::handleCollision(Food& food)
{}

void Key::handleCollision(TimeGift & gift)
{}

void Key::handleCollision(LifeGift & gift)
{}

void Key::handleCollision(FreezeGift & gift)
{}

void Key::handleCollision(SuperGift & gift)
{
}

/* Will never collide. */
void Key::handleCollision(Wall& wall)
{}

void Key::handleCollision(Pacman& pacman)
{
	if (!pacman.getKeyInfo()){
		this->m_isDisposed = true;
		this->setAteKey(true);
	}
	pacman.handleCollision(*this);
}

void Key::handleCollision(SuperPacman& superPacman)
{
	if (!superPacman.getKeyInfo()) {
		this->m_isDisposed = true;
		this->setAteKey(true);
	}
	superPacman.handleCollision(*this);
}

void Key::handleCollision(Ghost& ghost)
{}