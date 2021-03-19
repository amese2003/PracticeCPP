#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void MathFactor(int num) {

	vector<int> visit(num + 1, 0);

	for (int i = 1; i <= num; i++) {
		for (int j = i; j <= num; j += i) {
			visit[j]++;				
		}
	}
}



int main() {
	MathFactor(8);
	return 0;
}