#pragma once
#include "Player.h"
#include "Ghost.h"

class SuperPacman : public Player
{
public:
	using Player::Player;

	/* Collision handlers. */
	virtual void handleCollision(GameObject& object) override;
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Pacman& pacman) override;
	virtual void handleCollision(SuperPacman& superPacman) override;
	virtual void handleCollision(Ghost& ghost) override;
	virtual void handleCollision(Key& Key) override;
	virtual void handleCollision(Gate& gate) override;
	virtual void handleCollision(Food& food) override;
	virtual void handleCollision(TimeGift& gift) override;
	virtual void handleCollision(LifeGift& gift) override;
	virtual void handleCollision(FreezeGift& gift) override;
	virtual void handleCollision(SuperGift& gift) override;

	bool getKeyInfo() const
	{
		return m_gotKey;
	}

	void setKeyInfo(bool info)
	{
		this->m_gotKey = info;
	}

private:
	bool m_gotKey = false; // To save info regarding key possession.
};