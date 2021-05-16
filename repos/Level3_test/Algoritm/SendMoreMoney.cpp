#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int hashSize = 10;
vector<int> check(hashSize, 0);
vector<bool> visit(hashSize, false);

int Send() {
	return check[6] * 1000 + check[1] * 100 + check[3] * 10 + check[0];
}

int More() {
	return check[2] * 1000 + check[4] * 100 + check[5] * 10 + check[1];
}

int Money() {
	return check[2] * 10000 + check[4] * 1000 + check[3] * 100 + check[1] * 10 + check[7];
}

void Search(int n) {

	if (n == 8) {

		if (Send() + More() == Money()) {
			if (check[2] == 0 || check[6] == 0) return;

			cout << " " << check[6] << check[1] << check[3] << check[0] << endl;
			cout << " " << check[2] << check[4] << check[5] << check[1] << endl;
			cout << check[2] << check[4] << check[3] << check[1] << check[7] << endl;
			return;
		}

	}
	else {
		for (int i = 0; i < hashSize; i++) {
			if (visit[i] == false) {
				check[n] = i;
				visit[i] = true;
				Search(n + 1);
				visit[i] = false;
			}
		}
	}
}

void SendMore() {
	Search(0);
}
