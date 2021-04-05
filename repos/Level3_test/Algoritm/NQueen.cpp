#include <string>
#include <vector>

using namespace std;

void PlaceQueens(int row, vector<int> columns, vector<vector<int>>& result);
bool CheckValid(vector<int> columns, int row1, int column1);
int GRID_SIZE;


int solution(int n) {
	int answer = 0;
	GRID_SIZE = n;
	vector<int> columns(GRID_SIZE);
	vector<vector<int>> result;

	PlaceQueens(0, columns, result);
	return result.size();
}


void PlaceQueens(int row, vector<int> columns, vector<vector<int>>& result) {

	if (row == GRID_SIZE)
		result.push_back(columns);
	else {
		for (int col = 0; col < GRID_SIZE; col++) {
			if (CheckValid(columns, row, col)) {
				columns[row] = col;
				PlaceQueens(row + 1, columns, result);
			}
		}
	}
}


bool CheckValid(vector<int> columns, int row1, int column1) {

	for (int row2 = 0; row2 < row1; row2++) {
		int column2 = columns[row2];

		if (column1 == column2)
			return false;

		int columnsDistance = abs(column2 - column1);
		int rowDistance = row1 - row2;

		if (columnsDistance == rowDistance)
			return false;
	}
	return true;
}