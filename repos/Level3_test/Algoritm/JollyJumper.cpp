#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool JollyJumper(vector<int> nums) {

	vector<bool> check(nums.size(), false);

	for (int i = 1; i < nums.size(); i++) {
		int num = abs(nums[i] - nums[i - 1]);
		check[num] = true;
	}

	auto iter = find(check.begin() + 1, check.end(), false);

	if (iter == check.end())
		return true;

	return false;
}
