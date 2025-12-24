#include <iostream>
#include <vector>

// for 반복문의 또 다른 사용법. cpp에서 추가 된 기능.
// 배열
// ranged loop - 끝이 어딘지 알아야한다.

using namespace std;

int main()
{
	int array2[30] = { 1,2,3,4,5,6 };
	cout << "array로 범위 기반 루프 실행" << endl;
	for (int single : array2) { // 고정 배열
		cout << single << " ";
	}
	cout << "\n" << endl;

	std::vector<int> i_vec;  // 가변 배열
	i_vec.push_back(0);
	i_vec.push_back(1);
	i_vec.push_back(2);
	i_vec.push_back(3);
	i_vec.push_back(4);
	cout << "vector로 범위 기반 루프 실행" << endl;

	cout << "i_vec의 값 출력" << endl;

	for (int i : i_vec) {
		cout << i << " ";
	}
	cout << "\n" << endl;

	cout << "auto 키워드로 범위 기반 루프 실행" << endl;
	for (auto& i : i_vec) {			// 참조자를 사용하지 않는 경우 지역변수로 인식되어 값 변경이 안됨. 참조자 사용 필요
		i += 1;
	}
	
	cout << "i_vec의 값 출력" << endl;

	for (const auto& i : i_vec) {
		cout << i << " ";
	}
	cout << "\n" << endl;

}
