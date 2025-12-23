#include "Screen.h"
#include "run_GameObject.h"

using namespace std;

int main()
{
	Screen screen;

	run_GameObject* goArray[4];

	goArray[0] = new run_GameObject;
	goArray[1] = new run_GameObject(70, 6, "###", 5);
	goArray[2] = new run_GameObject(70, 6, "@@@@@", 1);
	goArray[3] = new jump_GameObject(70, 10, "JUMP", 1, 2);

	while (true)
	{
		// 플레이어 입력 player->update

		// gameobject->update
		for (int i = 0; i < 4; i++)
		{
			goArray[i]->Update();
		}

		// Rendering
		screen.clear();
		for (int i = 0; i < 4; i++)
		{
			goArray[i]->Draw(screen);
		}
		//Flip
		screen.flipping();

		// 고정 대기시간
		Sleep(16);
	}
	delete[] goArray;
}