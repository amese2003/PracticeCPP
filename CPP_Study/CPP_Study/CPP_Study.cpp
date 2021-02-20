#include <iostream>

using namespace std;

// 오늘의 주제 : 데이터 연산

unsigned char flag; // 부호를 없애야 >> 를 해도 부호가 딸려오지 않음!

// 한번 정해지면 절때 바뀌지 않을 값들
// const를 붙였으면 초기값 반드시 지정
// 변수의 상수화


// 그러면 const도 바뀌지 않는 읽기 전용일까?
// .rodata?
// 사실 c++ 표준에서 꼭 그렇게 하라는 말이 없음
// 그냥 컴파일러 마음임.
const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3;

// [데이터 영역]
// .data (초기값 있는 경우)
int rax = 1;

// .bss (초기값 없는 경우)
int ebx;

// .rodate (읽기 전용 데이터)
const char* msg = "Hello World";


int main()
{
    // 이건 스택 영역에다가 들어감.
    const int asd = 11;

    // [스택 영역]
    int c = 1;

#pragma region 비트연산
    
    // 언제 필요할까?
    // 비트 단위의 조작이 필요할 때
    // - 대표적으로 BitFlag

    // ~ bitwise not
    // 단일 숫자의 모든 비트를 대상으로, 0은 1, 1은 0으로

    // & bitwise and
    // 두 숫자의 모든 비트 쌍을 대상으로, and

    // | bitwise or
    // 두 숫자의 모든 비트 쌍을 대상으로, or

    // ^ bitwise xor
    // 두 숫자의 모든 비트 쌍을 대상으로, xor

    // << 비트 좌측 이동
    // 비트열을 N만큼 왼쪽으로 이동
    // 넘치는 비트는 버림.
    // *2를 할 때 자주 보임.

    // >> 비트 우측 이동
    // 비트열을 N만큼 오른쪽으로 이동
    // 오른쪽의 넘치는 N개의 비트는 버림.
    // 왼쪽 생성되는 N개의 비트는 어떻게 할래?
    // - 부호 비트가 존재할 경우 부호 비트를 따라감 (부호있는 정수라면 이 부분을 유의)
    // - 아니면 0

    int a = 1;
    int b = 123;

    // b가 대칭키!
    a ^= b;
    a ^= b;

    // 실습
    // 0b0000 [무적][변이][스턴][공중부양]

    // 무적?
    flag = (1 << INVINCIBLE);
    
    // 변이 상태 추가 (무적 + 변이)
    flag |= (1 << POLYMORPH);

    // 무적인지 확인하고 싶다
    // bitmask
    bool invincible = ((flag & (1 << 3)) == 1);
    
    
    // 무적이거나 스턴상태
    bool stunOrInvincible = ((flag & 0b1010) != 0);



    


#pragma endregion


    return 0;
}