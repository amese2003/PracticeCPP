#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int CheckMusic(vector<int> test, int count) {
	int total = 0;



	for (int i = 0; i < test.size(); i++)
		total += test[i];

	int start = 0;
	int end = total;


	int minRecord = count;
	int mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;


		int track = 1;
		int recorded = 0;
		for (int i = 0; i < test.size(); i++) {
			recorded += test[i];

			if (recorded > mid) {
				track++;
				recorded = test[i];
			}
		}

		if (minRecord < track)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return mid;
}

int CheckRecord() {

	vector<int> task{ 1,2,3,4,5,6,7,8,9 };
	int ans = CheckMusic(task, 3);

	return 0;
}