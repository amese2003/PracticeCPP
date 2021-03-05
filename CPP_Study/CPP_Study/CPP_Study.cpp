#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 타입 변환 (포인터)
class Knight {

};

class Item {
public:
	Item() {
		cout << "Item()" << endl;
	}

	Item(const Item& item) {
		cout << "Item(const Item&)" << endl;
	}

	Item(int itemType) : _itemType(itemType) {

	}

	~Item() {
		cout << "~Item()" << endl;
	}


public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {}; // 이런 저런 정보들로 인해 비대해짐
};

enum ItemType {
	IT_WEAPON = 1,
	IT_ARMOR = 2
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		_itemType = 1;
		cout << "Item()" << endl;
	}

	~Weapon() {
		cout << "~Weapon()" << endl;
	}

public:
	int _damage = 0;
};

class Armor : public Item {
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Item()" << endl;
	}

	~Armor() {
		cout << "~Armor()" << endl;
	}

public:
	int _defence = 0;
};

void TestItem(Item item) {

}

void TestItmePtr(Item* item) {

}

int main() 
{	
	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{
		// Stack [ 주소 ] -> Heap [_hp(4)]
		Knight* knight = new Knight();

		// 암시적은 안돼
		// 명시적   가능

		// stack [주소] 
		Item* item = (Item*)knight;
		item->_itemType = 2;
		item->_itemDbId = 1;
	}

	// 자식 -> 부모 변환 테스트
	{
		Item* item = new Item();


		// [    [Item]      ]
		// [ _damage        ]
		//Weapon* weapon = (Weapon*)item;

		// 으악 안돼
		//weapon->_damage = 10;


		delete item;
	}

	// 부모 -> 자식 변환 테스트
	{
		// [    [Item]      ]
		// [ _damage        ]
		Weapon* weapon = new Weapon();

		// 암시적으로도 가능!
		Item* item = weapon;

		delete weapon;
	}
	// 명시적으로 타입 변환 할 때는 항상 조심해야한다!
	// 암시적으로 될 때는 안전하다?
	// -> 평생 명시적으로 타입 변환(캐스팅)은 안 하면 되는거 아님?

	Item* inventory[20] = {};

	srand((unsigned int)time(0));
	for (int i = 0; i < 20; i++) {
		int randvalue = rand() & 2;

		switch (randvalue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;

		default:
			break;
		}
	}

	return 0;
}