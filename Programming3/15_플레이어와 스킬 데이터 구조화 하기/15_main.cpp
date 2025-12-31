#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

#include "Skill.h"
#include "Screen.h"

#define FRAME 17

// 플레이어	player
// 스킬		skill

using namespace std;

int main() {
	unique_ptr<Skill> garenPassive = make_unique<Garen_Passive>();
	unique_ptr<Skill> garen_Q = make_unique<Garen_Q>();
	unique_ptr<Skill> garen_W = make_unique<Garen_W>();
	unique_ptr<Skill> garen_E = make_unique<Garen_E>();
	unique_ptr<Skill> garen_R = make_unique<Garen_R>();

	// 데이터를 사용하는 객체가 필요하다.

	Player Garen;

	Garen.setSkill(make_unique<Garen_Q>());
	Garen.setSkill(make_unique<Garen_W>());
	Garen.setSkill(make_unique<Garen_E>());
	Garen.setSkill(make_unique<Garen_R>());

	//Garen.useSkill(4); // cin >> "Q" Q가 발동.

	//Skill* garenPassive = new Garen_Passive();
	//Skill* garenQ = new Garen_Q();

	//garenPassive->Excute();
	//garen_Q->Excute();
	//garen_W->Excute();

	while (true)
	{
		// 플레이어의 입력
		Garen.Update();

		// 문자를 입력 받는 함수

		// 입력된 값을 가지고 스킬을 사용하는 함수

		Sleep(FRAME);
	}
}