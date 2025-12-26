#include "Screen.h"
#include "run_GameObject.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;

int main()
{

	string file_path = "D:\\SBS게임아카데미\\SBSProgramming3\\Programming3\\10_예제 게임 코드(달리기 프로젝트)\\run_object.json";

	ifstream ifs(file_path);
	IStreamWrapper isw(ifs);
	Document doc;
	doc.ParseStream(isw);

	vector<run_GameObject*> runObjects;

	if (doc.IsArray())	// 읽어온 파일이 배열인지 확인
	{
		for (int i = 0; i < doc.Size(); i++)
		{
			const Value& obj = doc[i];

			if (obj.IsObject())  //json 파일에서 {}로 묶어있는지 확인
			{
				if (obj.HasMember("X") && obj["X"].IsInt() &&
					obj.HasMember("Y") && obj["Y"].IsInt() &&
					obj.HasMember("Shape") && obj["Shape"].IsString() &&
					obj.HasMember("Speed") && obj["Speed"].IsInt())   // 각 객체의 자료형이 맞는지 확인
				{
					run_GameObject* r = new run_GameObject (obj["X"].GetInt(), obj["Y"].GetInt(), obj["Shape"].GetString(), obj["Speed"].GetInt());

					// 만약에 r의 enum타입이 일반 타입이면 run_GameObject로 생성
					// enum타입이 jump 타입이면 jump_GameObject로 생성
					// enum타입이 dash 타입이면 dash_GameObject로 생성
					runObjects.push_back(r);
				}
			}
		}
	}

	Screen screen;

	//run_GameObject* goArray[8];

	//goArray[0] = new run_GameObject;
	//goArray[1] = new run_GameObject(70, 6, "###", 5);
	//goArray[2] = new run_GameObject(70, 6, "@@@@@", 1);
	//goArray[3] = new jump_GameObject(70, 10, "JUMP", 1, 2);
	//goArray[4] = new jump_GameObject(70, 12, "dddddd", 3, 4);
	//goArray[5] = new jump_GameObject(60, 20, "aaaaaa", 3, 4);
	//goArray[6] = new jump_GameObject(60, 15, "bbbbbbb", 2, 3);
	//goArray[7] = new dash_GameObject(70, 25, "ccccccc", 1, 10);

	while (true)
	{
		// 플레이어 입력 player->update

		// player->update();
																  
		// gameobject->update
		for (const auto& go : runObjects)
		{
			go->Update();
		}

		// Rendering
		// player->draw();
		screen.clear();
		for (const auto& go : runObjects)
		{
			go->Draw(screen);
		}
		//화면 전환(Flip)
		screen.flipping();

		// 고정 대기시간
		Sleep(16);
	}
	/*delete[] goArray;*/
}