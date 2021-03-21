#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Tempature(vector<int> num, int K) {
	int sum = 0;
	int answer = 0;

	for (int i = 0; i < K; i++)
		sum += num[i];

	answer = sum;

	for (int i = K; i < num.size(); i++) {
		sum -= num[i - K];
		sum += num[i];

		if (sum > answer)
			answer = sum;
	}

	return answer;
}

int tempatur() {
	Tempature({ 3,-2,-4,-9,0,3,7,13,8,-3 }, 2);
	return 0;
}