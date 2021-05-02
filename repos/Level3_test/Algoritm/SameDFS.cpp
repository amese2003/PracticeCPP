#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void CheckDFS(int total, int pos, int curSum, const vector<int>& set) {
	if (curSum > total / 2)
		return;

	if (pos >= set.size()) {
		if (curSum == (total - curSum)) {
			cout << "Ã£¾Ò´Ù!" << endl;
		}

		return;
	}

	CheckDFS(total, pos + 1, curSum + set[pos], set);
	CheckDFS(total, pos + 1, curSum, set);
}



int SameDFS() {

	vector<int> subset{ 1,3,5,6,7,10 };

	int total = 0;

	for (size_t i = 0; i < subset.size(); i++) {
		total += subset[i];
	}

	CheckDFS(total, 0, 0, subset);

	return 0;
}