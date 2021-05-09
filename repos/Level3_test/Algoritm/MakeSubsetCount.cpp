#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int Calsubset(vector<vector<int>>& memo, int N, int R) {

	if (memo[N][R] > 0)
		return memo[N][R];

	if (N == R || R == 0) {
		memo[N][R] = 1;
		return memo[N][R];
	}

	return memo[N][R] = Calsubset(memo, N - 1, R - 1) + Calsubset(memo, N - 1, R);
}


int MakeSubsetCount() {
	vector<vector<int>> memo(21, vector<int>(21, 0));

	int answer = Calsubset(memo, 5, 3);

	return 0;
}