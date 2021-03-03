#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 객체지향 마무리

// 1) struct vs class

// c++ 에서는 struct나 class 종이 한장차이다.
// struct는 기본 접근 지정자가 public, class는 private
// 왜 이렇게 했을까? c++은 c언어에서 파생되어 발전, 어느정도 호환성 때문에..
// -> struct는 구조체 (데이터 묶음)을 표현하는 용도
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도

struct TestStruct {
	int _a;
	int _b;
};

class TestClass {
private:
	int _a;
	int _b;
};

// 2) static 변수, static 함수
class Marine {
public:
	// 특정 마린 객체에 종속적
	int _hp;

	void TakeDamage(int damage) {
		_hp -= damage;
	}

	static void SetAttack() {
		s_attack = 100;
	}


	// 특정 마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관
	static int s_attack; // 설계도상으로만 존재
};

// static 변수는 어떤 메모리?
// 초기화 하면 .data
// 안하면 .bss
int Marine::s_attack = 0;

class Player {
public:
	int _id;
};

int GenerateId() {

	// 생명주기: 프로그램 시작/종료 (메모리에 항상 올라가 있음)
	// 가시범위: 

	// 정적 지역 객체
	static int s_id = 1;

	return s_id++;
}


int main() 
{	
	Marine m1;
	m1._hp = 45;

	Marine::s_attack = 6;
	Marine::SetAttack();
	//m1.s_attack = 6;

	

	Marine m2;
	m1._hp = 45;

	// 스택 아님. .data 영역
	static int id = 10;
	int a = id;

	return 0;
}