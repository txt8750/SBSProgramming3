#include <iostream>
#include "Pos.h"
#include "Player.h"
#include "Monster.h"

using namespace std;

int main() {
	// 위치 표현
	// 2D(x,y)
	// 3D(x,y,z)
	//{
	//	Pos p1;
	//	Pos p2(3, 5);
	//	Pos p3(p2);
	//	Pos p4(move(p3));

	//	if (p1 == p4)
	//	{
	//		cout << "두 좌표가 같습니다" << endl;
	//	}
	//	else {
	//		cout << "두 좌표가 다릅니다" << endl;
	//	}

	//	if (p2 != p4)
	//	{
	//		cout << "두 좌표가 다릅니다" << endl;
	//	}
	//	else {
	//		cout << "두 좌표가 같습니다" << endl;
	//	}

	//	cin >> p1;
	//	cout << "p1의 데이터\n" << p1;
	//	cin >> p2;
	//	cout << "p2의 데이터\n" << p2;
	//	cin >> p4;
	//	cout << "p3의 데이터\n" << p4;
	//}
	Pos DungeonPos(100, 100);
	Player p1;

	p1.Move(1, 1);
	p1.DisplayPos();
	p1.Teleport(&DungeonPos);
	p1.DisplayPos();

	Pos DungeonMonsterPos(111, 111);
	Monster mon1;
	mon1.Move(3, 5);
	mon1.DisplayPos();
	mon1.Teleport(&DungeonMonsterPos);
	mon1.DisplayPos();




}