#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>  // 스마트 포인터, 포이터를 객체화 했다.

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;

// 1. Factory 클래스 (열거형을 읽어서 자신의 타입에 맞는 클래스를 생성해주는 클래스)
// 2. Spawner 클래스는 Factory클래스를 사용해서 클래스를 생성한다.
// 특정 클래스를 사용하는 클래스를 만들어라
// 포인터를 사용하는 클래스. 스마트 포인터.
// gameObject

enum class moveType {
	normal,
	jump,
	dash
};

class Run
{
public:
	int x;
	int y;
	string shape;
	int speed;

	Run() : Run(0, 0, "###", 3) {}
	Run(int x, int y, string shape, int speed) : x(x), y(y), shape(shape), speed(speed) {}
	virtual ~Run() = default;
	virtual void Move() { cout << shape << endl; }

	virtual void loadFromJson(const Value& v) {
		if (v.HasMember("x")) x = v["x"].GetInt();
		if (v.HasMember("y")) y = v["y"].GetInt();
		if (v.HasMember("shape")) shape = v["shape"].GetString();
		if (v.HasMember("speed")) speed = v["speed"].GetInt();
	}
};

class Dash : public Run
{
public:
	int dashpower;

	Dash() : Dash(0, 0, "@@@", 3, 0) {}
	Dash(int x, int y, string shape, int speed, int dashpower) : Run(x, y, shape, speed), dashpower(dashpower) {}
	void Move() override { cout << shape << endl; }

	void loadFromJson(const Value& v) override {
		Run::loadFromJson(v);
		if (v.HasMember("dashpower")) dashpower = v["dashpower"].GetInt();
	}
};

class Jump : public Run
{
public:
	int jumppower;

	Jump() : Jump(0, 0, "$$$", 3, 0) {}
	Jump(int x, int y, string shape, int speed, int jumppower) : Run(x, y, shape, speed), jumppower(jumppower) {}
	
	void Move() override { cout << shape << endl; }
	void loadFromJson(const Value& v) override {
		Run::loadFromJson(v); // 부모 데이터 로드
		if (v.HasMember("jumppower")) jumppower = v["jumppower"].GetInt();
	}
};

class RunFactory {
public:
	static std::unique_ptr<Run> createRun(const Value& v) {
		if (!v.HasMember("moveType")) return nullptr;

		moveType type = static_cast<moveType>(v["moveType"].GetInt());
		std::unique_ptr<Run> instance = nullptr;

		// 타입에 따른 인스턴스 생성
		switch (type) {
		case moveType::normal: instance = std::make_unique<Run>();  break;
		case moveType::jump:   instance = std::make_unique<Jump>(); break;
		case moveType::dash:   instance = std::make_unique<Dash>(); break;
		default: return nullptr;
		}

		// 데이터 주입
		if (instance) {
			instance->loadFromJson(v);
		}

		return instance;
	}
};

// RunFactory클래스를 이용해서 run객체를 vector에 저장해서 사용하는 Swawner 클래스를 만들어라.

class Spawner // 정의한 게임 객체를 생성하는 객체
{
private:
	// 다형성을 위해 부모 클래스의 포인터로 저장
	std::vector<std::unique_ptr<Run>> _units; // run* 저장하는 배열이다.

public:
	// JSON 파일 경로를 받아 객체들을 로드하고 리스트에 저장
	bool loadSpawnData(const string& filepath) {
		std::ifstream ifs(filepath);
		if (!ifs.is_open()) {
			std::cerr << "파일 열기 실패: " << filepath << std::endl;
			return false;
		}

		IStreamWrapper isw(ifs);
		Document doc;
		doc.ParseStream(isw);

		if (doc.HasParseError()) {
			std::cerr << "JSON 파싱 에러" << std::endl;
			return false;
		}

		if (!doc.IsArray()) {
			std::cerr << "JSON 형식이 배열이 아닙니다." << std::endl;
			return false;
		}

		// 기존 데이터 초기화 (필요시)
		_units.clear();

		// 팩토리를 이용해 객체 생성 및 저장
		for (const auto& item : doc.GetArray()) {
			auto unit = RunFactory::createRun(item);
			if (unit) {
				_units.push_back(std::move(unit));
			}
		}

		cout << _units.size() << "개의 객체가 생성되었습니다.\n" << std::endl;
		return true;
	}

	// 저장된 모든 객체의 행동 실행
	void Display() {
		for (const auto& r : _units) {
			r->Move();
		}
	}

	// 메모리 정리는 unique_ptr 덕분에 Spawner 소멸 시 자동 처리됨
};