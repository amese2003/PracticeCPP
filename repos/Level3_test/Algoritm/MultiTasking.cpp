#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int multitasking(vector<int> tasking, int powerOut) {
	int answer = 0;

	int tick = 0;

	int pos = 0;
	int execPos = 0;
	int size = tasking.size();
	int jobCount = size;


	while (tick < powerOut && jobCount > 0) {
		int cur = pos % size;

		if (tasking[cur] > 0) {
			tasking[cur]--;
			execPos = cur;

			if (tasking[cur] == 0)
				jobCount--;

			tick++;
		}

		pos++;
	}

	if (jobCount <= 0)
		return -1;

	while (tasking[execPos] == 0) {
		execPos = (execPos + 1) % size;
	}


	return execPos;
}


int UseTask() {
	vector<int> tasking{ 1,2,3 };
	int out = 5;
	int test = multitasking(tasking, out);
	return 0;
}