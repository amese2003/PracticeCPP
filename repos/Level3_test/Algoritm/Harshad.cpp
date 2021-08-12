#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool Harshad(int x) {
    vector<int> temp;
    string str = to_string(x);
    int length = str.size();
    int avar = x;
    int sum = 0;
    bool answer = false;

    for (int i = 0; i < length; i++)
    {
        temp.push_back(avar % 10);
        avar = avar / 10;
        sum = sum + temp[i];
    }


    if (x % sum == 0)
        answer = true;
    else
        answer = false;





    return answer;
}