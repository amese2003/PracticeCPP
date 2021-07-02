#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ShortWay(vector<vector<int>> maps)
{
	using Pos = pair<int, int>;

	vector<vector<int>> move_dis(maps.size(), vector<int>(maps[0].size(), 0));
	vector<Pos> dir = { make_pair(0, -1), make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0) };

	queue<Pos> route;
	move_dis[0][0] = 1;
	route.push(make_pair(0, 0));

	while (!route.empty()) {
		int col = route.front().first;
		int row = route.front().second;
		route.pop();


		if (col == maps.size() - 1 && row == maps[0].size() - 1)
			return move_dis[maps.size() - 1][maps[0].size() - 1];


		for (int i = 0; i < 4; i++) {
			int new_col = col + dir[i].first;
			int new_row = row + dir[i].second;

			if (new_col < 0 || new_col > maps.size() - 1 || new_row < 0 || new_row > maps[0].size() - 1) continue;
			if (!maps[new_col][new_row] || move_dis[new_col][new_row]) continue;

			move_dis[new_col][new_row] += move_dis[col][row] + 1;
			route.push(make_pair(new_col, new_row));
		}
	}

	return -1;
}