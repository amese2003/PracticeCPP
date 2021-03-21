#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<char> RockPaper(vector<int> A, vector<int> B) {

	vector<char> winner;

	for (int i = 0; i < A.size(); i++) {
		int a = A[i];
		int b = B[i];

		if (a == 3) {
			switch (b)
			{
			case 1:
				winner.push_back('b');
				break;
			case 2:
				winner.push_back('a');
				break;
			case 3:
				winner.push_back('d');
				break;
			}
		}

		else if (a == 2) {
			switch (b)
			{
			case 1:
				winner.push_back('a');
				break;
			case 2:
				winner.push_back('d');
				break;
			case 3:
				winner.push_back('b');
				break;
			}
		}

		else {
			switch (b)
			{
			case 1:
				winner.push_back('d');
				break;
			case 2:
				winner.push_back('b');
				break;
			case 3:
				winner.push_back('a');
				break;
			}
		}
	}

	return winner;
}