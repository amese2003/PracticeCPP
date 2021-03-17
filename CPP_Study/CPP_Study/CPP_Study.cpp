#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : 스마트 포인터 (smart pointer)

class Knight {
public:
	Knight() { cout << "Knight 생성" << endl; }
	~Knight() { cout << "Knight 소멸" << endl; }

	void Attack() {
		if (_target) {
			_target->_hp -= _damage;

			cout << "HP: " << _target->_hp << endl;
		}
	}
public:
	int _hp = 100;
	int _damage = 10;
	shared_ptr<Knight> _target = nullptr;
};

class RefCountBlock {
public:
	int _refCount = 1;
};

template<typename T>
class Shared_ptr {
public:
	Shared_ptr() {};
	Shared_ptr(T* ptr) : _ptr(ptr){
		if (_ptr != nullptr) {
			_block = new RefCountBlock();
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	Shared_ptr(const Shared_ptr& sptr) : _ptr(sptr._ptr), _block(sptr._block) {

		if (_ptr != nullptr) {
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	void operator=(const Shared_Ptr& sptr) {
		_ptr = sptr._ptr;
		_block = stpr._block;
	}

	~Shared_ptr() {
		if (_ptr != nullptr) {
			_block->_refCount--;
			cout << "RefCount : " << _block->_refCount << endl;

			if (_block->_refCount == 0) {
				delete _ptr;
				delete _block;
				cout << "Delete Data" << endl;
			}

			delete _ptr;
		}
	}

public:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};


int main()
{	

	// 스마트 포인터 : 포인터를 알맞는 정책에 따라 관리하는 객체
	// shared_ptr, weak_ptr, unique_ptr
	/*Shared_ptr<Knight> k2;
	{
		Shared_ptr<Knight> k1(new Knight());
		k2 = k1;
	}*/


	shared_ptr<Knight> k1 = make_shared<Knight>();
	shared_ptr<Knight> k2 = make_shared<Knight>();

	return 0;
}
