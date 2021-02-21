#include <iostream>

using namespace std;

// 오늘의 주제 : 주의 사항

// 1) 변수의 유효범위

// 스택
// {} 중괄호의 범위가 생존 범위



int main()
{
    // 별찍기

    int input;
    cin >> input;


    for (int i = 0; i < input; i++) {
        
        for (int j = 0; j < input; j++)
            cout << "*";

        cout << "\n";
    }

    // 별찍기 2)
    // 음.. n*n개의 별은 좀 심심하다?

    for (int i = 0; i < input; i++) {
        for (int j = input - i; j > 0; j--)
            cout << "*";

        cout << "\n";
    }


    return 0;
}