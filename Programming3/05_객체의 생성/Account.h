#pragma once // 중복된 클래스가 있는경우 하나만 사용하도록 하라

using namespace std;

// 어떤 데이터를 저장해야 하는가? 멤버 변수
// 어떤 기능을 처리하는가? withdraw(출금) deposit(입금)

// 클래스랑 함께 사용하면 좋은 키워드
// Getter Setter 함수 표현

class Account
{
private:
	static constexpr int default_money = 1000;
	int money;
	int* iptr;

public:   
	Account();					// 기본 생성자 default constructor
	Account(int _money);		// 중첩 정의 생성자 overload constructor
	Account(const Account& other); // 복사 생성자 copy constructor
	Account(Account&& rhs) noexcept;	       // 이동 생성자 move constructor
	~Account();

	// Getter Setter 함수를 만드세요
	int GetMoney() const { return money; } // 함수를 const화 시키는 키워드
	void SetMoney(int _money){ money = _money; }
	
	// 기능 멤버 함수, 메소드(method)
	void WithDraw(int amount); // 돈을 출금하는 함수
	void Deposit(int amount);  // 돈을 입금하는 함수

	// 연산자 오버로딩
};