#include "Monster.h"

// delegate(위임) 생성자
// 매개변수가 몇개든 모든 생성자는 하나의 생성자 코드로만 구현할 수 있다.

Monster::Monster() : Monster{"이름없음", 0, 0, "정의되지 않음", BattleType::Undefined, 0}
{
}

Monster::Monster(string _name, int _hp, double _evasion, string _type, BattleType _enum_type, int _speed)
	: name(_name), hp(_hp), evasion(_evasion), type(_type), enum_type(_enum_type), speed(_speed)
{
	// 포인터 동적할당
	iptr = new int;
}

Monster::Monster(const Monster& other) : Monster{other.name,other.hp,other.evasion,other.type,other.enum_type,other.speed}
{
	cout << "복제 생성자" << endl;
	*iptr = *other.iptr;
}

Monster::~Monster()
{
	delete iptr;
}

void Monster::SetPtrValue(int value)
{
	*iptr = value;
}

void Monster::PrintData()
{
	cout << name << endl;
}

Monster::Monster(Monster&& rhs) noexcept : name(rhs.name), hp(rhs.hp), evasion(rhs.evasion), type(rhs.type), enum_type(rhs.enum_type), speed(rhs.speed)
{
	cout << "이동 생성자" << endl;
	iptr = rhs.iptr;
	rhs.iptr = nullptr;
}
