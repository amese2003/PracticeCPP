#include <iostream>
#include <vector>

using namespace std;


bool isPrimeNumber(int num) {

	/*vector<int> check(num + 1);

	for (int i = 2; i < check.size(); i++)
		check[i] = i;
	
	for (int i = 2; i < check.size(); i++) {
		if (check[i] == 0) continue;

		for (int j = i + i; j < check.size(); j += i) {
			check[j] = 0;
		}
	}

	return check[num] != 0;*/

	int end = (int)sqrt(num);

	for (int i = 2; i < end; i++) 
		if (num % i == 0) return 0;
	
	return 1;
}



int main() {
	cout << isPrimeNumber(97) << endl;
	return 0;
}