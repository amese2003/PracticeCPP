#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : nullptr

class Knight {
public:
	void Test() {

	}

};

Knight* FindKnight() {
	// TODO

	return nullptr;
}

void Test(int a) {
	cout << "Test(int)" << endl;
}

void Test(void* ptr) {
	cout << "Test(*)" << endl;
}

// nullptr 구현

class NullPtr {
public:
	template<typename T>
	operator T* () const {
		return 0;
	}

	// 그 어떤 타입의 멤버 포인터와도 치환 가능
	template<typename C, typename T>
	operator T C::* () const {
		return 0;
	}

private:
	void operator&() const; // 주소값 & 막는다
};

int main()
{
	int* ptr = NULL;
	
	// 1) 오동작
	Test(0);
	Test(NULL);
	Test(nullptr);

	auto knight = FindKnight();

	void (Knight::* memFunc)();
	memFunc = &Knight::Test; 

	return 0;
}
