// STL c++ 개발자(게임) - STL 잘 아시나요?
// Standard Template Library (신뢰할 수 있는 라이브러리)
// 자료구조 - 알고리즘

// 컨테이너 알고리즘 이터레이터(반복자)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Monster
{
private:
	int hp;
	int atk;
	string name;
public:
	int GetStrength() const { return hp + atk; }

	bool operator>(const Monster& other)
	{
		return (hp + atk) > (other.hp + other.atk);
	}
	Monster(int _hp, int _atk, string _name) : hp(_hp), atk(_atk), name(_name) {}
	Monster() : Monster{ 100, 10, "이름없음"} {}

	void Damage(int amount) { hp -= amount; }

	bool IsDeath() { return hp <= 0; }
	
// 접근 지정자.
// 생성 - 소멸자
// 상속 - 구성
// 스마트 포인터
};

// Room은 게임에 등장하는 게임 요소를 incount 시키는 객체다.
// iterator<Room> iterator++

struct CompareStrength
{
	bool operator()(const Monster* a, const Monster* b)
	{
		return a->GetStrength() < b->GetStrength();
	}
};

class Room
{
	// Monster* unique_ptr<Monster>
private:
	vector<Monster*> AvailableMonsters; // 컨테이너 생성. 랜덤한 몬스터들이 배정 되어 있다.
	vector<Monster*> SettingsMonster; // 약한 몬스터가 0번배열에 저장이 되어있다.
public:
// 몬스터들의 강함 순위를 정해서 약한 몬스터가 앞에서 등장하게 구현하고 싶다. (순서를 재정렬하고싶다.)
	void Initialize(const vector<Monster*>& copyMonsters)
	{
		AvailableMonsters = copyMonsters;
	}
	void SetOrder()  // 알고리즘 라이브러리 가져와서 코드를 실행하겠다.
	{
		SettingsMonster = AvailableMonsters;
		sort(SettingsMonster.begin(), SettingsMonster.end(), CompareStrength());
	}

	int RoomCount() const { return SettingsMonster.size(); }

	Monster* Encount(int roomindex) { return SettingsMonster[roomindex]; }
};

class Player
{
private:
	int hp;
	int atk;
public:

	Player(int _hp, int _atk) : hp(_hp), atk(_atk) {}
	Player() : Player{ 1000, 100 } {}
	bool IsDeath() { return hp <= 0; }
};

class BattleManager
{
private:
	void Battle(Player& player, Monster* mon)
	{
		// 턴
		while (true) {
			int playerIndex = 0;
			cout << "플레이어의 턴" << endl;

			// 내가 공격
			cin >> playerIndex; // 대기 하라.
			player.Attack(mon);

			// 니가 공격
			mon->Attack(player);

			if (player.IsDeath() || mon->IsDeath())
			{
				break;
			}
		}

		// 몬스터가 죽었으면 다음 전투를 진행.
		// 플레이어가 죽었으면 게임 종료
		if (player.Death) {}
		if (mon.Death) {}
	}
public:
	void PlayRoom(Player& player,Room room)
	{
		int battleCount = room.RoomCount();
		for (int i = 0; i < battleCount; i++)
		{
			// 전투

			// 몬스터와 조우했다.
			Monster* mon = room.Encount(i);

			Battle(player, mon);
		}
	}
};

int main()
{
	cout << "16강 STL 예제" << endl;

	Room room;
	vector<Monster*> copyMonsters;
	copyMonsters.push_back(new Monster(70, 7, "C")); 
	copyMonsters.push_back(new Monster(60, 6, "B"));
	copyMonsters.push_back(new Monster(80, 8, "D"));
	copyMonsters.push_back(new Monster(50, 5, "A"));

	room.Initialize(copyMonsters);
	room.SetOrder();

}