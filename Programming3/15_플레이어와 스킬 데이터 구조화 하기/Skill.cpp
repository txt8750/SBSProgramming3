#include "Skill.h"
#include <conio.h>


void Player::Update()
{
    // keyavailable
    // kbhit()
    // 'q', 'w', 'e', 'r' key 값
    if (_kbhit()) {
        char input = _getch();
        switch (input) {
        case 'q': case 'Q': useSkill(0); break;
        case 'w': case 'W': useSkill(1); break;
        case 'e': case 'E': useSkill(2); break;
        case 'r': case 'R': useSkill(3); break;
        default:; // q,w,e,r 이외의 키가 눌린 경우
        }
    }
}


bool Passive_Skill::IsAvailable()
{
    // Update 구조. TimeTick  4초마다 실행되는 패시브다.
    return true;
}

void Passive_Skill::Excute()
{
    if (IsAvailable())
    {
        // 로직을 실행하라.
    }
}

void Garen_Passive::Excute()
{
    cout << "가렌이 8초 동안 피해를 입지 않거나 적의 스킬에 맞지 않으면 5초마다 최대 체력의 일정 비율롤아이콘-레벨만큼 회복합니다.\n" << endl;
}



bool Active_Skill::IsAvailable()
{
    // Update 구조. 특정 키를 입력헀을때.
    // 쿨타임이 아닐 때
    return true;

}

void Active_Skill::Excute()
{
    if (IsAvailable())
    {
        // 로직을 실행하라.
    }
}

bool Garen_Q::IsAvailable()
{
    timeTick++;
    if (timeTick >= coolTime)
    {
        timeTick = 0;
        return true;
    }

    return false;
}

void Garen_Q::Excute()
{
    if (IsAvailable())
    {
        cout << "가렌에게 적용된 모든 둔화 효과가 제거되고 일정 시간 동안 이동 속도가 35% 상승합니다.\n다음 기본 공격은 1.5초 동안 롤아이콘 - 군중제어 침묵 침묵시키고 추가 물리 피해를 입힙니다\n" << endl;
    }
}

bool Garen_W::IsAvailable()
{
    timeTick++;
    if (timeTick >= coolTime)
    {
        timeTick = 0;
        return true;
    }

    return false;
}

void Garen_W::Excute()
{
    if (IsAvailable())
    {
        cout << "가렌이 4초 동안 용기백배하여 받는 피해가 감소합니다. 또한 0.75초 동안 일정 피해를 흡수하는 보호막과 60%의 강인함을 얻습니다.\n" << endl;
    }
}

bool Garen_E::IsAvailable()
{
    timeTick++;
    if (timeTick >= coolTime)
    {
        timeTick = 0;
        return true;
    }

    return false;
}

void Garen_E::Excute()
{
    if (IsAvailable())
    {
        cout << "가렌이 3초 동안 검을 들고 빠르게 회전하여 물리 피해를 여러 차례 입힙니다.\n가장 가까운 적을 대상으로는 25 % 의 추가 피해를 입힙니다.\n공격에 6번 맞은 챔피언은 6초 동안 방어력이 25 % 감소합니다.\n" << endl;
    }
}

bool Garen_R::IsAvailable()
{
    timeTick++;
    if (timeTick >= coolTime)
    {
        timeTick = 0;
        return true;
    }

    return false;
}

void Garen_R::Excute()
{
    if (IsAvailable())
    {
        cout << "가렌이 적을 처단할 데마시아의 힘을 소환하여 잃은 체력의 일정 비율에 해당하는 고정 피해를 입힙니다.\n" << endl;
    }
}



void Player::setSkill(unique_ptr<Skill> skill)
{
    skills.push_back(move(skill));  // push_back은 copy 동작이 일어나므로 std::move()함수를 사용
}

void Player::useSkill(int index)
{
     skills[index]->Excute();
}

