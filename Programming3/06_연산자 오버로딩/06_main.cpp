#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;

// std::string 클래스를 직접 구현하기

int main()
{
	cout << "string 클래스를 이해해보자" << endl;
	string str = "Hello world";
	const char* str2 = "안녕하세요"; // 주소. 안에 있는 값을 변경하지 못하게 막은 주소
	str = "아무 말";  // string으로 선언한 문자열은 변경 가능
	cout << str << endl;
	cout << str2 << endl;

	// string 타입은 선언 후에 rvalue타입을 대입할 수 있다.
	// 왜 이게 가능한지 구현을 통해서 알아보자.

	cout << "\nMyString 객체 구현" << endl;
	MyString s1;
	MyString s2("Hello World!");

	MyString s3(s2); // copy
	MyString s4(move(s3)); // move. s3->str 은 null, s4는 s3의 str을 갖는다.

	cout << "\nMyString 연산자를 이용한 기능 구현(연산자 오버로딩)" << endl;
	
	MyString s5;
	s5 = s2; // cpoy assignment ("=" 연산자 오버로딩해서 구현)
	s1.CopyAssignment("이순신");
	//s5 = move(s1);

	/*string str3 = "홍길동";
	str = "My Name : " + str3;
	cout << str << endl;*/
	
	s5 = s1 + "홍길동";

	s5 = "이름은 : " + s1;

	cout << s5 << "\n다른 객체의 정보 : "<< s1 << endl;
}