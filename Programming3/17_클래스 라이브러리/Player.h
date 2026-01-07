#pragma once
#include "GameObject.h"
#include <iostream>

class Player : public BattleObject
{
public:

	Player(int _id, RoomObjectType TYPE, int _hp, int _atk);
	Player();

	void Attack(BattleObject* other) override;
};
