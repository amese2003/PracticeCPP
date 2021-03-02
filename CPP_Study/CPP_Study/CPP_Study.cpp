#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 은닉성

// 객체 지향 (OOP Object Oriented Programming)

// - 상속성
// - 은닉성
// - 다형성

// 다형성 (Polymorphism = Poly + morph) = 겉은 똑같은데, 기능이 다르게 동작한다.
// - 오버로딩 (Overloading) = 함수 중복 정의 = 함수 이름 재사용
// - 오버라이딩(Overriding) = 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의

// 바인딩(Binding) = 묶는다
// - 정적 바인딩(Static Binding) : 컴파일 시점에 결정
// - 동적 바인딩 (Dynamic Binding) : 실행시점에 결정

// 일반 함수는 정적 바인딩을 기본으로 사용
// 동적 바인딩 원한다면? -> 가상 함수 (virtual fuction)

class Player {
public:
	void Move() { cout << "Move Player !" << endl; }

	virtual void VMove() { cout << "Move Player !" << endl; }
public:
	int _hp;
};

class Knight : public Player {
public:
	void Move() { cout << "Move Knight !" << endl; }

	// 가상 함수는 재정의를 해도 가상 함수
	void VMove() { cout << "Move Knight !" << endl; }
public:
	int _stamina;
};

class Mage : public Player {
public:
	int _mp;
};

void MovePlayer(Player* player) {
	(*player).VMove();
}

int main() 
{	
	Player p;
	//MovePlayer(&p); // 플레이어는 플레이어다? Yes
	//MoveKnight(&p); // 플레이어는 기사다? no
	

	Knight k;
	MovePlayer(&k);


	return 0;
}