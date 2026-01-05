#include "GameObject.h"

GameObject::GameObject(int _id) : id(_id)
{
}

void BattleObject::Damage(int amount)
{
	hp -= amount;
}

bool BattleObject::IsDeath()
{
	return hp <= 0;
}