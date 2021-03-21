#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Counting3_1(int N) {

	int answer = 0;

	for (int i = 3; i <= N; i++) {

		int value = i;

		while (value > 0) {
			if (value % 10 == 3)
				answer++;

			value /= 10;
		}
	}

	return answer;
}