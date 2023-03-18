#pragma once
#include "UnmovableObject.h"

/* The Gifts class is the base class of the different gifts in the game. */
class Gifts : public UnmovableObject
{
public:
	// C-tor and d-tor.
	using UnmovableObject::UnmovableObject;
	~Gifts() {};

	// Collision handlers.
	virtual void handleCollision(GameObject& object) = 0;
	virtual void handleCollision(Wall& wall) = 0;
	virtual void handleCollision(Pacman& pacman) = 0;
	virtual void handleCollision(SuperPacman& superPacman) = 0;
	virtual void handleCollision(Ghost& ghost) = 0;
	virtual void handleCollision(Key& key) = 0;
	virtual void handleCollision(Gate& gate) = 0;
	virtual void handleCollision(Food& food) = 0;
	virtual void handleCollision(TimeGift& gift) = 0;
	virtual void handleCollision(LifeGift& gift) = 0;
	virtual void handleCollision(FreezeGift& gift) = 0;
	virtual void handleCollision(SuperGift& gift) = 0;
};
