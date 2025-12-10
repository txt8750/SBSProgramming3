// C언어 학습 한 상태.
// C++ 시작하기(배우기)
// C -> C++ 업그레이드 되면서 어떤 기능이 다를까?
// 새로운 언어를 사용하게 될 가능성이 높다
// C언어의 기능 -> 다른 언어에서는 어떻게 표현하고 있을까?
// Hello World를 출력 해봐라
#include "01_namespace.h"
#include "Monster.h"

// using namespace A;
using A::ShowPlayer;
using namespace std;

int main()
{

	cout << "Cpp Style" << "append" << endl;
	cout << "Hello World!" << endl;

	int num = 10;
	char a = 'a';
	double num2 = 0.1;
	cout << a << num << endl;
	cout << num2 << endl;

	A::ShowPlayer();

	cout << "\n사용자 정의 자료형을 사용하기 : Struct" << endl;

	// char name[100]; name = "슬라임"; // 주소 <- 주소
	// strcpy(monclass.name, "슬라임"); 이름을 오른쪽 이름을 왼쪽에 옮기고 싶음. 특별한 함수사용
	Monster monclass;
	monclass.name = "슬라임"; // string 문자열을 표현하는 객체
							 // c언어와 사용하는 문법이 전혀 다르다. 암기로 시작하면 머리아픔
	monclass.HP = 100;
	monclass.uid = 1;

	cout << "몬스터의 이름 : " << monclass.name << endl;
	cout << "몬스터의 체력 : " << monclass.HP << endl;
	cout << "몬스터의 UID : " << monclass.uid << endl;
}
// (1) std::cout, 새로운 문법?
//     std : namespace
//     cout : namespace안에 정의 된 코드, 함수 등을 뜻함
//     namespace로 공간을 나누고 각 공간의 코드들을 가져올 수 있음.(코드들의 이름이 동일해도 namespace로 구분)
//     스코프 연산자(::) -> 영역을 표현한다.
//     namespace 키워드 선언. namespace를 사용한다(using 키워드)
//     using namespace (이름); -> 선언 하면 namespace::를 빼고 사용할 수 있음
//         ㄴ> namespace에 속하지않은 동일한 이름의 함수가 있는 경우 오류  발생
//     using A::ShowPlayer; -> 모든 ShowPlayer 함수 중 A에있는 것만 사용하겠다.
// 
//     응용해서 using namespace std;를 선언하여
//     cout << "" << endl; 이런식으로 사용가능
// 
// 
// (2) << 이건 또 뭘까?
// 
// 
// (3) std::endl;
//     줄바꿈 : endl
//     줄바꿈 안함 : 아무것도 안적음
//     줄바꿈 안함 : ends
//     ends란? C언어용 출력 변경 장치(Cpp로만 사용할때는 사용할 일이 없다)

// C언어와 Cpp언어 변경 사항이 뭐가 있을까?
// 1. 함수 오버로딩(overloading)
//  - C언어 : 반환값 이름(...)
//  - cpp : 이름이 같더라도 인자가 다르면 다른 함수로 인식하자.
//    ex) void Plus(int a, int b);
//        void Plus(int a, int b, int c);
//        C언어에서는 위 두 함수가 똑같은걸로 처리를 하여 오류가 발생하지만
//        Cpp에서는 서로 다른 함수로 처리하여 오류가 발생하지 않는다.
// 2. C언어 struct(구조체), Cpp class(객체)

// 포인터, 참조자
//  - 사용자를 위한 문법
//  cpp 만들어진 코드가 쓰고 싶다 vs 설계 해보고 싶다
// C언어 프로젝트에서 사용한 게임 데이터를 볌용으로 사용할 수 있게 변경하기.
