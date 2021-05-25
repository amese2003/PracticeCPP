#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void IslandVisit(vector<vector<int>> map, int& count) {

	vector<vector<bool>> visit(map.size(), vector<bool>(map.size(), false));

	const int dirSize = 8;
	int dirY[dirSize]{ -1,-1,-1,0,0,1,1,1 };
	int dirX[dirSize]{ -1,0,1,-1,1,-1,0,1 };

	int maxSize = map.size();

	for (int col = 0; col < maxSize; col++) {
		for (int row = 0; row < maxSize; row++) {

			if (map[col][row] == 0)
				continue;

			if (visit[col][row] == true)
				continue;

			queue<pair<int, int>> check;
			count++;;
			check.push({ col, row });

			while (check.empty() == false) {
				int curCol = check.front().first;
				int curRow = check.front().second;

				visit[curCol][curRow] = true;
				check.pop();

				for (int i = 0; i < dirSize; i++) {

					int nextCol = curCol + dirY[i];
					int nextRow = curRow + dirX[i];

					if (nextCol < 0 || nextCol >= maxSize || nextRow < 0 || nextRow >= maxSize) {
						continue;
					}

					if (map[nextCol][nextRow] == 1 && visit[nextCol][nextRow] == false)
						check.push({ nextCol, nextRow });
				}
			}
		}
	}
}

void MakeIslane() {

	int count = 0;
	vector<vector<int>> map = {
		{1,1,0,0,0,1,0},
		{0,1,1,0,1,1,0},
		{0,1,0,0,0,0,0},
		{0,0,0,1,0,1,1},
		{1,1,0,1,1,0,0},
		{1,0,0,0,1,0,0},
		{1,0,1,0,1,0,0}
	};

	IslandVisit(map, count);
}