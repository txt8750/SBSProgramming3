#include "Account.h"
#include <iostream>

// delegate(위임) 생성자

Account::Account() : Account{ default_money } {}

Account::Account(int _money) : money(_money)
{
	iptr = new int; // 복제, 이동 생성자를 사용하기위한 포인터 변수를 동적할당
}

Account::Account(const Account & other) : Account{other.money}
{
	cout << "복제 생성자 호출" << endl;
	*iptr = *other.iptr;
}

Account::Account(Account&& rhs) noexcept : money(rhs.money)
{
	cout << "이동 생성자 호출" << endl;
	//delete iptr; //기존 자신의 iptr 주소를 삭제
	iptr = rhs.iptr; // 외부에서 가져온 주소를 자신의 주소로 넘겨준다.
	rhs.iptr = nullptr; // 외부의 주소를 nullptr로 지워버림 -> 주소 이동 완료!
}

// 소멸자
Account::~Account()
{
	delete iptr; // 동적할당 된 포인터변수 해제
}

void Account::WithDraw(int amount)
{
	int temp = 0;
	if (GetMoney() < amount)
	{
		cout << "잔고 보다 인출할 금액이 많습니다" << endl;
		temp = GetMoney();
		return;
	}
	temp = GetMoney() - amount;
	SetMoney(temp);
}

void Account::Deposit(int amount)
{
	if (amount < 0)
	{
		cout << "음수 금액을 예금할 수 없습니다." << endl;
		return;
	}
	int temp = GetMoney() + amount; // 내 계좌에 입금 될 값
	SetMoney(temp);
}
