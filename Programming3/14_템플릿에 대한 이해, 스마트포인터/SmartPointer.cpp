#include "SmartPointer.h"

// 몬스터.
// 클래스(drop, stat...)

void Example1()
{
	cout << "\nUnique Pointer : Unique Example" << endl;
	UEx unique;
	unique.setPointer(make_unique<int>(20));  //void setPointer(unique_ptr<int> other) 방식   
	unique.getValue();
	unique.setPointer(10);					  //void setPointer(int value) 방식
	unique.getValue();
}

void Example2()
{
	cout << "\nSmart Pointer : Shared Example" << endl;
	Sharedptr shared;
	Sharedptr shared2;
	shared.setPointer(10);
	shared2.setPointer(shared.sptr);
	shared.getValue();
	shared2.getValue();

	//

	cout << "공유 포인터 가리키고 있는 수 : " << shared.sptr.use_count() << endl;
	cout << "공유 포인터 가리키고 있는 수 : " << shared2.sptr.use_count() << endl;
	shared.sptr.reset();
	cout << "공유 포인터 가리키고 있는 수 : " << shared.sptr.use_count() << endl;
	cout << "공유 포인터 가리키고 있는 수 : " << shared2.sptr.use_count() << endl;
	// shared.getValue(); -> reset으로 아무것도 가리키지 않게 되어 실행 시 오류 발생
	shared2.getValue();
}

void Example3()
{
	cout << "\nWeak Pointer : Weak Example" << endl;

	Police p1;
	Gun gun;

	p1.myGun = make_shared<Gun>(gun);
	gun.owner = make_shared<Police>(p1);

	gun.owner.reset(); // 경찰이 총을 집어들어서 생성 되어 있던 gun 정보를 없앴다.
	p1.myGun.reset();  // 내가 가지고 있는 총의 포인터를 지우겠다.

	cout << p1.myGun.use_count() << endl;
	cout << gun.owner.use_count() << endl;
}