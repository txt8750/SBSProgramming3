#include "Account.h"
#include <iostream>

using namespace std;

void Example(Account account)
{
	cout << "예시" << endl;
}

int main()
{
	cout << "생성자 호출" << endl;

	Account acc; // 기본생성자
	Account acc2(10000); // 중첩 정의 생성자
	Account acc3(acc2);

	Example(std::move(acc3));  // 임시 객체로 만드는 방법

	cout << "\n Getter Setter 함수 사용 예제" << endl;

	cout << "acc 계좌의 잔금 : " << acc.GetMoney() << endl;
	acc.SetMoney(100000);
	cout << "acc 계좌의 잔금 : " << acc.GetMoney() << endl;
	cout << "\n\n\n" << endl;

	int temp = 2000;
	cout << "예금할 금액 : " << temp << endl;
	acc.Deposit(temp);
	cout << "acc 계좌의 잔금 : " << acc.GetMoney() << endl;

	int amount = 102000; // 인출할 금액
	acc.WithDraw(amount);
	cout << "인출한 금액 : " << amount << endl;
	cout << "acc 계좌의 잔금 : " << acc.GetMoney() << endl;
}