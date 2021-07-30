#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Coliz(int num) {
    long long temp = num;
    int count = 0;
    int answer = 0;



    while (temp != 1)
    {
        if (temp % 2 == 0)
            temp = temp / 2;
        else
            temp = (temp * 3) + 1;

        count++;


        if (count == 500)
        {
            answer = -1;
            break;
        }
    }

    if (answer != -1)
        answer = count;



    return answer;
}