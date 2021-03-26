#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void InversionSequence(vector<int>& test) {
	vector<int> ans(test.size() + 1, 0);

	for (int i = 0; i < test.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (test[i] < test[j])
				ans[test[i]]++;
		}
	}
}

int Inversion() {
	vector<int> test{ 4,8,6,2,5,1,3,7 };
	InversionSequence(test);
	return 0;
}