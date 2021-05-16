#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Search(vector<pair<int, int>> table, int day, int cost, int& result) {
	if (day == table.size()) {
		result = max(cost, result);
		return;
	}
	else {
		if (day + table[day].first <= table.size())
			Search(table, day + table[day].first, cost + table[day].second, result);

		Search(table, day + 1, cost, result);
	}
}


void MakeVaction() {
	const int N = 7;
	int maxCost = 0;

	vector<pair<int, int>> table;
	vector<bool> visit(N, false);

	table.push_back({ 2,20 });
	table.push_back({ 2,10 });
	table.push_back({ 3,15 });
	table.push_back({ 3,20 });
	table.push_back({ 2,30 });
	table.push_back({ 2,20 });
	table.push_back({ 1,10 });

	Search(table, 0, 0, maxCost);
}
