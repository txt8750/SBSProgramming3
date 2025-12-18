#pragma once
#include "Pos.h"

using namespace std;
class Moveable
{
private:
	Pos* pos;
public:
	Moveable();
	Moveable(Pos* pos);
	Moveable(const Moveable& other_pos);
	Moveable(Moveable&& rhs_pos);
	~Moveable();

	void Move(int x, int y);
	void Teleport(Pos* other_pos);

	Pos& GetPos() const;  // const Player -> 함수 실행
	void DisplayPos() const;
};

