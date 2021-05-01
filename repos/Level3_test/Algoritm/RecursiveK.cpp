#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void RecursiveK(int& num, string& result) {
	if (num <= 0)
		return;


	char word = (num % 2) + '0';
	result += word;
	num /= 2;

	RecursiveK(num, result);
}


int UseRecursiveK() {

	string result = "";
	int refer = 11;
	RecursiveK(refer, result);
	reverse(result.begin(), result.end());
	return 0;
}