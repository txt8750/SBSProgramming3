

#include <memory>
#include <iostream>
#include <vector>
#include <string>

#include "SmartPointer.h"

// STL : Standard Template Library
// STL 사용이 능숙한 분 우대.

using namespace std;

template<typename T>
class A {
private:
	T value;
public:
	A(T a) : value(a) {}
	int operator+(const A&)
	{
		return 10;
	}
	T GetValue() { return value; }
};

class Item
{
private:
	string name;
public:
	Item(string n) : name(n) {}

	void display() { cout << "아이템 이름 : " << name << endl; }
};

template <typename T>
T Add(T a, T b)
{
	return a + b;
}
//// ---------------------------------------
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//double Add(double a, double b)
//{
//	return a + b;
//}
//
//A Add(A a, A b) {
//	return a;
//
//}
//// ---------------------------------------

enum class moveType
{
	DASH, JUMP, RUN
};
int main()
{
	unique_ptr<int> p1;
	vector<int> v1;
	static_cast<int>(0.25);

	// template 문법들을 사용하고 있었다.
	// 템플릿이란 무엇인가? 왜 쓰는가? 사용하는 법.
	// 기능을 비슷하게 가져온다. 데이터의 형태에 따라서 사용할 수 도 있고 못할 수 도 있다.

	double n1 = Add<int>(1.1, 3.1);
	cout << n1 << endl;

	A<int> a(1);		// A<int> 객체
	A<double> b(1.1);	// A<double> 객체
	A<int> c(2);
	cout << a + c << endl;
	cout << a.GetValue() << endl;
	cout << b.GetValue() << endl;
	cout << c.GetValue() << endl;

	cout << "\nTemplate 사용 예제" << endl;
	// int 배열
	vector<int> intArray = { 0,1,2,3,4,5 };
	for (auto& i : intArray)
	{
		i++;
		cout << i << " ";
	}
	cout << endl;

	vector<Item> inventory;
	Item i1("아이템1");
	Item i2("아이템2");
	inventory.push_back(i1);
	inventory.push_back(i2);
	for (auto& i : inventory)
	{
		i.display();
	}

	int nn1 = static_cast<int>(moveType::DASH);
	moveType m_type = static_cast<moveType>(1);

	// 스마트 포인터 : delete를 자동으로 해주는 객체 (3종류. unique, shared, weak)
	int* iptr1;
	{
		unique_ptr<int> my_unique_p1(new int);
		iptr1 = new int;
		*iptr1 = 10;

		*my_unique_p1 = 20; // new int와 똑같음
		cout << "raw pointer : " << *iptr1 << endl;
		cout << my_unique_p1.get() << endl;
		delete iptr1;
	}

	//cout << "smart pointer : " << *my_unique_p1 << endl;

	Example1();
	Example2();
	Example3();

}