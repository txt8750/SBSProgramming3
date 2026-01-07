#pragma once
#include <string>
#include <iostream>

using namespace std;

enum class RoomObjectType {
	BATTLE, TREASURE, REST
};

class GameObject
{
protected:
	int id;
	RoomObjectType r_TYPE;
	// int instanceId;

public:
	GameObject(int _id, RoomObjectType TYPE);

	void SetRoomType(RoomObjectType r) { r_TYPE = r; }
};

class BattleObject : public GameObject
{
protected:
	int hp;
	int atk;
public:

	BattleObject(int _id, RoomObjectType TYPE, int _hp, int _atk) : GameObject(_id, TYPE), hp(_hp), atk(_atk) {}

	void Damage(int amount);
	bool IsDeath();

	virtual void Attack(BattleObject* other) = 0;
};

class TreasureObject : public GameObject
{
protected:
	int gold;
	string item;
public:

	TreasureObject(int _id, RoomObjectType TYPE, int _gold , string _item ) : GameObject(_id, TYPE), gold(_gold), item(_item) {}

	void GetTreasure();

	virtual void Attack(BattleObject* other) = 0;
};

// 엑셀 시트
// 몬스터 (전투) + (드랍) + (스킬)
// 고블린 클래스. 고유한 몬스터?
// 고블린 3마리랑 전투. (A) = 1 B = 2 C = 3...
// 아이템. 집행검 A()    B

