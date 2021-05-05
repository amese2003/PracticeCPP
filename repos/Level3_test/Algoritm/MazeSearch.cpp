#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const vector<int> dirY{ -1,0,1,0 };
const vector<int> dirX{ 0,1,0,-1 };


void FindTheWayBoard(vector<vector<int>>& board, int col, int row, int destCol, int destRow, int& count) {
	if (col == destCol && row == destRow) {
		count++;
		return;
	}

	for (int i = 0; i < dirY.size(); i++) {

		int nextY = col + dirY[i];
		int nextX = row + dirX[i];

		if (nextY < 0 || nextY >= board.size() || nextX < 0 || nextX >= board[0].size())
			continue;

		if (board[nextY][nextX] == 1)
			continue;

		board[nextY][nextX] = 1;
		FindTheWayBoard(board, nextY, nextX, destCol, destRow, count);
		board[nextY][nextX] = 0;
	}
}

int MazeSearchLogic() {

	vector<vector<int>> board = {
		{0,0,0,0,0,0,0},
		{0,1,1,1,1,1,0},
		{0,0,0,1,0,0,0},
		{1,1,0,1,0,1,1},
		{1,1,0,0,0,0,1},
		{1,1,0,1,1,0,0},
		{1,0,0,0,0,0,0}
	};

	int count = 0;
	board[0][0] = 1;
	FindTheWayBoard(board, 0, 0, 6, 6, count);

	return 0;
}