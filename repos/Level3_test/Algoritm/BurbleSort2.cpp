#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void BubleSort2(vector<int>& test) {

	for (int i = 0; i < test.size(); i++) {

		for (int j = 1; j < test.size(); j++) {

			if (test[j] < 0 && test[j - 1] >= 0) {
				int temp = test[j - 1];
				test[j - 1] = test[j];
				test[j] = temp;
			}
		}
	}
}

