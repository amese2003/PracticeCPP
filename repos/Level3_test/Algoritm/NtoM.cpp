#include <iostream>
#include "NtoM.h"

using namespace std;

int NtoM::solution_1(int n, int m) {
	int answer = 0;
	for (int i = 0; i <= n; i += m) {
		answer += i;
	}

	return answer;
}