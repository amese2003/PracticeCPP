#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 생성자와 소멸자

// 생성자 [Constructor] 와 소멸자 (Destructor)
// 이 중에서 굉장히 특별한 함수 2종이 있는데, 바로 [시작]과 [끝]을 알리는 함수

// - 시작 (탄생) -> 생성자
// - 끝 (소멸) -> 소멸자 (딱 1개)

// [암시적(Implicit) 생성자]
// 생성자를 명시적으로 만들지 않으면?
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐.
// -> 근데 우리가 명시적(Explicit)으로 아무 생성자 하나 만들면,
// 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어지지 않음!

// class는 일종의 설계도
class Knight {
public:

	// [1] 기본 생성자
	Knight() {
		_hp = 100;
		_attack = 10;
		_posY = 0;
		_posX = 0;

		cout << "Knight() 기본 생성자" << endl;
	}

	// [2] 복사 생성자? (자기 자신의 클래스 참조 타입을 인자로 받음)
	// (일반적으로 '똑같은' 데이터를 지닌 객체가 생성되길 기대한다)
	Knight(const Knight& knight) {
		_hp = knight._hp;
		_attack = knight._attack;
		_posX = knight._posX;
		_posY = knight._posY;
	}

	Knight(int hp, int attack, int posX, int posY) {
		_hp = hp;
		_attack = attack;
		_posY = posY;
		_posX = posX;
	}


	// [3] 기타 생성자

	// 이 중에서 인자를 1개만 받는 [기타 생성자]를 
	// [타입 변환 생성자] 라고 부르기도 함.

	// 명시적인 용도로만 사용할 것!
	 explicit Knight(int hp) {
		_hp = hp;
		_attack = 10;
		_posY = 0;
		_posX = 0;

		cout << "Knight() 기본 생성자" << endl;
	}

	// 소멸자
	~Knight() {
		cout << "~Knight() 소멸자" << endl;
	}

	// 멤버 함수 선언
	void Move(int y, int x);
	void Attack();
	void Die() {
		_hp = 0;
		cout << "Die" << endl;
	}
public:
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Move(Knight* knight, int y, int x) {
	knight->_posY = y;
}

void Knight::Move(int y, int x) {
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack() {
	cout << "Attack" << endl;
}

void HelloKnight(Knight k) {
	cout << "Hello Knight" << endl;
}

int main() 
{	
	Knight k1(100, 10, 0, 0);
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	Knight k2(k1); // 복사 생성자

	Knight k3 = k1; // 복사 생성자

	Knight k4; // 생성자
	k4 = k1; // 복사

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	// 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
	int num = 1;


	float f = (float)num; // 명시작 < 우리가 코드로 num을 float 바구니에 넣으라고 함.
	double d = num; // 암시작 << 별말 안했는데 컴파일러가 알아서 넣음.

	Knight k5;
	k5 = (Knight)1;

	HelloKnight((Knight)5);

	return 0;
}