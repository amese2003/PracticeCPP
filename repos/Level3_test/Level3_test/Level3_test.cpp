// Level3_test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<int>> root_u(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> root_l(m + 1, vector<int>(n + 1, 0));

    root_u[1][1] = root_l[1][1] = 1;

    for (int col = 1; col <= m; col++) {
        for (int row = 1; row <= n; row++) {          
            /*if (city_map[col - 1][row - 1] == 0) {
                root_u[col][row] += (root_u[col - 1][row] + root_l[col][row - 1]) % MOD;
                root_l[col][row] += (root_u[col - 1][row] + root_l[col][row - 1]) % MOD;
            }
            else if (city_map[col - 1][row - 1] == 1) {
                root_u[col][row] = 0;
                root_l[col][row] = 0;
            }
            else {
                root_u[col][row] += root_u[col - 1][row];
                root_l[col][row] += root_l[col][row - 1];
            }*/


            switch (city_map[col - 1][row - 1])
            {
                case 0:
                    root_u[col][row] += (root_u[col - 1][row] + root_l[col][row - 1]) % MOD;
                    root_l[col][row] += (root_u[col - 1][row] + root_l[col][row - 1]) % MOD;
                    break;
                case 1:
                    root_u[col][row] = 0;
                    root_l[col][row] = 0;
                    break;
                case 2:
                    root_u[col][row] += root_u[col - 1][row];
                    root_l[col][row] += root_l[col][row - 1];
                    break;
            }
        }
    }

    return root_u[m][n];
}

int main()
{
    int temp = solution(3, 6, { {0, 2, 0, 0, 0, 2}, { 0, 0, 2, 0, 1, 0 }, { 1, 0, 0, 2, 2, 0 } });
    std::cout << temp;
}