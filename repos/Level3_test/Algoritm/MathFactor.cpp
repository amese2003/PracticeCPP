#include <iostream>
#include <vector>
#include <stack>

using namespace std;


void MathFactor(int num) {

	vector<int> visit(num + 1, 0);

	for (int i = 1; i <= num; i++) {
		for (int j = i; j <= num; j += i) {
			visit[j]++;
		}
	}
}
