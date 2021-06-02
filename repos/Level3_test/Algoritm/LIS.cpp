#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void LongSubSet() {
	vector<int> arr{ 5,3,7,8,6,2,9,4 };
	vector<int> subCount(arr.size(), 0);
	int result = 0;
	subCount[0] = 1;

	for (int i = 1; i < arr.size(); i++) {
		int maxNum = 0;

		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j] && subCount[j] > maxNum) {
				maxNum = subCount[j];
			}
		}

		subCount[i] = maxNum + 1;

		if (subCount[i] > result)
			result = subCount[i];
	}

	cout << result << endl;
}
