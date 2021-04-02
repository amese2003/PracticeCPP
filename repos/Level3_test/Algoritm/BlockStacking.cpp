#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int BlockStacking(vector<int> front, vector<int> right) {

	vector<vector<int>> panel(front.size(), vector<int>(right.size(), 0));
	int blockCount = 0;

	for (int col = 0; col < right.size(); col++) {
		for (int row = 0; row < front.size(); row++) {
			panel[col][row] = front[row];

			int temp = right[right.size() - 1 - col];

			if (panel[col][row] > temp)
				panel[col][row] = temp;

			blockCount += panel[col][row];
		}
	}

	return blockCount;
}



int UseBlockStacking() {

	vector<int> front{ 2,0,3,1 };
	vector<int> right{ 1,1,2,3 };

	int temp = BlockStacking(front, right);


	return 0;
}