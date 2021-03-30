#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int volunteer(int N, int K) {

	vector<int> num(N, 0);
	int count = N;


	int pos = 0;
	int currentNum = 0;

	while (count > 1) {
		int curPos = pos;
		pos = (pos + 1) % N;

		if (num[curPos] == 1)
			continue;

		int yell = currentNum++;

		if (yell == K - 1) {
			num[curPos] = 1;
			count--;
			currentNum = 0;
		}
	}

	return 0;
}

int Princess() {
	int ans = volunteer(8, 3);
	return 0;
}
