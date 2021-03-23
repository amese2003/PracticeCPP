#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int GetNum(vector<int>& test) {

	int num = 0;
	int current = 200;

	for (int i = 0; i < test.size(); i++) {

		if (current > test[i]) {
			current = test[i];
			num++;

			if (num == 3)
				break;
		}

	}

	return current;
}


void QuickSort2(vector<int>& test, int start, int end) {
	if (start >= end) return;

	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {

		if (left <= end && test[pivot] <= test[left])
			left++;

		if (right > start && test[pivot] > test[right])
			right--;


		if (left > right) {
			int temp = test[pivot];
			test[pivot] = test[right];
			test[right] = temp;
		}
		else {
			int temp = test[left];
			test[left] = test[right];
			test[right] = temp;
		}
	}

	QuickSort2(test, start, right - 1);
	QuickSort2(test, right + 1, end);

}

int Number3Get() {
	vector<int> test{ 80,96,75,82,96,92 };

	QuickSort2(test, 0, test.size() - 1);
	int get = GetNum(test);

	return 0;
}