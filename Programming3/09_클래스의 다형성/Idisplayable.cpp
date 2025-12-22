#include "Idisplayable.h"

using namespace std;

void Unit::Display() const
{
	cout << "\nExample3 예제" << endl;
	cout << "유닛 입니다." << endl;
}

void Example3()
{
	Unit zerg;
	zerg.Display();
}
