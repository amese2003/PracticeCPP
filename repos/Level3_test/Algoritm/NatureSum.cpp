#include <iostream>
#include "NatureSum.h"

using namespace std;

int NatureSum::solution_2(int a ,int b) {
	int sum = 0;

	for (int i = a; i < b; i++) {
		sum += i;
		cout << i << "+";		
	}

	cout << b << "=" << sum << endl;
	return sum;
}