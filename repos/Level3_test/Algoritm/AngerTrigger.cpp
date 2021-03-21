#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int AngerTrigger(vector<int> height) {
	int answer = 0;
	int triggerMan = height[height.size() - 1];

	for (int i = height.size() - 1; i > 0; i--) {

		if (triggerMan < height[i]) {
			answer++;
			triggerMan = height[i];
		}
	}

	return answer;
}
