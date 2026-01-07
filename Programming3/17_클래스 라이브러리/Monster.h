#pragma once
#include <string>
#include "GameObject.h"

using namespace std;

class Monster : public BattleObject
{
private:
	string name;
public:
	int GetStrength() const { return hp + atk; }

	bool operator>(const Monster& other)
	{
		return (hp + atk) > (other.hp + other.atk);
	}
	Monster(int _id, RoomObjectType TYPE, int _hp, int _atk, string _name);
	Monster();

	void Attack(BattleObject* other);

	// 접근 지정자.
	// 생성 - 소멸자
	// 상속 - 구성
	// 스마트 포인터
};




