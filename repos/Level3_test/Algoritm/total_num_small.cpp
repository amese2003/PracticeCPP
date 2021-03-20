#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int total_natureNum_small(int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		int num = i;
		while (num > 0) {
			count++;
			num /= 10;
		}
	}

	return count;
}