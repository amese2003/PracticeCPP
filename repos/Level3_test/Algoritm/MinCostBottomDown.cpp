#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int GetCost(const vector<vector<int>>& map, vector<vector<int>>& cost, int col, int row) {

	if (col == 0 && row == 0)
		return map[0][0];


	if (col < 0)
		return cost[0][row] = GetCost(map, cost, 0, row - 1) + map[0][row];
	else if (row < 0)
		return cost[col][0] = GetCost(map, cost, col - 1, 0) + map[col][0];
	else
		return cost[col][row] = min(GetCost(map, cost, col - 1, row) + map[col][row], GetCost(map, cost, col, row - 1) + map[col][row]);

}


void TopDownSearch() {
	vector<vector<int>> map{
		{3,3,5},
		{2,3,4},
		{6,5,2}
	};

	vector<vector<int>> cost(map.size(), vector<int>(map[0].size(), 0));

	int destY = map.size() - 1;
	int destX = map[0].size() - 1;

	int result = GetCost(map, cost, destY, destX);

	cout << result << endl;
}