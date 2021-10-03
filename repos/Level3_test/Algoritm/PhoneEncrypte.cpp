#include <string>
#include <iostream>
#include <vector>

using namespace std;

string PhoneEncrypte(string phone_number) {

    string answer = phone_number;
    int length = phone_number.size();

    for (int i = 0; i < length - 4; i++)
    {
        answer[i] = '*';
    }


    return answer;
}