#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


int digit_sum(int x) {
	vector<int> Input{ 125, 15232,79,1325,97 };

	int maxNum = INT32_MIN;
	int answer = 0;

	for (int i = 0; i < Input.size(); i++) {
		int get = Input[i];
		int sum = 0;

		while (get > 0) {
			sum += (get % 10);
			get /= 10;
		}

		maxNum = max(maxNum, sum);
		if (maxNum == sum)
			answer = Input[i];
	}

	return answer;
}