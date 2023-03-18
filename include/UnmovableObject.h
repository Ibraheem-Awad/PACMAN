#pragma once
#include "GameObject.h"

/* UnmovableObject class is in charge of the unmovable objects in the game. */
class UnmovableObject : public GameObject
{
public:
	//C-tor and D-tor
	using GameObject::GameObject;
	virtual ~UnmovableObject() = default;

	/* Virtual collision handlers. */
	virtual void handleCollision(GameObject& object) = 0;
	virtual void handleCollision(Wall& wall) = 0;
	virtual void handleCollision(Pacman& pacman) = 0;
	virtual void handleCollision(SuperPacman& superPacman) = 0;
	virtual void handleCollision(Ghost& ghost) = 0;
	virtual void handleCollision(Key& Key) = 0;
	virtual void handleCollision(Gate& gate) = 0;
	virtual void handleCollision(Food& food) = 0;
	virtual void handleCollision(TimeGift& gift) = 0;
	virtual void handleCollision(LifeGift& gift) = 0;
	virtual void handleCollision(FreezeGift& gift) = 0;
	virtual void handleCollision(SuperGift& gift) = 0;
};