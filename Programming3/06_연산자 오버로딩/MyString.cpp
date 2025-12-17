#include "MyString.h"

// delegate 생성자

MyString::MyString() : str(nullptr)
{
	str = new char[1]; // 포인터 변수 동적할당
	*str = '\0';
}

MyString::MyString(const char* source) : str(nullptr)
{
	// source의 길이 만큼 char길이를 메모리에 저장하겠다.
	// NULL문자를 저장하여 리터럴문자로 표현해야 하므로 +1을 해준다.
	str = new char[strlen(source) + 1]; 
	strcpy(str, source);  // source의 데이터를 str에 복제
}

MyString::MyString(const MyString& other) : str(nullptr)
{
	str = new char[strlen(other.str) +1]; // 포인터 복사할 때 실행
	strcpy(str, other.str);
}

MyString::MyString(MyString&& rhs) noexcept : str(nullptr)
{
	str = rhs.str;  // 포인터 이동할 때 실행
	rhs.str = nullptr;
}

MyString::~MyString()
{
	delete[] str; // 동적할당 해제. 배열로 선언했으면 배열로 제거해야함. delete[] 변수명
}

MyString MyString::operator=(const MyString& other) // = 이라는 기호의 의미를 재정의
{
	if (this == &other) {
		return *this;
	}
	delete[] str;
	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);
	return *this;
}

MyString MyString::operator=(MyString&& rhs) noexcept
{
	if (this == &rhs) {
		return *this;
	}
	delete[] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

MyString MyString::CopyAssignment(const MyString& other)
{
	if (this == &other) {
		return *this;
	}
	delete[] str;
	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);
	return *this;
}

ostream& operator<<(ostream& os, const MyString& obj)
{
	os << obj.str;
	return os;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	// 새로운 문자의 길이 = this.str 길이 + other.str 길이 + NULL문자길이
	// ex) s1 + "홍길동" 이라는 식이 있다면
	//     this.str : s1, other.str : "홍길동", NULL 문자 : \0 이 된다.
	char* buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
	strcpy(buff, lhs.str); // buffer[시작 ~ A], buff에 str 값을 복사)
	strcat(buff, rhs.str); //buffer[A ~ other길이], buff의 값에 other.str값을 추가

	MyString temp(buff); // 임시 객체를 만들어서 buff의 값을 넣고 
	delete[] buff;       // buff의 메모리 해제

	return temp;
}
