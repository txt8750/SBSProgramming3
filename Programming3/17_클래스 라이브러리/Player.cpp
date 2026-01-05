#include "Player.h"

using namespace std;

Player::Player(int _id, int _hp, int _atk) : BattleObject(_id, _hp, _atk) {}

Player::Player() : Player{ 1001, 1000, 100 } {}

void Player::Attack(BattleObject* other)
{
	cout << "몬스터에게 " << atk << "만큼 데미지를 주었습니다!" << endl;
	other->Damage(atk);
}