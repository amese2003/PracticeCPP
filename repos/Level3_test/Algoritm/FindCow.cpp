#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void BFScow(int& count, vector<int> movement, int startPos, int cowPos) {
	vector<int> visit(cowPos + 1, 0);

	queue<int> pos;
	pos.push(startPos);
	visit[startPos] = 1;

	while (pos.empty() == false) {

		int curPos = pos.front();
		pos.pop();

		for (size_t i = 0; i < movement.size(); i++) {

			int nextPos = curPos + movement[i];

			if (nextPos > cowPos || nextPos < 0)
				continue;

			if (nextPos == cowPos) {
				cout << visit[curPos] << endl;
				return;
			}

			if (visit[nextPos] == 0) {
				visit[nextPos] = visit[curPos] + 1;
				pos.push(nextPos);
			}
		}
	}
}


int FindCow() {
	int count = 0;
	vector<int> movement{ 1,-1,5 };
	BFScow(count, movement, 5, 14);
	return 0;
}