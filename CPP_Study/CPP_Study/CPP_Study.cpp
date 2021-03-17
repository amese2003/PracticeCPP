#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : delete (삭제된 함수)

class Knight {
public:

public:
	// 정의되지 않은 비공개 함수
	void operator=(const Knight& k) = delete;


	// 모든 것을 뚫는 창 vs 절대 방패
	friend class Admin;
private:
	int _hp = 100;
};

class Admin {
public:
	void CopyKnight(const Knight& k) {
		Knight k1;
	}
};

int main()
{
	Knight k1;

	Knight k2;

	// 복사 연산자
	//k1 = k2;

	return 0;
}
