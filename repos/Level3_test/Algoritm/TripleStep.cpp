#include <iostream>
#include <vector>

using namespace std;

int countWay(int n, vector<int>& memo) {
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (memo[n] > -1)
        return memo[n];
    else {
        memo[n] = countWay(n - 1, memo) + countWay(n - 2, memo) + countWay(n - 3, memo);

        return memo[n];
    }
}

int countWay(int n) {
    vector<int> memo(n + 1, -1);
    return countWay(n, memo);
}

int Triple()
{
    int test = 9;
    int sol = countWay(test);
    std::cout << "Hello World!\n";
}