#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void MakeTargetNum(const vector<int>& num, int curPos, int sum, int N, int& count) {
	if (curPos >= num.size()) {
		if (sum == N) {
			cout << "찾았다!" << endl;
			count++;
		}
		return;
	}

	if (sum == N) {
		cout << "찾았다!" << endl;
		count++;
		return;
	}

	MakeTargetNum(num, curPos + 1, sum + num[curPos], N, count);
	MakeTargetNum(num, curPos + 1, sum, N, count);
	MakeTargetNum(num, curPos + 1, sum - num[curPos], N, count);


}



int MakeTargetNumMs() {
	vector<int> nums{ 2,4,6,8 };
	int N = 12;
	int count = 0;
	MakeTargetNum(nums, 0, 0, N, count);

	if (count == 0)
		count = -1;

	return 0;
}