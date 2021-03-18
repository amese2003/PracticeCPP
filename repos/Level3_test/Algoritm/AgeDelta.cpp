#include "AgeDelta.h"
#include <queue>

using namespace std;

int AgeDelta::solution(int count, int age[]) {

	/*priority_queue<int> test;

	for (int i = 0; i < count; i++) {
		test.push(age[i]);
	}

	int elder = test.top();

	while (test.size() > 1) {
		test.pop();
	}

	int younger = test.top();

	int delta = elder - younger;*/

	int min = INT32_MAX;
	int max = INT32_MIN;

	for (int i = 0; i < count; i++) {
		if (age[i] > max) { max = age[i]; }
		if (age[i] < min) { min = age[i]; }
	}

	int delta = max - min;

	return delta;
}