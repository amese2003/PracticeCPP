#include "CDSum.h"
#include <iostream>

using namespace std;

int CDSum::solution3(int N) {
	int sum = 0;
	
	cout << 1;

	for (int i = 2; i <= N / 2; i++) {
		if (N % i == 0) {
			cout << "+" << i;
			sum += i;
		}
	}

	cout << "=" << sum + 1 << endl;
	
	return sum;
}