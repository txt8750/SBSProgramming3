#include "GameObject.h"

GameObject::GameObject(int _id, RoomObjectType TYPE) : id(_id), r_TYPE(TYPE)
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

void TreasureObject::GetTreasure()
{
	cout << item << "È¹µæÇß½À´Ï´Ù." << endl;
	cout << gold << "À»(¸¦) È¹µæÇß½À´Ï´Ù." << endl;
}
