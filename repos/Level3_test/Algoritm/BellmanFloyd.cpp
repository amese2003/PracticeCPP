#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Floyd() {
	const int nodeCount = 5;
	vector<pair<int, int>> nodeData[nodeCount + 1];


	nodeData[1].push_back({ 2,5 });
	nodeData[1].push_back({ 3,4 });

	nodeData[2].push_back({ 3,-3 });
	nodeData[2].push_back({ 5,13 });

	nodeData[3].push_back({ 4,5 });

	nodeData[4].push_back({ 2,3 });
	nodeData[4].push_back({ 5,7 });

	vector<vector<int>> minCost(nodeCount + 1, vector<int>(nodeCount + 1, 10000000));
	vector<vector<int>> result(nodeCount + 1, vector<int>(nodeCount + 1, 0));

	for (int i = 1; i <= nodeCount; i++) {

		minCost[i][i] = 0;

		for (int j = 0; j < nodeData[i].size(); j++) {
			int nextNode = nodeData[i][j].first;
			int nextCost = nodeData[i][j].second;

			if (i == nextNode)
				minCost[i][nextNode] = 0;
			else
				minCost[i][nextNode] = nextCost;
		}
	}

	for (int i = 1; i <= nodeCount; i++) {
		for (int j = 1; j <= nodeCount; j++) {
			result[i][j] = minCost[i][j];
		}
	}

	for (int buffer = 1; buffer <= nodeCount; buffer++) {

		for (int start = 1; start <= nodeCount; start++) {

			for (int end = 1; end <= nodeCount; end++) {

				if (result[start][end] > result[start][buffer] + result[buffer][end])
					result[start][end] = result[start][buffer] + result[buffer][end];
			}
		}
	}

}

void belmanFord() {
	const int nodeCount = 5;
	vector<pair<int, int>> nodeData[nodeCount + 1];

	int start = 1;
	int end = 5;

	nodeData[1].push_back({ 2,5 });
	nodeData[1].push_back({ 3,4 });

	nodeData[2].push_back({ 3,-3 });
	nodeData[2].push_back({ 5,13 });

	nodeData[3].push_back({ 4,5 });

	nodeData[4].push_back({ 2,3 });
	nodeData[4].push_back({ 5,7 });

	vector<vector<int>> minCost(nodeCount + 1, vector<int>(nodeCount + 1, 2100000000));
	vector<int> result(nodeCount + 1, 2100000000);

	for (int i = 1; i <= nodeCount; i++) {

		minCost[i][i] = 0;

		for (int j = 0; j < nodeData[i].size(); j++) {
			int nextNode = nodeData[i][j].first;
			int nextCost = nodeData[i][j].second;

			if (i == nextNode)
				minCost[i][nextNode] = 0;
			else
				minCost[i][nextNode] = nextCost;
		}
	}

	result[start] = 0;

	for (int i = 1; i <= nodeCount; i++) {

		if (nodeData[i].size() == 0)
			continue;

		for (size_t j = 0; j < nodeData[i].size(); j++) {

			int next = nodeData[i][j].first;
			int cost = nodeData[i][j].second;

			if (result[next] > result[i] + cost)
				result[next] = result[i] + cost;

		}
	}


}
