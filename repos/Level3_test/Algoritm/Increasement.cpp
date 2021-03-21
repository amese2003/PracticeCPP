#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int incresement(vector<int> num) {
	int answer = 0;
	int count = 1;

	for (int i = 1; i < num.size(); i++) {
		if (num[i] >= num[i - 1])
			count++;
		else {
			answer = max(answer, count);
			count = 1;
		}
	}

	return answer;
}
