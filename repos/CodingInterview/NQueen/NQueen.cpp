#include <iostream>
#include <vector>

using namespace std;

const int grid_size = 4;

bool checkValid(vector<int> colums, int row1, int col1) {
    for (int row2 = 0; row2 < row1; row2++) {
        int col2 = colums[row2];

        if (col1 == col2)
            return false;

        int col_dis = abs(col2 - col1);
        int row_dis = row1 - row2;

        if (col_dis == row_dis)
            return false;
    }

    return true;
}


void placeQueens(int row, vector<int> &columns, vector<vector<int>>& result) {
    if (row == grid_size)
        result.push_back(columns);
    else {
        for (int col = 0; col < grid_size; col++) {
            if (checkValid(columns, row, col)) {
                columns[row] = col;
                placeQueens(row + 1, columns, result);
            }
        }
    }
}



int main()
{
    int answer = 0;
    vector<int> columns(grid_size);
    vector<vector<int>> result;

    placeQueens(0, columns, result);
    cout << result.size();
    std::cout << "Hello World!\n";
}