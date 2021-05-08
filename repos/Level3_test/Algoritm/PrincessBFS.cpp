#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void CheckPrincess(int N, int K) {


	queue<int> checking;

	for (int i = 0; i < N; i++)
		checking.push(i);

	int count = 0;


	while (checking.size() > 1) {
		int front = checking.front();
		checking.pop();
		count++;

		if (count < K) {
			checking.push(front);
		}
		else {
			count = 0;
		}
	}

	cout << checking.front() + 1 << endl;
}



int UseCheckPrincess() {
	CheckPrincess(8, 3);
	return 0;
}