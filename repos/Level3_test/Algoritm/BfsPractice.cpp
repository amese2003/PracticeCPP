#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void BFSPractice(vector<vector<int>> node) {

	queue<int> find;
	find.push(1);

	while (find.empty() == false) {

		int cur = find.front();
		find.pop();

		cout << cur << " ";

		for (int i = 0; i < node[cur].size(); i++) {
			find.push(node[cur][i]);
		}

	}

	cout << endl;
}


int BfsPractice() {

	const int N = 7;
	vector<vector<int>> node(N + 1);

	node[1].push_back(2);
	node[1].push_back(3);

	node[2].push_back(4);
	node[2].push_back(5);

	node[3].push_back(6);
	node[3].push_back(7);

	BFSPractice(node);

	return 0;
}