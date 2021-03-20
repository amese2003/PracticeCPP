#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int reverse_prime(int x) {

	int newNum = 0;

	while (x > 0) {
		newNum *= 10;
		newNum += (x % 10);
		x /= 10;
	}

	return newNum;
}

bool isPrime2(int x) {

	if (x == 1)
		return false;

	for (int i = 2; i <= sqrt(x); i++) {

		if (x % i == 0)
			return false;
	}

	return true;
}


int ReversePrime() {

	vector<int> num{ 32,55, 62,3700, 250 };

	for (int i = 0; i < num.size(); i++) {

		int temp = reverse_prime(num[i]);

		bool check = isPrime2(temp);

		if (check)
			cout << temp << " ";
	}

	cout << endl;


	return 0;
}