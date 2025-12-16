#pragma once

#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <iostream>

using namespace std;

enum class BattleType {
	불경,
	신성,
	Undefined
};

// class, struct
// 함수가 존재하면 class로 선언하라
// 함수가 필요없으면 struct로 선언하라

class Monster
{
private:
	string name;		// 몬스터이름
	int hp;				// 몬스터 HP
	double evasion;		// 몬스터 회피율
	string type;		// 몬스터 종류
	BattleType enum_type;	// enum 0 : 불경, 1 : 신성, 2 : Undefined
	int speed;			// 몬스터 속도

	int* iptr; //deep copy를 위한 예제

public:
	// 생성자
	Monster();  // no args 생성자. 기본값으로 전부 다 설정해줘.
	Monster(string _name, int _hp, double _evasion, string _type, BattleType _enum_type, int _speed);
	Monster(const Monster& other);   // copy 생성자  shallow copy, deep copy -> new 키워드로 메모리 생성 후 값 복사
	Monster(Monster&& rhs) noexcept;			 // move 생성자  

	~Monster(); // 소멸자
	// 멤버함수
	void SetPtrValue(int value);
	void PrintData();
};

#endif