#include <iostream>
#include <queue>
using namespace std;

int solution(string text) {
	queue<int> numbers;

	int size = numbers.size();
	int answer = 0;

	for (int i = 0; i < text.length(); i++) {
		char word = text[i] - '0';

		if (word >= 0 && word < 10) {
			answer = (answer * 10) + word;
		}
	}

	/*while (!numbers.empty()) {
		int a = 1;
		for (int i = 1; i < size; i++)
			a *= 10;

		answer += (numbers.front() * a);
		numbers.pop();
		size--;
	}*/

	int count = 0;
	for (int i = 1; i <= answer; i++) {
		if (answer % i == 0)
			count++;
	}

	return 0;
}