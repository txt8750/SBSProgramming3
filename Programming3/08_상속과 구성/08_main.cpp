#include "Player.h"
#include "Monster.h"
#include "Moveable.h"

// 중복되는 것들은 하나로 표현하자.
// 정적 라이브러리 .lib

// 데이터 구조를 확장하기 위해서 클래스 안에 클래스를 넣으면 된다.

// 상속(Inheritance) : 내가 가진 모든 것을 자식에게 물려주겠다.
// 내가 가진 모든 것이 공통으로 반복된다면 이것을 어떻게 한번만 처리할 수 있을까?

// 구성(Composition) : 상속이 아닌 경우에 객체를 추가할 때 사용한다.

using namespace std;

int main() {
	Monster m1;
	m1.DisplayPos();
	Player p1;
	p1.DisplayPos();

	Moveable mov;
	Flyable fly(3);
	fly.Fly(2, 3);
	fly.DisplayPos();

	mov.Move(2,2);
	mov.DisplayPos();
	fly.Move(2,2);
	fly.DisplayPos();
	// fly 자식 클래스는 Move() 함수를 소유하고 있다. 부모 클래스의 Move(int x, int y)

	cout << "상속된 클래스 멤버 함수 재사용하기." << endl; // 부모클래스::함수이름();
	Moveable* movptr = new Moveable;
	Flyable* flyptr = new Flyable(3);

	movptr->Move(1, 1);
	movptr->DisplayPos();
	flyptr->Move(3, 3);
	flyptr->DisplayPos();

	cout << "클래스의 다형성" << endl;
	delete movptr;
	delete flyptr;
	
	Moveable* ffptr = new Flyable(3); // 부모는 자식을 가리킬 수 있다.
	Moveable* mmptr = new Moveable;
	ffptr->Move(1, 1);
	mmptr->Move(1, 1);
	ffptr->DisplayPos();
	mmptr->DisplayPos();
	// 기본적으로 Movable*로 선언 되어있어서 Moveable의 Move함수가 실행됨.
	// Moveable::Move()함수의 헤더에 virtual 키워드를 붙이면 Flyable의 Move함수로 실행됨.

	// Moveable 객체. Fly, Roll, Crawl
	// Moveable 객체를 베이스로 자식 객체를 만들어서 구현

	// 다형성 코드를 사용할 때의 주의사항

}