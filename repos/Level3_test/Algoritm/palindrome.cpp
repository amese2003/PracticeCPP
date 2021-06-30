#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m);
bool CheckPalindrome(int num);

int solution(int n, int m) {
	int answer = 0;

	for (int i = n; i <= m; i++) {
		if (CheckPalindrome(i)) answer++;
	}
	return answer;
}

bool CheckPalindrome(int num) {
	int checkNum = num;
	int reverseNum = 0;

	while (checkNum > 0) {
		reverseNum *= 10;
		reverseNum += checkNum % 10;
		checkNum /= 10;
	}

	if (num == reverseNum) return true;
	return false;
}