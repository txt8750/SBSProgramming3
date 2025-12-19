#include "Pos.h"

Pos::Pos() : Pos(0, 0) {}

Pos::Pos(int x, int y) : x(x), y(y) {}

Pos::Pos(const Pos& other) : x(other.x), y(other.y) {}

Pos::Pos(Pos&& rhs) noexcept = default; //포인터가 없을 때는 default로 선언

Pos::~Pos() = default; // 포인터가 없을 때는 default로 선언(동적할당이 없음)

bool Pos::operator==(const Pos& other)
{
	// p2 == p3 식에서 x는 p2.x , other.x는 p3.x로 나타낸다
	return x == other.x && y == other.y;
}

bool Pos::operator!=(const Pos& other)
{
	return !(*this == other);
}

Pos Pos::operator=(const Pos& other)
{
	if (this == &other)
	{
		return *this;
	}
	x = other.x;
	y = other.y;
	return *this;
}

ostream& operator<<(ostream& os, const Pos& pos)
{
	// << 뒤에오는 여러 타입을 출력
	os << "[x : " << pos.x << ", y : " << pos.y << "]" << endl;
	return os; // os에 저장되어있는 정보(os<<뒤에 있는 모든 정보)를 반환하여 출력
}

istream& operator>>(istream& is, Pos& pos)
{
	int x = 0, y = 0;
	cout << "x 좌표의 값 : ";
	is >> x;
	//is >> pos.x;
	cout << "y 좌표의 값 : ";
	is >> y;
	//is >> pos.y;

	pos = Pos{ x,y };
	return is;
}

void Pos::Move(int x, int y)
{
	this->x += x;
	this->y += y;
}

void Pos::Teleport(Pos* other_pos)
{
	x = other_pos->x;
	y = other_pos->y;
}

