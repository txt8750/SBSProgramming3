#include "01_namespace.h"

void ShowPlayer()
{
	std::cout << "플레이어 입니다." << std::endl;
}

void A::ShowPlayer()
{
	std::cout << "A의 플레이어 입니다." << std::endl;
}

void B::ShowPlayer()
{
	std::cout << "B의 플레이어 입니다." << std::endl;
}