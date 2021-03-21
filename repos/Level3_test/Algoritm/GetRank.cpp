#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void GetRank(vector<int> num) {

	int start = num.size() - 1;
	vector<int> rank(num.size(), 1);

	for (int i = start; i >= 0; i--) {

		for (int j = i - 1; j >= 0; j--) {

			if (num[j] > num[i])
				rank[i]++;
		}
	}
}
