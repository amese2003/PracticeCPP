#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void VoteBoss() {

	const int people = 5;
	vector<int> know[people + 1];

	know[1].push_back(2);
	know[2].push_back(3);
	know[3].push_back(4);
	know[4].push_back(5);
	know[2].push_back(4);
	know[5].push_back(3);

	vector<vector<int>> map(people + 1, vector<int>(people + 1, 100));
	vector<int> result(people + 1, 0);

	for (int i = 1; i <= people; i++) {

		vector<int> curKnow = know[i];

		for (int j = 0; j < curKnow.size(); j++) {
			map[i][curKnow[j]] = 1;
			map[curKnow[j]][i] = 1;
		}
	}

	for (int middle = 1; middle <= people; middle++) {

		for (int i = 1; i <= people; i++) {
			for (int j = 1; j <= people; j++) {
				map[i][j] = min(map[i][j], map[i][middle] + map[middle][j]);

			}
		}
	}

	int score = 100;
	for (int i = 1; i <= people; i++) {
		for (int j = 1; j <= people; j++) {
			result[i] = max(result[i], map[i][j]);
		}

		score = min(result[i], score);
	}

	for (int i = 1; i <= people; i++) {
		if (result[i] == score)
			cout << i << " ";
	}

	cout << endl;

}