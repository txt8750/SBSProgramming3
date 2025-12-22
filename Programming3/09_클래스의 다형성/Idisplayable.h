#pragma once

// 순수 가상 함수
// 문법 : virtual 키워드를 붙인 함수 뒤에 = 0;
// 개념 : 구현을 자식에게 위임하는 문법
// 자기 자신은 아예 사용을 못함

// 인터페이스 : (공격클래스)-> 인터페이스 <- (유닛)
// 유닛 - 추상적인 개념. has(공격한다 기능)
// 저글링, 오버로드, 드론
// I를 붙여서 인터페이스 임을 알리자.

#include <iostream>
#include <string>

using namespace std;

class Idisplayable
{
public:
	virtual void Display() const = 0;
};

// 테란 저그 프로토스 -> 어떻게 표현할 것 인가?

class Unit : public Idisplayable
{
public:
	// Idisplayable을(를) 통해 상속됨
	void Display() const override;
};

void Example3(); //pure virtual function



class Tribe
{
	// 종족 마다 다른 특징을 공통으로 표현하게 구성.
	string tribe;
public:
	// 저그 : 체력 회복
	// 프로토스 : 실드
	// 테란 : 수리가능
};

class Terran : public Tribe
{
	Tribe* terran;
};

class Zerg : public Tribe
{
	Tribe* terran;
};

class Protoss : public Tribe
{
	Tribe* Protoss;
};