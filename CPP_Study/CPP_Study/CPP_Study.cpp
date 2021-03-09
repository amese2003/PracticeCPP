#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 포인터

int Add(int a, int b) {
	return a + b;
}

int Sub(int a, int b) {
	return a - b;
}

class Item {
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0) {

	}

public:
	int _itemId; // 아이템을 구분하기 위한 ID
	int _rarity; // 희귀도
	int _ownerId; // 소지자 ID
};

typedef bool(ITEM_SELECTOR)(Item* item);

Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector) {
	for (int i = 0; i < itemCount; i++) {
		Item* item = &items[i];

		if (selector(item))
			return item;

	}

	return nullptr;
}

bool IsRareItem(Item* item) {
	return item->_rarity >= 2;
}


int main() 
{	
	int a = 10;

	typedef int DATA;

	DATA* ptr = &a;

	// 함수
	typedef int(FUNC_TYPE)(int, int);

	// 1) 포인터 *
	// 2) 변수 이름 fn
	// 3) 데이터 타입 함수는 (인자는 int, int 반환은 int)
	FUNC_TYPE* fn;


	// 함수 포인터
	fn = Add;

	// 함수의 이름은 함수의 시작 주소 (배열과 유사)
	int result = fn(1, 2);	// 기본 문법
	cout << result << endl;

	int result2 = (*fn)(1, 2); // 함수 포인터는 *(접근 연산자) 붙여도 함수 주소! 
	cout << result2 << endl;

	Item items[10] = {};
	items[3]._rarity = 3;

	Item* rareItem = FindItem(items, 10, IsRareItem);


	return 0;
}