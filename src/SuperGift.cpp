#include "SuperGift.h"

void SuperGift::handleCollision(GameObject& object)
{}

void SuperGift::handleCollision(Wall& wall)
{}

void SuperGift::handleCollision(Pacman& pacman)
{
	this->m_isDisposed = true;
	this->setAteSuperGift(true);
}
void SuperGift::handleCollision(SuperPacman& superPacman)
{
	this->m_isDisposed = true;
	this->setAteSuperGift(true);
	this->m_objSprite.setTexture(*Textures::instance().getObjectTexture(superPac));
}
/*Ghost will handle its own collision*/
void SuperGift::handleCollision(Ghost& ghost)
{
}

void SuperGift::handleCollision(Key& Key)
{}

void SuperGift::handleCollision(Gate& gate)
{

}

void SuperGift::handleCollision(Food& food)
{
}

void SuperGift::handleCollision(TimeGift& gift)
{
}

void SuperGift::handleCollision(LifeGift& gift)
{
}

void SuperGift::handleCollision(FreezeGift& gift)
{
}

void SuperGift::handleCollision(SuperGift& gift)
{
}