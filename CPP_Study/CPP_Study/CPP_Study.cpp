#include <iostream>

using namespace std;

// 오늘의 주제 : 주의 사항

// 1) 변수의 유효범위

// 스택
// {} 중괄호의 범위가 생존 범위



int main()
{
    srand(time(0));

    
    string output = "";
    int input;

    int total = 0;
    int win = 0;

    const int SCISSORS = 1;
    const int ROCK = 2;
    const int PAPER = 3;

    const int END = 4;

    while (true) {
        int value = 1 + rand() % 3; // 
        cout << "가위(1), 바위(2), 보(3)를 입력해주세요. 종료(4)" << endl;

        if (total == 0) {
            cout << "정보 없음" << endl;
        }
        else {
            float ratio = (win * 100) / total;
            cout << "현재 승률 : " << ratio << endl;
        }


        cin >> input;

        if (input == SCISSORS) {
            if (value == ROCK) {
                output = "패!";
            }
            else if (value == PAPER) {
                output = "승!";
                win++;
            }
            else {
                output = "비김!";
            }

            total++;
            cout << output << endl;
        }
        else if (input == ROCK) {
            if (value == ROCK) {
                output = "패!";
            }
            else if (value == SCISSORS) {
                output = "승!";
                win++;
            }
            else {
                output = "비김!";
            }

            total++;
            cout << output << endl;
        }
        else if (input == PAPER) {
            if (value == SCISSORS) {
                output = "패!";
            }
            else if (value == ROCK) {
                output = "승!";
                win++;
            }
            else {
                output = "비김!";
            }
            cout << output << endl;
        }
        else if (input == END) {
            break;
        }
        else {
            cout << "뭘 낸겁니까?" << endl;
        }
    }
    return 0;
}
