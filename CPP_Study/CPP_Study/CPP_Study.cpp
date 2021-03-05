#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 타입 변환 (포인터)

class Item {
public:
	Item() {
		cout << "Item()" << endl;
	}

	Item(const Item& item) {
		cout << "Item(const Item&)" << endl;
	}

	~Item() {
		cout << "~Item()" << endl;
	}


public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {}; // 이런 저런 정보들로 인해 비대해짐
};

void TestItem(Item item) {

}

void TestItmePtr(Item* item) {

}

int main() 
{	
	// 복습
	{
		// Stack [ type(4) dbid(4) dummy(4096) ]
		Item item;

		// Stack [ 주소 (4,8) ] -> Heap 주소 [ type(4) dbid(4) dummy(4096) ]
		Item* item2 = new Item();

		TestItem(item);
		TestItem(*item2);

		TestItmePtr(&item);
		TestItmePtr(item2);

		// 메모리 누수 (Memory Leak) -> 점점 가용 메모리가 줄어든다!
		delete item2;
	}

	// 배열
	{
		cout << "----------------------" << endl;
		// 진짜 아이템이 100개 있음. stack 메모리에 올라와있다
		Item item3[100] = {};
		
		cout << "----------------------" << endl;
		// 아이템이 100개가 있을까?
		// 아이템을 가리키는 바구나가 100개. 실제 아이템은 1개도 없을수도...
		Item* item4[100] = {};

		for (int i = 0; i < 100; i++)
			item4[i] = new Item();
		cout << "----------------------" << endl;

		for (int i = 0; i < 100; i++)
			delete item4[i];
	}

	return 0;
}