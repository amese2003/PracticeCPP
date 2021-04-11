#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int CheckTerriory(vector<vector<int>> map, int rowSize, int colSize) {

	vector<vector<int>> memo(map.size(), vector<int>(map[0].size(), 0));
	vector<vector<int>> dy(map.size(), vector<int>(map[0].size(), 0));

	int maxTerriory = INT32_MIN;

	for (int col = 0; col <= colSize; col++) {
		for (int row = 0; row < map[0].size(); row++) {

			if (col == colSize && row == rowSize)
				break;

			memo[col][row] = ((row - 1 >= 0) ? memo[col][row - 1] : 0) + map[col][row];
			dy[col][row] = ((col - 1 >= 0) ? dy[col - 1][row] : 0) + memo[col][row];
		}
	}


	for (int col = colSize; col < map.size(); col++) {
		int row = (col == colSize) ? rowSize : 0;
		for (row; row < map[0].size(); row++) {
			dy[col][row] = map[col][row];
			if (col - 1 >= 0) {
				dy[col][row] += dy[col - 1][row];

				if (row - 1 >= 0)
					dy[col][row] += (dy[col][row - 1] - dy[col - 1][row - 1]);
			}


			if (row >= rowSize && col >= colSize) {
				int terriory = dy[col][row] - dy[col - colSize][row] - dy[col][row - rowSize] + dy[col - colSize][row - rowSize];
				maxTerriory = max(maxTerriory, terriory);
			}
		}
	}

	return maxTerriory;
}

int CheckTerritory() {

	vector<vector<int>> map{
		{3,5,1,3,1,3,2},
		{1,2,1,3,1,1,2},
		{1,3,1,5,1,3,4},
		{5,1,1,3,1,3,2},
		{3,1,1,3,1,1,2},
		{1,3,1,3,1,2,2}
	};

	int ans = CheckTerriory(map, 3, 2);
	return 0;
}