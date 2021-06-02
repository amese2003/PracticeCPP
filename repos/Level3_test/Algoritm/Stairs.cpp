#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Stairs() {

	const int stairsCount = 7;
	vector<int> count(stairsCount + 1, 0);

	count[1] = 1;
	count[2] = 2;

	for (int i = 3; i <= stairsCount; i++) {
		count[i] = count[i - 1] + count[i - 2];
	}


	cout << count[stairsCount] << endl;
}