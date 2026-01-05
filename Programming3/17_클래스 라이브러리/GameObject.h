#pragma once
class GameObject
{
protected:
	int id;
	// int instanceId;

public:
	GameObject(int _id);
};

class BattleObject : public GameObject
{
protected:
	int hp;
	int atk;
public:

	BattleObject(int _id, int _hp, int _atk) : GameObject(_id), hp(_hp), atk(_atk) {}

	void Damage(int amount);
	bool IsDeath();

	virtual void Attack(BattleObject* other) = 0;
};

// 엑셀 시트
// 몬스터 (전투) + (드랍) + (스킬)
// 고블린 클래스. 고유한 몬스터?
// 고블린 3마리랑 전투. (A) = 1 B = 2 C = 3...
// 아이템. 집행검 A()    B

