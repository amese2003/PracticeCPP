#include <string>
#include <iostream>
#include <vector>

using namespace std;

double Avar(vector<int> arr) {
    double answer = 0;
    int length = arr.size();
    double sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += arr.at(i);
    }

    answer = (sum / length);

    cout << answer << endl;

    return answer;
}