#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> MergePractice(vector<int> arr1, vector<int> arr2) {

	vector<int> merge(arr1.size() + arr2.size(), 0);
	int leftpos = 0;
	int rightpos = 0;

	int mergePos = 0;

	for (int i = 0; i < merge.size(); i++) {

		if (leftpos >= arr1.size()) {
			merge[i] = arr2[rightpos++];
			continue;
		}

		if (rightpos >= arr2.size()) {
			merge[i] = arr1[leftpos++];
			continue;
		}


		if (arr1[leftpos] < arr2[rightpos]) {
			merge[i] = arr1[leftpos++];
		}
		else if (arr1[leftpos] > arr2[rightpos]) {
			merge[i] = arr2[rightpos++];
		}
		else {
			merge[i] = arr1[leftpos++];
			merge[++i] = arr2[rightpos++];
		}
	}

	return merge;
}

int UseMerge() {

	vector<int> arr1{ 1,3,5 };
	vector<int> arr2{ 2,3,6,7,9 };

	vector<int> merge = MergePractice(arr1, arr2);
	return 0;
}