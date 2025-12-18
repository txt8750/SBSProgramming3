#include "Moveable.h"

Moveable::Moveable()
{
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
}

void Moveable::Move(int x, int y)
{
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
	cout << "ÁÂÇ¥ : " << GetPos() << endl;
}