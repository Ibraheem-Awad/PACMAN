#pragma once
#include "UnmovableObject.h"
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Pacman.h"
#include "SuperPacman.h"
#include "Ghost.h"

/* The Gate class is in charge of the gate object. 
 * The gate can be opened with a 
 , which can only be obtained by the thief. */
class Gate : public UnmovableObject
{
public:
	// C-tor and d-tor.
	using UnmovableObject::UnmovableObject;
	~Gate() override;

	/* Collision handlers. */
	virtual void handleCollision(GameObject& object) override;
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Pacman& pacman) override;
	virtual void handleCollision(SuperPacman& superPacman) override;
	virtual void handleCollision(Ghost& ghost) override;
	virtual void handleCollision(Key& Key) override;
	virtual void handleCollision(Gate& Gate) override;
	virtual void handleCollision(Food& food) override;
	virtual void handleCollision(TimeGift& gift) override;
	virtual void handleCollision(LifeGift& gift) override;
	virtual void handleCollision(FreezeGift& gift) override;
	virtual void handleCollision(SuperGift& gift) override;

};