#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

// 생성자 : 객체의 데이터(속성)를 초기화 하기 위한 함수(문법)

// deepCopy 기능 구현하기 : 객체 간의 대입을 할 때 (복제) 주소는 복제가 안된다. 주소는 동적 할당을 해서 넘겨줘야 한다.

#define DEFAULT_MONEY 10000

class Person
{
private:
	// 속성(attribute)
	int money;
	int age;
	string name;
	string home;
	char* symbol;

public:
	Person() = default; // 생성자 - 자기자신을 초기화, 클래스와 같은 이름을 사용
	Person(int _age, string _name, string _home) : age(_age), name(_name), home(_home), money(DEFAULT_MONEY) {} // 각 정보를 밖에서 가져오겠다.
	Person(int _money, int _age, string _name, string _home) : money(_money), age(_age), name(_name), home(_home) {}
	Person(int _money, int _age, string _name, string _home, const char* _symbol) : money(_money), age(_age), name(_name), home(_home)
	{
		symbol = new char[100];
		strcpy(symbol, _symbol);
	}
	// 소멸자 - 생성자를 종료
	~Person()
	{
		cout << "소멸자 호출" << endl;
		delete[] symbol;
	}

	// 기능(method)
	void ToString()
	{
		cout << "나이 : " << age << endl;
		cout << "이름 : " << name << endl;
		cout << "거주지 : " << home << endl;
		cout << "소지금 : " << money << "원" << endl;
		cout << "상징 : " << symbol << endl;
	}
};

#endif