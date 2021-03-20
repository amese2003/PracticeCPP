#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int total_natureNum_Large(int n) {

	int digit_num_max = 9;
	int digit_count = 0;
	int answer = 0;

	int N = n;

	while (N > 0) {
		digit_count++;
		N /= 10;
	}

	for (int i = 1; i <= digit_count; i++) {
		if (n < digit_num_max) {


			int digit_min = pow(10, i - 1);
			int temp = n - digit_min;

			answer += ((temp + 1) * i);

		}
		else {
			answer += (digit_num_max * i);
		}

		digit_num_max *= 10;
	}

	return answer;
}