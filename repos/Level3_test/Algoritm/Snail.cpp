#include <string>
#include <vector>

using namespace std;

vector<int> Snail(int n) {
    vector<int> answer;

    int dir = 0;
    int col = 0, row = 0;

    int num = 0;
    vector<vector<int>> pyramid(n, vector<int>(n, 0));
    int count = 0;


    while (count < 3) {

        int nextCol, nextRow;


        if (pyramid[col][row] == 0) {
            pyramid[col][row] = ++num;
            count = 0;
        }
        else
            count++;

        switch (dir)
        {
        case 0:
            nextCol = col + 1;

            if (nextCol < n && pyramid[nextCol][row] == 0)
                col = nextCol;
            else
                dir = 1;
            break;
        case 1:
            nextRow = row + 1;

            if (nextRow < n && pyramid[col][nextRow] == 0)
                row = nextRow;
            else
                dir = 2;
            break;
        case 2:
            nextRow = row - 1;
            nextCol = col - 1;

            if (nextCol > 0 && nextRow > 0 && pyramid[nextCol][nextRow] == 0) {
                col = nextCol;
                row = nextRow;
            }
            else
                dir = 0;
            break;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (pyramid[i][j] != 0)
                answer.push_back(pyramid[i][j]);
            else
                break;
        }
    }


    return answer;
}