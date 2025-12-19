#include "Moveable.h"

Moveable::Moveable()
{
	cout << "Moveable 객체 생성" << endl;
	this->pos = new Pos;
}

Moveable::Moveable(Pos* pos)
{
	this->pos = new Pos;
	*(this->pos) = *pos;
}

Moveable::Moveable(const Moveable& other_pos)
{
}

Moveable::Moveable(Moveable&& rhs_pos)
{
}

Moveable::~Moveable()
{
	delete pos;
	cout << " Moveable 소멸자 호출" << endl;
}

void Moveable::Move(int x, int y)
{
	cout << "Moveable의 이동이다." << endl;
	pos->Move(x, y);
}

void Moveable::Teleport(Pos* other_pos)
{
	pos->Teleport(other_pos);
}

Pos& Moveable::GetPos() const
{
	return *pos;
}

void Moveable::DisplayPos() const
{
	cout << "좌표 : " << GetPos() << endl;
}

// : 부모클래스의 생성자, 자식클래스에서 추가된 오브젝트를 위임 시킴
Flyable::Flyable(int _fly_weight) : Moveable(), fly_weight(_fly_weight)
{
	cout << "Flyable 객체 생성" << endl;
}

Flyable::~Flyable()
{
	cout << "Flyable 소멸자 호출" << endl;
}

void Flyable::Fly(int x, int y)
{
	Moveable::Move(x * fly_weight, y * fly_weight);
}

void Flyable::Move(int x, int y)
{
	cout << "Flyable의 이동이다." << endl;
	Fly(x, y);
}