#include "Screen.h"
#include "run_GameObject.h"

using namespace std;

int main()
{
	Screen screen;

	run_GameObject* goArray[8];

	goArray[0] = new run_GameObject;
	goArray[1] = new run_GameObject(70, 6, "###", 5);
	goArray[2] = new run_GameObject(70, 6, "@@@@@", 1);
	goArray[3] = new jump_GameObject(70, 10, "JUMP", 1, 2);
	goArray[4] = new jump_GameObject(70, 12, "dddddd", 3, 4);
	goArray[5] = new jump_GameObject(60, 20, "aaaaaa", 3, 4);
	goArray[6] = new jump_GameObject(60, 15, "bbbbbbb", 2, 3);
	goArray[7] = new dash_GameObject(70, 25, "ccccccc", 1, 10);

	while (true)
	{
		// 플레이어 입력 player->update

		// player->update();
																  
		// gameobject->update
		for (const auto& go : goArray)
		{
			go->Update();
		}

		// Rendering
		// player->draw();
		screen.clear();
		for (const auto& go : goArray)
		{
			go->Draw(screen);
		}
		//화면 전환(Flip)
		screen.flipping();

		// 고정 대기시간
		Sleep(16);
	}
	delete[] goArray;
}