#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int checkPrime_Large(int N) {

	vector<bool> check(N + 1, false);

	for (int i = 2; i < N; i++) {
		if (check[i] == true)
			continue;

		for (int j = i + i; j < N; j += i) {
			check[j] = true;
		}
	}

	return 0;
}