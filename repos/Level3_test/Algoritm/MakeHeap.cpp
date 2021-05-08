#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> MaxHeap(vector<int> heapList) {

	vector<int> sortHeap;

	for (int i = 0; i < heapList.size(); i++) {

		int data = heapList[i];
		int pos = sortHeap.size();
		sortHeap.push_back(data);

		while (pos > 0) {
			int next = (pos - 1 == 0) ? 0 : (pos - 1) / 2;

			if (sortHeap[pos] < sortHeap[next])
				break;

			int temp = sortHeap[next];
			sortHeap[next] = sortHeap[pos];
			sortHeap[pos] = temp;

			pos = next;
		}
	}

	return sortHeap;
}


int CheckHeap() {

	vector<int> HeapList{ 5,3,2,1,4,6,7 };
	vector<int> ans = MaxHeap(HeapList);
	return 0;
}