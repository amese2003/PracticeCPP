#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void NFactorial2(int N) {
	vector<__int64> factorMemo(N + 1, 0);

	factorMemo[1] = 1;
	for (int i = 2; i <= N; i++) {
		factorMemo[i] = factorMemo[i - 1] * i;
	}


	__int64 targetNum = factorMemo[N];
	vector<int> usedCount(N + 1, 0);

	for (int i = 2; i <= N; i++) {

		int value = i;
		int share = 2;


		while (value > 1) {
			if (value % share == 0) {
				usedCount[share]++;
				value /= share;
			}
			else {
				share++;
			}
		}
	}
}

