#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 상속성

// 객체 지향 (OOP Object Oriented Programming)

// - 상속성
// - 은닉성
// - 다형성



// 메모리
// [ [Player] ]
// [ Knight   ]


// 생성자(N) / 소멸자(1)

// 생성자는 탄생을 기념해서 호출하는 함수?
// - Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택! 그냥 둘 다 호출하자!


// GameObject
// - Creature
// -- Player, Monster, Npc, Pet
// - Projectiile
// -- Arow, Fire
// - Env

// Item
// - Weapon
// -- Sword, Bow
// - Aromr
// -- Helmet, Boots, Armor
// - Consumable
// -- Potion, scroll

class GameObject {
public:
	int _objectId;
};

class Player {
public:
	Player() {
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() 생성자 호출" << endl;
	}

	Player(int hp) {
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp) 생성자 호출" << endl;
	}

	~Player() {
		cout << "~Player() 소멸자 호출" << endl;
	}


	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;
};

class Knight : Player {
public:
	void Move() { cout << "Player Move 호출" << endl; }

	Knight() 
	/*
		hidden Movement
		선처리 영역
		- 여기서 Player() 생성자 호출
	*/	
	{
		_stamina = 10;
		cout << "Knight() 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)
		/*
			hidden Movement
			선처리 영역
			- 여기서 Player() 생성자 호출
		*/
	{
		_stamina = stamina;
		cout << "Knight(int stamina) 생성자 호출" << endl;
	}

	~Knight() {
		cout << "~Knight() 소멸자 호출" << endl;
	}
	/*
		후처리 영역
		- 여기서 ~Player() 소멸자 호출
	*/

public:
	int _stamina;
};

class Mage : Player {
public:
};

int main() 
{	
	Knight k(100);

	return 0;
}