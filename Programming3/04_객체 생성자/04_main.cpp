#include "Monster.h"

using namespace std;

/*
*  Object orient Programming(객체 지향 프로그래밍, OOP)
*  
*/

// const Monster& mon = mon2;
// 몬스터의 기본값을 전달해서 새로운 객체만들기

// 복제 (deep copy)
//  1. 사용자 정의 클래스가 raw pointer를 소유하고 있으면 new 키워드로 동적할당 해줘야한다.
//  2. 없으면? 기본 복제 생성자를 사용하면 된다.                
void Example(Monster mon)
{
	cout << "Test" << endl;
}


int main()
{
	cout << "4강 객체 생성자에 대한 이해" << endl;
	Monster mon1; // 생성자를 선언하지 않으면 기본(default) 생성자가 구현되어있다.
	Monster mon2("해골 수비병", 15, 0, "불경", BattleType::불경,0);
	mon2.SetPtrValue(10);

	Example(mon2);

	cout << " lValue vs Rvalue" << endl;

	int a = 10;
	int& aRef = a;   // Lvalue의 참조자
	int&& bRef = 10; // Rvalue의 참조자
	
	// Lvalue 타입은 값을 저장하고 변경할 수 있는 타입
	// Rvalue 타입은 값을 변경할 수 없음. 이름을 가질 수 없음.
}