#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Dijkstar() {
	const int nodeCount = 6;
	vector<int> minCost(nodeCount + 1, INT32_MAX);
	int start = 1;

	vector<pair<int, int>> nodeData[nodeCount + 1];

	nodeData[1].push_back({ 2,12 });
	nodeData[1].push_back({ 3,4 });

	nodeData[2].push_back({ 1,2 });
	nodeData[2].push_back({ 3,5 });
	nodeData[2].push_back({ 5,5 });

	nodeData[3].push_back({ 4,5 });

	nodeData[4].push_back({ 2,2 });
	nodeData[4].push_back({ 5,5 });

	nodeData[6].push_back({ 4,5 });

	minCost[1] = 0;
	priority_queue<pair<int, int>> search;
	search.push({ start , 0 });

	while (search.empty() == false) {
		int curNode = search.top().first;
		int distance = -search.top().second;
		search.pop();

		if (minCost[curNode] < distance)
			continue;

		for (int i = 0; i < nodeData[curNode].size(); i++) {
			int nextNode = nodeData[curNode][i].first;
			int nextCost = nodeData[curNode][i].second;

			int sum = distance + nextCost;

			if (sum < minCost[nextNode]) {
				minCost[nextNode] = sum;
				search.push({ nextNode, -sum });
			}
		}
	}


	for (int i = 1; i < minCost.size(); i++) {
		cout << minCost[i] << " ";
	}
	cout << endl;
}