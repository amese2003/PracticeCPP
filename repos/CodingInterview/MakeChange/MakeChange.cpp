#include <iostream>
#include <vector>

using namespace std;

int makeChange(int amount, vector<int> changes, int index, vector<vector<int>>& memo) {
    if (memo[amount][index] > 0)
        return memo[amount][index];

    if (index >= changes.size() - 1)
        return 1;

    int changeAmount = changes[index];
    int way = 0;

    for (int i = 0; i * changeAmount <= amount; i++) {
        int remain = amount - changeAmount * i;
        way += makeChange(remain, changes, index + 1, memo);
    }

    memo[amount][index] = way;
    return way;
}

int makeChange(int n) {
    vector<int> changes = { 25, 10, 5, 1 };
    vector<vector<int>> map(n + 1, vector<int>(changes.size(), 0));

    return makeChange(n, changes, 0, map);
}



int main()
{
    int amount = makeChange(120);

    cout << amount << endl;
    std::cout << "Hello World!\n";
}