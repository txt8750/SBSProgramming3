#include "Base.h"

void Example()
{
	cout << "\nExample1 예제" << endl;
	Base base;
	base.Display();
	Derived der;
	der.Display();
}

 // Base : Character
 // Derived : 직업(전사, 마법사, 도적)
void Example2()
{ 
	cout << "\nExample2 예제" << endl;
	Base* baseptr = new Base;
	Derived* derptr = new Derived;
	Base* someptr = new Derived; // Base로 선언 되어 Base에 있는 오브젝트 사용
	// Base의 함수의 앞에 virtual을 붙여주면 자식 클래스의 함수로 간다.
	baseptr->Display();
	derptr->Display();
	someptr->Display();
}

// 다형성을 왜 쓰는가?
// interface 사용하는 것.
void Example4()
{
	cout << "\nExample4 예제" << endl;

	//Idisplayable* all_display[3];   // 배열, vector
	Base* base_ptr = new Base;
	Base* d_ptr = new Derived;
	//Unit* unit_ptr = new Unit;
	
	base_ptr->Display();
	d_ptr->Display();
	//unit_ptr->Display();
}
