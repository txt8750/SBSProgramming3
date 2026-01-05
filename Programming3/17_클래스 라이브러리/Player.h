#pragma once
#include "GameObject.h"
#include <iostream>

class Player : public BattleObject
{
public:

	Player(int _id, int _hp, int _atk);
	Player();

	void Attack(BattleObject* other) override;
};
