#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void LisLine() {
	vector<int> left{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> right{ 4,1,2,3,9,7,5,6,10,8 };

	vector<int> line(right.size(), 0);

	int count = 0;

	line[0] = 1;

	for (int i = 1; i < right.size(); i++) {
		int max = 0;

		for (int j = left.size() - 1; j >= 0; j--) {
			if (right[i] != left[j])
				continue;

			if (right[i - 1] > right[i]) {
				line[i] = line[i - 1];
			}
			else {
				line[i] = line[i - 1] + 1;
			}
		}
	}
}