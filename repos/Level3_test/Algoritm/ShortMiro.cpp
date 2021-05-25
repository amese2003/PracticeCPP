#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int FindMiro(vector<vector<int>> map) {

	vector<vector<pair<int, int>>> visitFrom(map.size(), vector<pair<int, int>>(map.size()));
	vector<vector<int>> visitCount(map.size(), vector<int>(map.size(), 0));
	queue<pair<int, int>> visit;

	int dest = map.size() - 1;

	int dirY[4] = { -1,0,1,0 };
	int dirX[4] = { 0,1,0,-1 };

	visit.push({ 0,0 });

	while (visit.empty() == false) {
		int col = visit.front().first;
		int row = visit.front().second;
		visit.pop();

		if (col == dest && row == dest)
			break;

		for (int i = 0; i < 4; i++) {

			int nextCol = col + dirY[i];
			int nextRow = row + dirX[i];

			if (nextCol < 0 || nextCol >= map.size() || nextRow < 0 || nextRow >= map.size())
				continue;

			if (map[nextCol][nextRow] == 1)
				continue;

			visit.push({ nextCol,nextRow });
			visitFrom[nextCol][nextRow] = { col,row };
			visitCount[nextCol][nextRow] = visitCount[col][row] + 1;
		}
	}

	return 0;
}

void ShortMap() {
	const int mapSize = 7;
	vector<vector<int>> map{
		{0,0,0,0,0,0,0},
		{0,1,1,1,1,1,0},
		{0,0,0,1,0,0,0},
		{1,1,0,1,0,1,1},
		{1,1,0,1,0,0,0},
		{1,0,0,0,1,0,0},
		{1,0,1,0,0,0,0}
	};

	FindMiro(map);
}
