#pragma once
#include "UnmovableObject.h"
#include <SFML/Graphics.hpp>
/* The Key class is in charge of the key object.
 * The key can be appear randomly and is also dropped by orcs.
 * The key can be used to open a gate. */
class Food : public UnmovableObject
{
public:
	// C-tor and d-tor.
	using UnmovableObject::UnmovableObject;
	~Food() override;

	/* Collision handlers. */
	virtual void handleCollision(GameObject& object) override;
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Pacman& pacman) override;
	virtual void handleCollision(SuperPacman& superPacman) override;
	virtual void handleCollision(Ghost& ghost) override;
	virtual void handleCollision(Key& key) override;
	virtual void handleCollision(Gate& gate) override;
	virtual void handleCollision(Food& food) override;
	virtual void handleCollision(TimeGift& gift) override;
	virtual void handleCollision(LifeGift& gift) override;
	virtual void handleCollision(FreezeGift& gift) override;
	virtual void handleCollision(SuperGift& gift) override;
};