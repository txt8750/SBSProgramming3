#pragma once

#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class Player;
class Skill;

// 1) unique_ptr, [shared_ptr, weak_ptr]
// 2) shared : 다른 포인터가 플레이어가 소유한 스킬을 가리키고 있다.

// Command Pattern 사용하기
// 데이터를 저장하는 객체 선언. <- 자료구조

class Player
{
private:
	vector<unique_ptr<Skill>> skills;
	//shared_ptr<Skill> skill;  // player가 소유한 skill 변수는 오로지 플레이어 객체만 가리키겠다.
public:
	void Update();

	void setSkill(unique_ptr<Skill> skill);

	void useSkill(int index);
};


class Skill  // 다형성을 사용해서 여러 스킬로 표현해보자.
{
	// 패시브 스킬, 액티브 스킬
protected:
	virtual bool IsAvailable() = 0;

public:
	virtual void Excute() = 0;
};


// Passive 스킬
class Passive_Skill : public Skill
{
private:
	virtual bool IsAvailable() override;

public:
	virtual void Excute() override;
};

class Garen_Passive : public Passive_Skill
{
private:

public:
	virtual void Excute() override;
};



// Active 스킬
class Active_Skill : public Skill
{
protected:
	int coolTime;
	int timeTick;

	virtual bool IsAvailable() override;

public:
	virtual void Excute() override;
};

class Garen_Q : public Active_Skill
{
private:
	virtual bool IsAvailable() override;
public:
	virtual void Excute() override;
};

class Garen_W : public Active_Skill
{
private:
	virtual bool IsAvailable() override;
public:
	virtual void Excute() override;
};

class Garen_E : public Active_Skill
{
private:
	virtual bool IsAvailable() override;
public:
	virtual void Excute() override;
};

class Garen_R : public Active_Skill
{
private:
	virtual bool IsAvailable() override;
public:
	virtual void Excute() override;
};