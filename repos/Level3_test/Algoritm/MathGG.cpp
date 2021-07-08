
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> MathGG(vector<int> answers) {
	vector<int> answer(3, 0);
	vector<vector<int>> mathGG = { {1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5} };
	int highVal = 0;

	for (int i = 0; i < 3; i++) {
		int ruleNum = mathGG[i].size();
		int tortoise = 0;
		int count = 0;

		for (int j = 0; j < answers.size(); j++) {
			if (answers[j] == mathGG[i][tortoise % ruleNum]) count++;
			tortoise++;
		}

		if (count >= highVal)
			highVal = count;
		answer[i] = count;
	}

	for (int i = 0; i < 3; i++) {
		if (highVal == answer[i])
			answer[i] = i + 1;
		else
			answer[i] = -1;
	}
	answer.erase(remove(answer.begin(), answer.end(), -1), answer.end());
	return answer;
}