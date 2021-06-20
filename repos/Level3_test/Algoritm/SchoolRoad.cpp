#include <string>
#include <vector>

using namespace std;

int SchoolRoad(int m, int n, vector<vector<int>> puddles) {
	vector<vector<int>> route_count(n + 1, vector<int>(m + 1, 0));

	route_count[1][0] = 1;

	for (vector<int> puddle : puddles)
		route_count[puddle[1]][puddle[0]] = -1;


	for (int col = 1; col <= n; col++) {
		for (int row = 1; row <= m; row++) {
			if (route_count[col][row] == -1) {
				route_count[col][row] = 0;
				continue;
			}

			route_count[col][row] = (route_count[col - 1][row] + route_count[col][row - 1]) % 1000000007;
		}
	}

	return route_count[n][m];
}