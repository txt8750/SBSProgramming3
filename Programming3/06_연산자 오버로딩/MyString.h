#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // strcpy, strcom, strlen

using namespace std;

class MyString
{
	friend ostream& operator<<(ostream& os, const MyString& obj);
	friend MyString operator+(const MyString& lhs, const MyString& rhs); // +연산자를 재정의
private:
	char* str;	
public:
	// 생성자 및 소멸자
	MyString(); // 기본 생성자
	MyString(const char* source); // overload constructor
	MyString(const MyString& other); // 복사 생성자
	MyString(MyString&& rhs) noexcept; // 이동 생성자
	~MyString();  // 소멸자
	// 클래스 안에 생성자 ~ 소멸자 까지 만드는게 템플릿임
	
	// 연산자 오버로딩
	MyString operator=(const MyString& other);
	MyString operator=(MyString&& rhs) noexcept;
	// MyString operator+(const MyString& other);

	// 멤버 함수로 구현
	MyString CopyAssignment(const MyString& other);

};

