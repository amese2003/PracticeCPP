#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;



void Tomato() {

	const int colSize = 4;
	const int rowSize = 6;
	vector<vector<int>> tomato{
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,-1,0,1}
	};

	int dirY[4] = { -1, 0, 1, 0 };
	int dirX[4] = { 0, 1, 0, -1 };

	queue<pair<int, int>> tryVisit;
	int maxDay = 1;

	for (int col = 0; col < colSize; col++) {
		for (int row = 0; row < rowSize; row++) {

			if (tomato[col][row] == 1)
				tryVisit.push({ col, row });
		}
	}

	while (tryVisit.empty() == false) {
		int curCol = tryVisit.front().first;
		int curRow = tryVisit.front().second;
		tryVisit.pop();

		for (int i = 0; i < 4; i++) {
			int nextCol = curCol + dirY[i];
			int nextRow = curRow + dirX[i];

			if (nextCol < 0 || nextCol >= colSize || nextRow < 0 || nextRow >= rowSize)
				continue;

			if (tomato[nextCol][nextRow] != 0)
				continue;


			tryVisit.push({ nextCol, nextRow });
			tomato[nextCol][nextRow] = tomato[curCol][curRow] + 1;

			maxDay = max(maxDay, tomato[nextCol][nextRow]);
		}
	}

	cout << maxDay << endl;
}