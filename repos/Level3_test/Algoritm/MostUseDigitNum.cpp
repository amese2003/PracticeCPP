#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int most_used_num(int n) {
	vector<int> used(10, 0);
	int answer = 0;

	int most_use = INT32_MIN;

	while (n > 0) {
		int getNum = n % 10;
		used[getNum]++;
		n /= 10;
	}

	for (int i = 1; i < 10; i++) {

		if (most_use < used[i]) {
			most_use = used[i];
			answer = i;
		}
	}

	return answer;
}