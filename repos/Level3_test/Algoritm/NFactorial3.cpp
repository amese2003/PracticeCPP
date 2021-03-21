#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int NFactorial3(int N) {

	vector<__int64> Factorial(N + 1, 0);
	Factorial[1] = 1;


	//for (int i = 2; i <= N; i++) {
	//	Factorial[i] = i * Factorial[i - 1];
	//}

	//int value = Factorial[N];
	//int count = 0;

	//
	//while (value > 0) {
	//	if (value % 10 == 0) {
	//		value /= 10;
	//		count++;
	//	}
	//	else {
	//		break;
	//	}
	//}

	int count2 = 0;
	int count5 = 0;

	for (int i = 2; i <= N; i++) {

		int value = i;
		int share = 2;

		while (value > 2) {
			if (value % share == 0) {

				if (share == 2) count2++;
				else if (share == 5) count5++;

				value /= share;
			}
			else {
				share++;
			}
		}
	}

	int count = (count2 >= count5) ? count5 : count2;

	return count;
}