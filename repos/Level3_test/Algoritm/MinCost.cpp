#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void GetCostBottomUp() {

	vector<vector<int>> map{
		{3,3,5},
		{2,3,4},
		{6,5,2}
	};

	vector<vector<int>> result(map.size(), vector<int>(map[0].size(), INT32_MAX));
	result[0][0] = map[0][0];

	int dirY[] = { 1, 0 };
	int dirX[] = { 0, 1 };

	for (int col = 0; col < map.size(); col++) {
		for (int row = 0; row < map[0].size(); row++) {


			for (int dir = 0; dir < 2; dir++) {
				int nextY = col + dirY[dir];
				int nextX = row + dirX[dir];


				if (nextY >= map.size() || nextX >= map[0].size())
					continue;

				result[nextY][nextX] = min(result[nextY][nextX], result[col][row] + map[nextY][nextX]);
			}
		}
	}
}