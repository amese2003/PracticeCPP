#include <string>
#include <vector>

using namespace std;

int SchoolRoute(int m, int n, vector<vector<int>> puddles) {
	int map[101][101] = { 0, };
	int root[101][101];

	root[1][0] = 1;

	for (auto puddle : puddles) {
		map[puddle[1]][puddle[0]] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (map[i][j] == -1)
				root[i][j] = 0;
			else
				root[i][j] = (root[i - 1][j] + root[i][j - 1]) % 1000000007;
		}
	}
	return root[n][m];
}