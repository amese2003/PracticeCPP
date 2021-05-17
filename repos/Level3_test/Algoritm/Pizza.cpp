#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void SearchPizza(int count, int maxNum, vector<pair<int, int>> pizza, vector<pair<int, int>> home, vector<int> make, int& result) {
	if (count == maxNum) {

		int sum = 0;
		for (int i = 0; i < home.size(); i++) {

			int x1 = home[i].first;
			int y1 = home[i].second;

			int distance = 2100000000;
			for (int j = 0; j < maxNum; j++) {

				int x2 = pizza[make[j]].first;
				int y2 = pizza[make[j]].second;

				distance = min(distance, abs(x2 - x1) + abs(y2 - y1));
			}

			sum = sum + distance;
		}

		if (sum < result)
			result = sum;

	}
	else {
		for (int i = count; i < pizza.size(); i++) {
			make[count] = i;
			SearchPizza(count + 1, maxNum, pizza, home, make, result);
		}

	}
}

void Pizza() {
	const int N = 4;
	int maxPizza = 4;
	vector<vector<int>> node{
		{0,1,2,0},
		{1,0,2,1},
		{0,2,1,2},
		{2,0,1,2}
	};

	vector<pair<int, int>> home;
	vector<pair<int, int>> pizza;

	for (int col = 0; col < N; col++) {
		for (int row = 0; row < N; row++) {
			if (node[col][row] == 1)
				home.push_back({ col, row });

			if (node[col][row] == 2)
				pizza.push_back({ col, row });
		}
	}

	vector<int> makePizza(maxPizza);
	int min = 2100000000;

	SearchPizza(0, maxPizza, pizza, home, makePizza, min);
}