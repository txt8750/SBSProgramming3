#include "Monster.h"

Monster::Monster(int _id, int _hp, int _atk, string _name) : BattleObject(_id, _hp, _atk), name(_name) {}
Monster::Monster() : Monster{ 1002, 100, 10, "이름없음" } {}



void Monster::Attack(BattleObject* other)
{
	cout << "플레이어에게 " << atk << "만큼 데미지를 주었습니다!" << endl;
	other->Damage(atk);
}