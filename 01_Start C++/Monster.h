#pragma once

// 접근 제어 지시자
// public  : 공공의, 누구나 사용할 수 있는
// private : 사적인, 숨겨진, 함부로 사용할 수 없는

// struct VS class
// 문법적인 차이가 언어마다 다르다.
// 개념,의미론적(Sementic)으로 이해를 해야함

// class로 선언한 객체는 접근제어를 지시하지않으면 기본적으로 private로 선언된다.
#ifndef MONSTER_H
#define MONSTER_H

#include <string>
using namespace std;

class Monster{
public:
	string name;	// 이름
	int HP;
	int uid;		// UID   0000_0001 몬스터 데이터
};					//       0001_0000 속성

//cpp에서는 typedef로 struct 안써도 됨.
// struct로 선언한 객체는 접근제어를 지시하지 않으면 기본적으로 public으로 선언된다.
struct MonsterStruct
{
	int a;
	int b;
};
// 끝에도 따로 선언하는 이름X

// struct를 이용해서 게임 데이터를 메인 함수에 출력하기
#endif