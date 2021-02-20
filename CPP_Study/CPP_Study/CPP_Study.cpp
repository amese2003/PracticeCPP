#include <iostream>

using namespace std;

// 오늘의 주제 : 주의 사항

// 1) 변수의 유효범위

// 스택
// {} 중괄호의 범위가 생존 범위



int main()
{
    int hp = 123;
    int maxHp = 1000;
    
    // int / int = int;

    // int / float float / int  = float
    float ratio = hp / maxHp;

    return 0;
}