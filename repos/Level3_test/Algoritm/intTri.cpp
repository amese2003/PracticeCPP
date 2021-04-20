#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TriInt(vector<vector<int>> triangle) {
	int max_num = 0;
	vector<vector<int>> max_result = triangle;

	for (int col = 1; col < triangle.size(); col++) {
		for (int row = 0; row < triangle[col].size(); row++) {
			if (row == 0) {
				max_result[col][row] += max_result[col - 1][row];
				continue;
			}

			if (row == triangle[col].size() - 1) {
				max_result[col][row] += max_result[col - 1][row - 1];
				continue;
			}

			max_result[col][row] = max(max_result[col - 1][row - 1] + triangle[col][row], max_result[col - 1][row] + triangle[col][row]);
		}
	}

	for (int i = 0; i < max_result[max_result.size() - 1].size(); i++)
		max_num = max(max_num, max_result[triangle.size() - 1][i]);

	return max_num;
}