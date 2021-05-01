#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void MakeSubSet(int N, int cur, vector<int> curSet, vector<vector<int>>& subSet) {
	if (cur > N) {
		subSet.push_back(curSet);
		return;
	}

	vector<int> containData = curSet;
	vector<int> nonContainData = curSet;

	containData.push_back(cur);

	MakeSubSet(N, cur + 1, containData, subSet);
	MakeSubSet(N, cur + 1, nonContainData, subSet);
}

int CheckSubset() {
	vector<vector<int>> subSet;
	MakeSubSet(3, 1, {}, subSet);

	return 0;
}