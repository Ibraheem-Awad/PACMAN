#pragma once
#include "Gifts.h"
#include "Macros.h"
#include "Pacman.h"
#include "Ghost.h"

/* FreezeGift is in charge of the time gift object.
 * The time gift can either give time or take time. */
class LifeGift : public Gifts
{
public:
	using Gifts::Gifts;

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