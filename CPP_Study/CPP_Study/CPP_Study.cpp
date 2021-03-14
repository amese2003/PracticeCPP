#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 오늘의 주제 : list

class Node {
public:
	Node* _next;
	Node* _prev;
	int _data;
};

int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	list<int> li;

	list<int>::iterator itRemember;
	for (int i = 0; i < 100; i++) {

		if (i == 50) {
			itRemember = li.insert(li.end(), i);
		}
		else {
			li.push_back(i);
		}


	}


	for (int i = 0; i < 100; i++)
		li.push_back(0);

	int size = li.size();
	
	int first = li.front();
	int last = li.back();

	// 임의 접근 비허용
	//li[3] = 10; // 없음

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();


	//list<int>::iterator itTest1 = --itBegin;
	//list<int>::iterator itTest2 = --itEnd;
	//list<int>::iterator itTest3 = ++itEnd;

	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());


	for (list<int>::iterator it = li.begin(); it != li.end(); it++) {
		cout << *it << endl;
	}

	li.insert(itBegin, 100);

	li.erase(li.begin());

	li.pop_front();

	li.remove(10);


	return 0;
}
