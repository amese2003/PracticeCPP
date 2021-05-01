#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void RecursivePrac(int& num) {
	if (num > 3) {
		cout << endl;
		return;
	}


	int cur = num;
	cout << cur << " ";
	cur++;
	RecursivePrac(cur);
}


int UseRecursive() {
	int num = 1;
	RecursivePrac(num);
	return 0;
}