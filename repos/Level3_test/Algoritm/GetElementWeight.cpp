#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int TotalWeight(string element) {

	unordered_map<char, int> weight;
	weight['C'] = 12;
	weight['H'] = 1;

	stack<char> check;
	int answer = 0;

	for (int i = 0; i < element.length(); i++) {
		if (element[i] >= 'A' && element[i] <= 'Z') {
			if (!check.empty()) {
				char ele = check.top();
				check.pop();
				answer += weight[ele];
			}

			check.push(element[i]);
		}

		if (element[i] >= '0' && element[i] <= '9') {
			int count = element[i] - '0';
			char ele = check.top();
			check.pop();
			answer += (weight[ele] * count);
		}
	}

	return answer;
}
