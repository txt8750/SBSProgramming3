// cpp json 사용하기
// 객체를 규격화하여 표현

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

class Run
{
public:
	int x;
	int y;
	string Shape;
	int Speed;
public:
	Run(int x, int y, string Shape, int Speed) : x(x), y(y), Shape(Shape), Speed(Speed) {}
};

int main()
{
	cout << "JSON 파일 읽기" << endl;

	// 1. 프로젝트 내부에 있는 파일을 읽어오세요.
	string file_path = "D:\\SBS게임아카데미\\SBSProgramming3\\Programming3\\12_JSON 사용하기\\run_object.json";

	ifstream ifs(file_path);

	// 2. 파일 읽기
	IStreamWrapper isw(ifs);

	Document doc;
	doc.ParseStream(isw);


	vector<Run> runObjects;

	// 3. 파일 변환(Parse)
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
					Run r(obj["X"].GetInt(), obj["Y"].GetInt(), obj["Shape"].GetString(), obj["Speed"].GetInt());

					runObjects.push_back(r);
				}
			}
		}
	}

	// 4. 예제 출력
	for (const auto& r : runObjects)
	{
		cout << "x : " << r.x << ", y : " << r.y << ", Shape : " << r.Shape << ", Speed : " << r.Speed << endl;
	}
}