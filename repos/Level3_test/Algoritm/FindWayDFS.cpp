#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void FindWay(vector<pair<int, int>> nodeData[], vector<bool>& visit, int& result, int cur, int end) {
	if (cur == end) {
		result++;
		cout << "Ã£¾Ò´Ù!" << endl;
		return;
	}

	vector<pair<int, int>> curNode = nodeData[cur];

	for (int i = 0; i < curNode.size(); i++) {
		if (visit[curNode[i].first] == true)
			continue;

		visit[curNode[i].first] = true;
		FindWay(nodeData, visit, result, curNode[i].first, end);
		visit[curNode[i].first] = false;

	}
}



int FindWayDFS() {


	const int N = 5;

	vector<pair<int, int>> sum[N + 1];
	int result = 0;
	vector<bool> visit(N + 1, 0);

	sum[1].push_back({ 2,7 });
	sum[1].push_back({ 3,4 });
	sum[1].push_back({ 4,0 });

	sum[2].push_back({ 1,2 });
	sum[2].push_back({ 3,5 });
	sum[2].push_back({ 5,5 });

	sum[3].push_back({ 4,5 });

	sum[4].push_back({ 2,2 });
	sum[4].push_back({ 5,5 });

	visit[1] = true;
	FindWay(sum, visit, result, 1, 5);

	return 0;
}