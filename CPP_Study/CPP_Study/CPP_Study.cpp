#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : override, final

class Creature {
public:
	virtual void Attack() {
		cout << "Player!" << endl;
	}
};
class Player : public Creature {
public:
	virtual void Attack() override {
		cout << "Player!" << endl;
	}
};

class Knight : public Player {
public:
	virtual void Attack() override {
		cout << "Knight!" << endl;
	}

private:
	int _stamina = 100;
};


int main()
{
	Player* p = new Knight();

	p->Attack();

	return 0;
}
