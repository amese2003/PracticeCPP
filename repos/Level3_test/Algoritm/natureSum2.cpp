#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> natureSum(int target) {

	vector<vector<int>> sumList;

	int sum = 0;
	int count = 0;

	while (target > sum) {
		sum += ++count;

		int check = target - sum;
		if (count > 1 && check % count == 0) {

			int share = check / count;
			vector<int> shareList;

			for (int i = 1; i <= count; i++) {
				shareList.push_back(i + share);
			}

			sumList.push_back(shareList);
		}
	}


	return sumList;
}


int natureSum2() {
	vector<vector<int>> test = natureSum(15);

	return 0;
}