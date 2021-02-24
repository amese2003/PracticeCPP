#include <iostream>

using namespace std;

// 오늘의 주제 : 배열

struct StatInfo {
	int hp;
	int attack;
	int defence;
};


int main() {	

	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	auto WhoAmI = monsters;

	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// 포인터 덧셈은 타입만큼의 주소 이동
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [주의] 이건 완전히 다른 의미다!
	StatInfo temp = *(monsters + 2);
	temp.hp = 300;
	temp.attack = 30;
	temp.defence = 3;

	for (int i = 0; i < 10; i++) {
		StatInfo& monster = monsters[i]; // = *(monsters + i)
		monster.attack = 100 * (i + 1);
		monster.hp = 10 * (i + 1);
		monster.defence = (i + 1);
	}
	
	return 0;
}
