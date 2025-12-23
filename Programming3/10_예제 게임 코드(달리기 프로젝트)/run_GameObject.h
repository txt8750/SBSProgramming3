#pragma once

#include <string>
#include "Screen.h"

using namespace std;

class run_GameObject
{
protected:
	int x;
	int y;
	string shape;
	int speed;
	int movetick;

public:
	run_GameObject(int _x, int _y, string _shape, int _speed, int _movetick = 0);
	run_GameObject();

	void Update();
	void Draw(Screen& screen);
	virtual void Move();
};

class jump_GameObject : public run_GameObject
{
private:
	int jump_power;
	bool isGround; // 1 = ¶¥, 0 = Á¡ÇÁ
	int jumpTime;
	int jumptick;
public:
	jump_GameObject(int _x, int _y, string _shape, int _speed, int _jump_power, int _movetick = 0);
	jump_GameObject();

	void Move() override;
};

