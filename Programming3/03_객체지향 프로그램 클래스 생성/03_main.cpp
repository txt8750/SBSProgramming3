#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include "Maple.h"
#include <cstring>
using namespace std;

// c VS cpp
// c언어 - 절차 지향 언어 - 함수들로 구성된 프로그램
// cpp - 객체 지향 언어 - 객체들로 구성된 프로그램

// c언어로 프로그래밍을 하면서 겪었던 문제점
// 구조체 안의 데이터를 추가해서 사용해야 한다. - 프로그래밍의 확장이 어려움
// 모든 객체의 정보를 알고 있어야 함수를 다룰 수있다.
// ※ 프로그램이 커지면 커질수록 다루기가 어려워진다.

// 대입 연산자로 데이터를 초기화 하고있다.
// 참조 타입, 주소를 사용하는 데이터를 대입하면 어떤 일이 일어날까?
// 주소 데이터를 대입한 후에 하나의 객체를 지워보자
// 이것을 해결하기 위한 방법?

struct Monster
{
	char* name;
	int id;
	int hp;
};

int main()
{
	//cout << "3강 시작\n" << endl;

	//Person p1{};
	//Person p2(1000, 29, "김민규", "부산"); // 클래스 선언 및 안의 값 초기화
	//p1.ToString();
	//cout << "" << endl;
	//p2.ToString();

	//Person p3(2000, 20, "홍길동", "서울");
	//cout << "" << endl;
	//p3.ToString();

	//Monster mon;
	//mon.id = 1;
	//mon.hp = 10;
	//mon.name = new char[100];
	//strcpy(mon.name, "오크");
	//cout << mon.name << endl;
	//

	//Monster mon2;
	//mon2 = mon;  // 이렇게하면 mon의 정보가 mon2에 복사된다.
	//             // 단 주소값을 복사하는 경우 mon과 mon2 둘다 같은 주소를 가리킴
	//delete[] mon.name; // mon.name의 주소를 해제해버리면 mon2에서도 가리키고있던 주소안의 값이 사라지기 때문에 쓰레기값이 출력됨 
	//cout << mon2.name << endl;
	//cout << mon2.id << endl;
	//cout << mon2.hp << endl;
	//// 얕은 복사(shallow copy) : 동일한 곳을 바라보고있는 상태 독립적이지 않음
	//// 깊은 복사(deep copy) : 완전 복제, 서로 독립적인 상태

	//Person p4(3000, 34, "박박박", "대전", "노잼");

	//// 직접 클래스를 동적할당 해보자.
	//Person* p_ptr = new Person(3000, 34, "김김김", "대전", "노잼");

	Maple Magnus("매그너스", "폭군의 왕좌", 130, 6000000000, 100000, 5300000, 22000, 24000);
	Magnus.showBossStat();

}