#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void FindWay(vector<pair<int, int>> data[], vector <bool>& visit, int cur, int dest, int curCost, int& maxCost) {
	if (cur == dest) {
		maxCost = min(curCost, maxCost);
		return;
	}

	for (int i = 0; i < data[cur].size(); i++) {

		int next = data[cur][i].first;
		int cost = data[cur][i].second;

		if (visit[next] == true)
			continue;

		visit[next] = true;
		FindWay(data, visit, next, dest, curCost + cost, maxCost);
		visit[next] = false;

	}
}




int LassCostWay() {
	const int N = 5;

	vector<pair<int, int>> sum[N + 1];
	vector <bool> visit(N + 1, false);

	int cost = INT32_MAX;

	sum[1].push_back({ 2,12 });
	sum[1].push_back({ 3,6 });
	sum[1].push_back({ 4,10 });

	sum[2].push_back({ 5,2 });
	sum[2].push_back({ 3,2 });

	sum[3].push_back({ 4,3 });

	sum[4].push_back({ 2,2 });
	sum[4].push_back({ 5,5 });

	visit[1] = true;
	FindWay(sum, visit, 1, 5, 0, cost);

	return 0;
}