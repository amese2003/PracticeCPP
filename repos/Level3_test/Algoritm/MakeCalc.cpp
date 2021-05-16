#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void MakeCal(vector<int> num, vector<int> cal, int pos, int sum, int& maxNum, int& minNum) {
	if (pos == num.size()) {
		maxNum = max(sum, maxNum);
		minNum = min(sum, minNum);
		return;
	}
	else {
		if (cal[0] > 0) {
			cal[0]--;
			MakeCal(num, cal, pos + 1, sum + num[pos], maxNum, minNum);
			cal[0]++;
		}
		if (cal[1] > 0) {
			cal[1]--;
			MakeCal(num, cal, pos + 1, sum - num[pos], maxNum, minNum);
			cal[1]++;
		}
		if (cal[2] > 0) {
			cal[2]--;
			MakeCal(num, cal, pos + 1, sum * num[pos], maxNum, minNum);
			cal[2]++;
		}
		if (cal[3] > 0) {
			cal[3]--;
			MakeCal(num, cal, pos + 1, sum / num[pos], maxNum, minNum);
			cal[3]++;
		}
	}
}

void Calculate() {
	vector<int> number{ 1,2,3,4,5,6 };
	vector<int> cal{ 2,1,1,1 };
	int max = INT32_MIN;
	int min = INT32_MAX;

	MakeCal(number, cal, 1, number[0], max, min);
}
