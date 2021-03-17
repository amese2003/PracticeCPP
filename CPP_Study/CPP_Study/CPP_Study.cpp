#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : enum class

// unscoped enum (범위없는)
enum PlayerType {
	PT_Knight,
	PT_Archer,
	PT_Mage
};

enum MonsterType {
	MT_Knight
};

enum class ObjectType {
	Player,
	Monster,
	Projectile
};

int main()
{
	// enum class (scoped enum)
	// 1) 이름공간 관리 (scoped)
	// 2) 암묵적인 변환 금지
	PlayerType t;
	cout << sizeof(t) << endl;

	double value = PT_Knight;

	double vlaue = static_cast<double>(ObjectType::Player);
	

	return 0;
}
