#pragma once
#ifndef MAPLE_H
#define MAPLE_H
#include <string>
#include <iostream>

using namespace std;

class Maple
{
private:
	// 속성
	string name;
	int level;
	unsigned long long hp;
	unsigned int mp;
	unsigned int exp;
	string location;
	unsigned int ad;
	unsigned int ap;

public:
	// 기능
	Maple() = default;
	Maple(string _name, string _location,
		int _level, unsigned long long _hp, unsigned int _mp, unsigned int _exp,
		unsigned int _ad, unsigned int _ap) :
	name(_name), location(_location), level(_level), hp(_hp), mp(_mp), exp(_exp), ad(_ad), ap(_ap){}


	void showBossStat() {
		cout << "보스 : " << name << endl;
		cout << "레벨 : " << level << endl;
		cout << "HP : " << hp << endl;
		cout << "MP : " << mp << endl;
		cout << "위치 : " << location << endl;
		cout << "물리 공격 : " << ad << endl;
		cout << "마법 공격 : " << ap << endl;
	}
};
#endif
