//#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Sum(vector<int>& test, int size) {

	int track = 1;
	int recorded = 0;
	for (int i = 0; i < test.size(); i++) {
		if (recorded + test[i] > size) {
			track++;
			recorded = test[i];
		}
		else {
			recorded += test[i];
		}
	}

	return track;
}

int CheckMusic(vector<int> test, int count) {
	int total = 0;

	int max = INT32_MIN;

	for (int i = 0; i < test.size(); i++) {
		total += test[i];
		if (test[i] > max)
			max = test[i];
	}

	int start = 0;
	int end = total;


	int minRecord = count;
	int mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		if (mid >= max && Sum(test, count) <= count) {
			minRecord = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	return minRecord;
}

int CheckRecord() {

	vector<int> task{ 1,2,3,4,5,6,7,8,9 };
	int ans = CheckMusic(task, 9);

	return 0;
}