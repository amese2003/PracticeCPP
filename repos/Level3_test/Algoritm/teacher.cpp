#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool IsCorrect(int N, int solve) {

	int correct = (N * (N + 1)) / 2;

	if (solve == correct)
		return true;

	return false;
}

int solution_teacher() {

	vector<pair<int, int>> num{ {10,55}, {20,350}, {100,5050} };
	vector<bool> check(num.size(), false);

	for (int i = 0; i < num.size(); i++) {

		check[i] = IsCorrect(num[i].first, num[i].second);

	}


	return 0;
}