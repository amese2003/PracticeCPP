#include <iostream>
#include <vector>
#include <queue>
#define max(a,b) ((a < b) ? (b):(a));
#define min(a,b) ((a < b) ? (a):(b));

using namespace std;

class Drone {
public:
	int col;
	int row;
	int status;

	Drone() {
		col = 0;
		row = 0;
		status = 0;
	}

	Drone(int _col, int _row, int _status) {
		col = _col;
		row = _row;
		status = _status;
	}
};

int DroneMove(vector<vector<int>> board) {
	int MAX_SIZE = board.size();
	vector<vector<vector<int>>> visit(MAX_SIZE, vector<vector<int>>(MAX_SIZE, vector<int>(2, 0)));

	for (int col = 0; col < MAX_SIZE; col++) {
		for (int row = 0; row < MAX_SIZE; row++) {
			visit[col][row][0] = -1;
			visit[col][row][1] = -1;
		}
	}

	using Pos = pair<int, int>;
	vector<Pos> dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

	visit[0][0][0] = 0;

	queue<Drone> find_way;
	find_way.push(Drone(0, 0, 0));

	while (!find_way.empty()) {
		int col1 = find_way.front().col;
		int row1 = find_way.front().row;
		int status = find_way.front().status;

		int col2 = col1 + dir[status].second;
		int row2 = row1 + dir[status].first;

		int cost = visit[col1][row1][status];
		find_way.pop();

		for (int i = 0; i < 4; i++) {
			int next_col1 = col1 + dir[i].second;
			int next_row1 = row1 + dir[i].first;

			int next_col2 = col2 + dir[i].second;
			int next_row2 = row2 + dir[i].first;

			if (next_col1 < 0 || next_col1 >= MAX_SIZE || next_row1 < 0 || next_row1 >= MAX_SIZE) continue;
			if (next_col2 < 0 || next_col2 >= MAX_SIZE || next_row2 < 0 || next_row2 >= MAX_SIZE) continue;
			if (board[next_col1][next_row1] || board[next_col2][next_row2]) continue;
			if (visit[next_col1][next_row1][status] != -1) continue;

			visit[next_col1][next_row1][status] = cost + 1;
			find_way.push(Drone(next_col1, next_row1, status));
		}

		for (int rotate = 0; rotate < 2; rotate++) {
			for (int i = 0; i < 4; i++) {
				int next_col1 = col1;
				int next_row1 = row1;

				int next_col2 = col1 + dir[i].second;
				int next_row2 = row1 + dir[i].first;

				if (next_col2 < 0 || next_col2 >= MAX_SIZE || next_row2 < 0 || next_row2 >= MAX_SIZE) continue;

				int col_dis = abs(col2 - next_col2);
				int row_dis = abs(row2 - next_row2);

				if (col_dis != 1 || row_dis != 1) continue;
				if (board[next_col2][next_row2]) continue;

				int rotate_col = col1 ^ col2 ^ next_col2;
				int rotate_row = row1 ^ row2 ^ next_row2;

				if (board[rotate_col][rotate_row]) continue;

				if (next_col1 > next_col2) swap(next_col1, next_col2);
				if (next_row1 > next_row2) swap(next_row1, next_row2);

				int next_status = (status == 0) ? 1 : 0;

				if (visit[next_col1][next_row1][next_status] == -1) {
					visit[next_col1][next_row1][next_status] = cost + 1;
					find_way.push(Drone(next_col1, next_row1, next_status));
				}
			}

			swap(col1, col2);
			swap(row1, row2);
		}
	}

	int cost = min(visit[MAX_SIZE - 2][MAX_SIZE - 1][1], visit[MAX_SIZE - 1][MAX_SIZE - 2][0]);

	if (cost == -1)
		return max(visit[MAX_SIZE - 2][MAX_SIZE - 1][1], visit[MAX_SIZE - 1][MAX_SIZE - 2][0]);

	return cost;
}