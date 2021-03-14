#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
using namespace std;

// 오늘의 주제 : map

class Player {
public:
	Player() : _playerId(0){}
	Player(int playerId) : _playerId(playerId) {}

public:
	int _playerId;
};

class Node {
public:
	Node* _left;
	Node* _right;

	int _key;
	Player* _value;
};

int main()
{
	// 연관 컨테이너

	srand(static_cast<unsigned int>(time(nullptr)));

	// map : 균형 이진 트리 (AVL)
	// - 노드 기반

	map<int, int> m;

	pair<map<int, int>::iterator, bool> ok;

	ok = m.insert(make_pair(1, 200));
	ok = m.insert(make_pair(1, 200));

	// 10만명
	for (int i = 0; i < 100000; i++) {
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5만명 퇴장
	for (int i = 0; i < 50000; i++) {
		int randValue = rand() % 50000;

		// Erase By Key
		//m.erase(randValue);
	}

	// Q) ID = 1만인 Player 찾고 싶다!
	// A) 매우 빠름
	unsigned int count = 0;
	count = m.erase(10000);
	count = m.erase(10000);

	map<int, int>::iterator findit = m.find(10000);
	if (findit != m.end()) {
		cout << "찾음" << endl;
	}
	else {
		cout << "못찾음" << endl;
	}

	// map 순회
	
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
		pair<const int, int>& p = (*it);
		int key = p.first;
		int value = p.second;

		cout << key << " " << value << endl;
	}

	// 없으면 추가, 있으면 수정
	map<int, int>::iterator findit = m.find(10000);
	if (findit != m.end()) {
		findit->second = 200;
	}
	else {
		m.insert(make_pair(10000, 10000));
	}

	// 없으면 추가, 있으면 수정 v2
	m[5] = 500;

	m.clear();
	// [] 연산자 사용할 때 수정
	// 대입을 허지 않더라도 (key/val) 형태의 데이터가 추가된다!

	for (int i = 0; i < 10; i++) {
		cout << m[1] << endl;
	}

	// 넣고 (insert , [])
	// 빼고 (erase)
	// 찾고 (find, [])
	// 반복자 (map::iterator) (*it) pair<key, value>&

	return 0;
}
