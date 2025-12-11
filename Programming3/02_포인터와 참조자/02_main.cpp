#include <iostream> // std::cout, std::endl 등 입출력 헤더
#include <cstdio>   // cpp 방식의 호출 (c언어에서 사용했던 라이브러리를 사용하고 싶을 때는 cXXXX 로 호출
//#include <stdio.h>  // c언어 방식의 호출
#include <strstream>

using namespace std;

// 포인터 : 주소를 저장하는 변수
// (1) cpp 방식의 변수 선언.
// (2) 포인터의 동작 할당 변경 사항
// (3) 참조자

void Myswap(int& a, int& b) // 매개변수에 &을 넣으면? 참조자가 된다.
{
    int temp = b;
    b = a;
    a = temp;
}
void Myswap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int& RefExample(int& mainRef)
{
    int temp = ++mainRef;
    return temp;
}

struct Pos {
    int x;
    int y;
};

void changePos(Pos& pos)
{
    pos.x++;
    pos.y++;
}

// 포인터를 대체 할 수 있는가?
// 참조자로는 표현할 수 없는 내용이 있다. - 참조자가 NULL이 될 수 없다.
// 
// 포인터를 사용하는 이유?
// 함수 안에서 데이터를 변경할 수 있게 한다.
// 효율적으로 데이터를 전달하고 사용할 수 있다.

void RefExample2(int*& makePtr) // 참조자를 이용한 함수는 반드시 없는 경우가 없어야 한다.
{
    if (makePtr == nullptr)
    {
        throw "참조자는 null이 될 수 없습니다.";
    }
    int* tempIntPtr{};
    tempIntPtr = new int;
}

/*
*  1. 포인터를 사용하는 이유를 정리
*  2. 참조자를 사용할때의 주의 사항
*  3. 포인터와 참조자를 같이 사용해야하는 이유
*/

// 참조자를 이용해서 값을 변경하는 예제를 구현해보세요
// 참조자를 이용해서 값을 변경하지 않는 예제를 구현해보세요

struct Player
{
    int HP;
    int damage;
};

void Attack(Player& player)
{
    player.HP -= player.damage;
}

int main()
{
	cout << "2강 포인터와 참조자\n" << endl;
	// ends : 출력 버퍼가 C문자열로 처리되기 위해 NULL종료 되어야하는 경우 사용 

    int a = 10.5;   // c언어 방식의 변수 초기화
    int a2(20.5);   // cpp방식의 변수 초기화 -> 선언한 자료형과 일치 하지않는경우 선언한 자료형으로 자동 변환
    int a3{ 30 }; // cpp방식의 변수 초기화2 -> 선언한 자료형과 일치 하지않는경우 에러 발생
    cout << a << " " << a2 << " " << a3 << " " << endl;

    int* a_ptr = &a;
    int* a2_ptr{};
    int* a3_ptr{ nullptr };

    cout << a_ptr << endl;
    cout << a2_ptr << endl;
    cout << a3_ptr << endl;

    cout << "\n2-2 nullptr 주소에 주소 생성하기(런타임, 동적할당)\n" << endl;

    // malloc(sizeof(int));
    new char; // -> malloc()함수가 new 자료형 으로 변경
    a2_ptr = new int;
    cout << a2_ptr << endl;
    *a2_ptr = 10;
    cout << *a2_ptr << endl;

    //free(malloc(sizeof(char) * 10));
    delete a2_ptr; // 동적할당 한 변수를 delete 변수명 으로 해제
    cout << a2_ptr << endl;

    // 스마트 포인터 -> 포인터 할당 후 메모리 누수가 문제가 된다.(휴먼에러)
    // 동적할당 시 자동으로 해당 메모리를 해제해주는 기능

    cout << "\n2-3 swap함수 예제(참조자)\n" << endl;
    int b1(3);
    int b2(5);
    cin >> b1; // std::cin >> 변수명 -> 입력함수
    cin >> b2;
    int* b1ptr(&b1);
    int* b2ptr(&b2);
    Myswap(b1, b2);
    cout << "값이 매개변수인 함수(참조자 사용)" << endl;
    cout << "b1의 값 : " << b1 << endl;
    cout << "b2의 값 : " << b2 << endl;

    Myswap(b1ptr, b2ptr);
    cout << "포인터가 매개변수인 함수" << endl;
    cout << "b1의 값 : " << b1 << endl;
    cout << "b2의 값 : " << b2 << endl;

    // 참조자가 어떤 원리일까?

    cout << "\n2-4 참조자" << endl;
    // 선언 방법
    int& aRef = a; // 자료형 뒤에 &를 붙여야하고 반드시 초기화를 해줘야한다. 단, 초기화할때 값이 아닌 이미 만들어진 변수로 초기화를 한다.
                   // a라는 변수에 aRef라는 별명을 붙인 셈. a와aRef는 동일한 것으로 생각하면 됨.
                   // 니 이름은 인쟈부터 춘식이여 느낌.
    int* c_ptr{};
    c_ptr = new int;
    cout << c_ptr << endl;
    int*& c_ptrRef = c_ptr; // 참조자로 생성
    delete c_ptr;
    cout << c_ptr << endl;
    cout << c_ptrRef << endl; // c_ptr과 c_ptrRef가 같은 주소를 가리킨다.

    int* c2_ptr{};
    c2_ptr = new int;
    int* c2_ptr2 = c2_ptr; // 일반 포인터로 생성
    cout << c2_ptr << endl;
    delete c2_ptr;  // 할당된 주소를 날림
    cout << c2_ptr << endl; // 원본은 주소가 날라갔지만
    cout << c2_ptr2 << endl; // 얘는 주소가 있음

    // 포인터와 참조자의 차이
    // 포인터 : 변수의 주소값을 복제한다. -> 원본 주소가 변경되더라도 포인터 변수가 가지고있는 주소는 그대로
    // 참조자 : 변수의 주소값을 따라한다. -> 원본 주소가 변경되면 따라서 변경 됨.

    // 참조자 사용 시 주의사항
    // 1. 참조자는 선언과 동시에 초기화를 해줘야 한다.
    /*const int& myRef = 10;*/

    // 2. 함수에서 반환하는 값이 소멸되지 않도록 해야한다.
    
    int mainNumber = 10;
    int& refValue = RefExample(mainNumber); // refValue RefExample 함수안에 있는 temp의 별명
    cout << mainNumber << endl;
    cout << refValue << endl; // 컴파일러가 Undefined 정의 되지 않은 코드는 알아서 수정하도록 함.
                              // dangling, 임시 객체

    cout << "\n에제1) 참조자를 이용하여 Pos값을 변경해보자" << endl;
    Pos mypos{};
    mypos.x = 10;
    mypos.y = 20;
    changePos(mypos);

    cout << "X : " << mypos.x << endl;
    cout << "Y : " << mypos.y << endl;

    cout << "\n에제2) 참조자를 이용하여 HP값을 변경해보자" << endl;
    Player player{};
    player.HP = 100;
    player.damage = 10;
    cout << "전투 전 HP : " << player.HP << endl;
    Attack(player);
    cout << "전투 후 HP : " << player.HP << endl;

    
    
}

/*
int main()
{
    std::ostrstream oss;
    oss << "샘플 텍스트: " << 42 << ends;
    std::printf("%s \n ", oss.str()); oss.freeze
    (false); // 메모리 해제 활성화
}
*/