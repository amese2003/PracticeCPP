#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> memo(n + 1, 0);
    memo[1] = 1;
    memo[2] = 2;

    for (int i = 3; i <= n; i++) {
        memo[i] = (memo[i - 1] + memo[i - 2]) % 1234567;
    }

    return memo[n];
}

int main()
{
    __int64 ans = solution(4);
    cout << ans << endl;

    std::cout << "Hello World!\n";
}