#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void QuickSort(vector<int>& nums, int start, int end) {

	if (start >= end) return;

	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {

		while (left <= end && nums[pivot] >= nums[left])
			left++;

		while (right > start && nums[pivot] < nums[right])
			right--;


		if (left > right) {
			int temp = nums[right];
			nums[right] = nums[pivot];
			nums[pivot] = temp;
		}
		else {
			int temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
		}
	}

	QuickSort(nums, start, right - 1);
	QuickSort(nums, right + 1, end);
}


int UseQuick() {
	vector<int> nums{ 13,5,11,7,23,15 };

	QuickSort(nums, 0, nums.size() - 1);

	return 0;
}