#pragma once
#include<iostream>
#include<cstdbool>
// struct, class : 함수를 선언하려면 클래스로 구현

using namespace std;

class Pos
{
	// friend 멤버가 아닌 녀석에게도 접근 가능
	// ostream 출력을 시켜주는 stream
	// istream 입력을 시켜주는 stream
	friend ostream& operator<<(ostream& os, const Pos& pos);
	friend istream& operator>>(istream& is, Pos& pos); //입력 받으면 값이 바뀌기 때문에 const 없이 선언
private:
	int x;
	int y;
public:
	Pos();
	Pos(int x, int y);
	Pos(const Pos& other);
	Pos(Pos&& rhs) noexcept;
	~Pos();

	// 연산자 오버로딩
	bool operator==(const Pos& other);
	bool operator!=(const Pos& other);

	Pos operator=(const Pos& other);

	// 멤버 함수
	void Move(int x, int y);
	void Teleport(Pos* other_pos);
};

