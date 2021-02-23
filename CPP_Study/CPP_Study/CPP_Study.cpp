#include <iostream>

using namespace std;

// 오늘의 주제 : 포인터 연산


// 1) 주소 연산자 (&)
// 2) 산술 연산자
// 3) 간접 연산자
// 4) 간접 멤버 연산자

struct Player {
	int hp;
	int damage;
};


int main() {

	int number = 1;

	// 1) 주소 연산자 (&)
	// - 해당 변수의 주소를 알려달라!

	int* ptr = &number;

	// 2) 산술 연산자

	//number = number + 1;


	number += 1; // 1증가, 성공적 (!)

	// int*
	// - * : 포인터 타입이네. (4,8바이트) 주소를 담는 바구니.
	// - int : 주소를 따라가면 int(4바이트 정수형 바구니)가 있다.

	// [!] 포인터에서 +나 -등 산술 연산으로 1을 더하거나 뺴면?
	// 정말 '그 숫자'를 더하고 빼라는 의미가 아니다!
	// 한번에 TYPE 크기만큼 이동해라!

	//ptr = ptr + 1; // 메모리상에서 4가 증가했다

	// 3) 간접 연산자 (*)
	// - 포탈을 타고 해당 주소로 이동!

	number = 3;
	*ptr = 3;

	Player player;
	player.hp = 100;
	player.damage = 10;

	Player* playerPtr = &player;

	(*playerPtr).hp = 200;
	(*playerPtr).damage = 200;

	// 4) 간접 멤버 연산자 (->)
	// * 간접 연산자 (포탈 타고 해당 메모리로 이동)
	// . 구조체의 특정 멤버를 다룰 때 사용 (어셈블리 언어로 까보면 . 사실상 그냥 덧셈.)
	// * 와 .을 한방에!

	playerPtr->hp = 200;
	playerPtr->damage = 200;



	return 0;
}

