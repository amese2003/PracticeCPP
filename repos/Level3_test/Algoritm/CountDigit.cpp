#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int CountN(int num, int N) {

	int leftNum = 0;
	int currentNum = 0;
	int rightNum = 0;
	int result = 0;

	int K = 10;

	leftNum = num / (K * 10);
	currentNum = (num / K) % 10;
	rightNum = num % K;

	while (leftNum != 0) {
		leftNum = num / (K * 10);
		currentNum = (num / K) % 10;
		rightNum = num % K;

		if (currentNum > N) {
			result = result + ((leftNum + 1) * K);
		}
		else if (currentNum < N) {
			result = result + (leftNum * K);
		}
		else {
			result = result + ((leftNum * K) + (rightNum + 1));
		}

		K *= 10;
	}

	return result;
}