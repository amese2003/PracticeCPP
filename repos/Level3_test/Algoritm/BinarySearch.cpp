#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Searcing(vector<int> test, int targetNum) {

	sort(test.begin(), test.end());

	int start = 0, end = test.size() - 1;
	int mid = (start + end) / 2;

	while (start <= end) {
		mid = (start + end) / 2;

		if (test[mid] == targetNum)
			return mid;


		if (test[mid] > targetNum) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return -1;
}

int UseBinary() {

	vector<int> test{ 23,87,65,12,57,32,99,81 };

	int pos = Searcing(test, 32);

	return 0;
}