#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int FarNode(int n, vector<vector<int>> edge) {
	int answer = 0;
	vector<int> cost(n + 1, 0);
	vector<vector<int>> root(n + 1);
	vector<bool> visit(n + 1, false);

	int max_cost = 0;
	queue<int> pathfind;


	for (int i = 0; i < edge.size(); i++) {
		root[edge[i][0]].push_back(edge[i][1]);
		root[edge[i][1]].push_back(edge[i][0]);
	}

	pathfind.push(1);
	cost[1] = 0;
	visit[1] = true;
	max_cost = 0;

	while (!pathfind.empty()) {
		int cur = pathfind.front();
		pathfind.pop();

		for (int i = 0; i < root[cur].size(); i++) {
			int next = root[cur][i];

			if (!visit[next]) {
				pathfind.push(root[cur][i]);
				visit[root[cur][i]] = true;
				cost[root[cur][i]] = cost[cur] + 1;
			}
		}
	}

	sort(cost.begin(), cost.end(), greater<int>());
	max_cost = cost.front();

	for (int i = 0; i < n; i++) {
		if (max_cost == cost[i]) answer++;
		else break;
	}

	return answer;
}