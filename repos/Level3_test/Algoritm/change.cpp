#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money)
{
    int answer = 0;

    vector<int> MakeChange(n + 1);

    MakeChange[0] = 1;

    for (int i = 0; i < money.size(); i++) {

        int change = money[i];

        for (int j = change; j <= n; j++) {
            MakeChange[j] += MakeChange[j - change];
            MakeChange[j] %= 1000000007;
        }
    }


    return MakeChange[n];
}