#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> GetInterSection(vector<int> a1, vector<int> a2) {

	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());

	vector<int> ans;

	int left = 0;
	int right = 0;


	int maximum = max(a1.size(), a2.size());

	while (left < a1.size() && right < a2.size()) {

		if (a1[left] < a2[right]) {
			left++;
			continue;
		}

		if (a1[left] > a2[right]) {
			right++;
			continue;
		}

		if (a1[left] == a2[right]) {
			ans.push_back(a1[left++]);
			right++;
		}
	}

	return ans;
}

int InterSection() {

	vector<int> arr1{ 2,7,10,5,3 };
	vector<int> arr2{ 3,10,5,17,12 };

	vector<int> ans = GetInterSection(arr1, arr2);
	return 0;
}