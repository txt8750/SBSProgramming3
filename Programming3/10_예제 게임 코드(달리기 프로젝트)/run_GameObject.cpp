#include "run_GameObject.h"

run_GameObject::run_GameObject(int _x, int _y, string _shape, int _speed, int _movetick) : x(_x), y(_y), shape(_shape), speed(_speed), movetick(_movetick)
{
}

run_GameObject::run_GameObject() : run_GameObject(70, 5, "This is example", 3)
{
}

void run_GameObject::Update()
{
	// 속도 변수(3). 속도를 체크하는 tick(0)
	movetick++;
	if (movetick >= speed) {
		// 움직여라 코드. (다형성을 가지게 만들어라)
		Move();
		movetick = 0;
	}


}

void run_GameObject::Draw(Screen& screen)
{
	screen.print(x, y, shape);
}

void run_GameObject::Move()
{
	x--;
	if (x <= 0) { x = 70; }
}

jump_GameObject::jump_GameObject(int _x, int _y, string _shape, int _speed, int _jump_power, int _movetick)
	: run_GameObject(_x,_y,_shape,_speed), jump_power(_jump_power)
{
	jumpTime = 30;
	jumptick = 0;
	isGround = true;
}

jump_GameObject::jump_GameObject() : run_GameObject(), jump_power(2)
{
	jumpTime = 30;
	jumptick = 0;
	isGround = true;
}

void jump_GameObject::Move()
{
	jumptick++;
	if (jumptick >= jumpTime) {
		// 움직여라 코드. (다형성을 가지게 만들어라)
		if (isGround) {
			y += jump_power;
		}
		else {
			y -= jump_power;
		}
		isGround = !isGround;

		jumptick = 0;
	}	
	run_GameObject::Move();
}

dash_GameObject::dash_GameObject(int _x, int _y, string _shape, int _speed, int _dash_power, int _movetick)
	: run_GameObject(_x, _y, _shape, _speed), dash_power(_dash_power)
{
	dashtick = 0;
	dashtime = 20;
}

dash_GameObject::dash_GameObject() : run_GameObject(), dash_power(3)
{
	dashtick = 0;
	dashtime = 3;
}

void dash_GameObject::Move()
{
	dashtick++;
	if (dashtick >= dashtime)
	{
		x -= dash_power;
		dashtick = 0;
	}
	run_GameObject::Move();
}

