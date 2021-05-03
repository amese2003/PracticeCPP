#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> buffer(10, 0);

void sorting(int start, int mid, int end, vector<int>& data) {

	int left = start;
	int right = mid + 1;
	int pos = start;

	while (left <= mid && right <= end)
	{
		if (data[left] > data[right])
			buffer[pos++] = data[right++];
		else
			buffer[pos++] = data[left++];
	}

	while (left <= mid) {
		buffer[pos++] = data[left++];
	}

	while (right <= end)
		buffer[pos++] = data[right++];


	for (int i = start; i <= end; i++)
		data[i] = buffer[i];

}

void MergeSort(int start, int end, vector<int>& data) {

	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort(start, mid, data);
		MergeSort(mid + 1, end, data);
		sorting(start, mid, end, data);
	}
}


int UseMergeSecond() {

	vector<int> mergeSet{ 7,6,3,1,5,2,4,8 };
	MergeSort(0, mergeSet.size() - 1, mergeSet);
	return 0;
}