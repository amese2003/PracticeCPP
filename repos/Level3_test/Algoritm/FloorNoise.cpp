#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void Reset(int* count) {
	*count = 0;
}

int NoiseTime(vector<int> check, int maximum) {

	int count = 0;
	int maxTick = 0;

	for (int i = 0; i < check.size(); i++) {
		maxTick = max(maxTick, (check[i] >= maximum) ? ++count : count);

		if (check[i] < maximum)
			Reset(&count);

	}

	return maxTick;
}

int FloorNoise() {
	int temp = NoiseTime({ 23,17,120,34,112,136,1,100,101,113 }, 90);

	return 0;
}