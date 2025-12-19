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

	// virtual : 내가 상속하고있는 클래스에서 형태를 재정의하겠다.
	virtual void Move(int x, int y);
	void Teleport(Pos* other_pos);

	Pos& GetPos() const;  // const Player -> 함수 실행
	void DisplayPos() const;
};

// A is B 관계 : Moveable 은 Flyable 인가요? 상속(Inheritance)
// A has B 관계 : Monster 은 Monster을 갖고있나요? 구성(Composition)

// 상속 구문 작성 시 class Classname : 접근지정자 부모Classname
// 접근 지정자 구분
// 1. public : 부모클래스에서 항목을 가져올때 private는 private, public은 public으로 그대로 가져와라
// 2. private : 부모클래스에서 항목을 가져올때 모든 항목을 private로 가져와라
// 3. protected : 부모클래스에서 항목을 상속받은 자식 클래스에서만 공개적으로 사용할 수 있다.
//                public -> protected

// 클래스 안에서의 접근 지정자
// 1. public : 어디서든 해당 오브젝트, 함수 등을 사용가능
// 2. private : 현재 객체 안에서만 오브젝트, 함수 등을 사용가능
// 3. protected : 현재 객체와 상속받은 자식객체만 오브젝트, 함수 등을 사용가능.

// 다형성(polymorphism) : 형태는 같지만 다양한 의미를 소유하고 있는 상태
// Run Time     : 프로그램 실행 도중에 함수가 변화한다. 클래스 상속의 다형성
// Compile Time : 함수 오버로딩, 연산자 오버로딩
class Flyable : public Moveable // 접근지정자를 지정하지 않는 경우 private로 상속
{
private:  // Fly는 이동하는 거리보다 더 많이 움직인다 라는 개념을 추가해보자
	int fly_weight;

public:
	Flyable(int _fly_weight);
	~Flyable();

	void Move(int x, int y) override;
	// override : override로 선언된 멤버함수는 기본클래스 멤버를 재정의하지 않는다.
	void Fly(int x, int y);
};
