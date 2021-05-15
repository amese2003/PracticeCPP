#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;


void MakeSubSetDFS(int pos, int maxSize, vector<vector<int>>& result, vector<int> input, vector<int> sub, vector<bool> visit) {
	if (sub.size() == maxSize) {
		result.push_back(sub);
		return;
	}
	else {

		for (int i = 0; i < input.size(); i++) {

			if (visit[i] == false) {
				visit[i] = true;
				sub.push_back(input[i]);
				MakeSubSetDFS(pos + 1, maxSize, result, input, sub, visit);
				sub.pop_back();
				visit[i] = false;
			}
		}

	}
}


void ShowSubset() {
	const int count = 4;
	const int maxSize = 3;

	vector<vector<int>> result;

	vector<int> input{ 1,3,6,7 };
	vector<int> sub;
	vector<bool> visit(input.size(), false);

	for (int i = 0; i < count; i++) {
		visit[i] = true;
		sub.push_back(input[i]);
		MakeSubSetDFS(1, maxSize, result, input, sub, visit);
		sub.pop_back();
		visit[i] = false;
	}



}

