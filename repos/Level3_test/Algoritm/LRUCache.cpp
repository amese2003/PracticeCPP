#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


void LRU(vector<int>& test) {

	int first = 3;

	auto it = find(test.begin(), test.end(), first);

	if (it == test.end()) {

		for (int i = test.size() - 1; i > 0; i--) {
			test[i] = test[i - 1];
		}

		test[0] = first;
	}
	else {

		int i = 0;
		for (i = 0; i < test.size(); i++) {
			if (test[i] == first)
				break;
		}


		for (i; i > 0; i--) {
			test[i] = test[i - 1];
		}

		test[0] = first;

	}

}


int UseCache() {
	vector<int> test{ 5,2,3,1,6 };
	LRU(test);
	return 0;
}