#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void MaxScore() {

	int minute = 20;
	int count = 5;

	vector<vector<int>> table(count + 1, vector<int>(minute + 1, 0));
	vector<pair<int, int>> getScore{
		{0,0},
		{10,5},
		{25,12},
		{15,8},
		{6,3},
		{7,4}
	};

	for (int i = 1; i <= count; i++) {
		table[i] = table[i - 1];

		int solveTime = getScore[i].second;
		int solveScore = getScore[i].first;

		for (int j = solveTime; j <= minute; j++) {
			table[i][j] = max(table[i][j], table[i - 1][j - solveTime] + solveScore);
		}
	}
}