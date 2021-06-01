#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void CutRope() {
	const int len = 4;

	vector<int> num(len + 1, 0);

	num[1] = 1;
	num[2] = 2;

	for (int i = 3; i <= len; i++) {
		num[i] = num[i - 1] + num[i - 2];
	}

	cout << num[len] << endl;
}
