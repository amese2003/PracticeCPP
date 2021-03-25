#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void InsertSort(vector<int>& test) {

	for (int i = 0; i < test.size(); i++) {
		for (int j = i + 1; j < test.size(); j++) {

			if (test[i] > test[j]) {
				int temp = test[j];
				test[j] = test[i];
				test[i] = temp;
			}
		}
	}
}
