#pragma once
// 상속을 표현하는 용어
// Parent - Child
// Base   - Derived
// Super  - Sub

// 상속을 왜 사용했는가? 최적화 하기 위해서. 클래스 멤버 구현을 할 때 반복 되는 부분을 줄이려고
// 객체 안의 객체를 표현하기 위한 방법 중 하나다. (구성 Composition)
// 둘 중에 무엇을 사용해야 되는가? A is B 방식(A는B다), A has B(A는 B를 소유한다) 방식
// 상속 - 반드시 가지고 있어야 되는 정보
// 구성 - 가지고 있을 수도 있고 아닐 수도 있는 정보

// 다형성. 모습은 같지만 다른 기능을 실행 할 수 있게 하는 것.(함수, 연산자 오버로딩)
// 컴파일(compile)  - 함수, 연산자 오버로딩(프로그램 시작 전 컴파일 단게에서 체크)
// 런타임(run-time) - virtual. 가상 함수

// 다형성을 썼을 때의 장점이 있는가? if-else if-else... 표현식을 간결화 할 수 있다.

#include <iostream>
#include "Idisplayable.h"

using namespace std;

class Base : public Idisplayable
{
	int a;

public:
	virtual	void Display() const override // virtual : 내가 상속 시킨 모든 클래스를 확인하과 동일한 함수가 있다면 자식 클래스의 함수를 사용한다.
	{
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base
{
	Base* base;

public:
	void Display() const override // virtual 키워드를 사용했을 때 자식 클래스에 동일한 이름의 함수가 없다면 부모클래스의 함수를 실행한다.
	{                       // override : 자식 클래스에 동일한 이름의 함수가 없다면 오류를 발생 시킨다.(부모 클래스 함수 사용 X)
		cout << "I'm Derived" << endl;
	}
};

void Example();
void Example2();
void Example4();