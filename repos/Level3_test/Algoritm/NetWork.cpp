#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int CheckNetwork(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<bool> visit(computers.size(), false);


	for (int i = 0; i < n; i++) {
		if (visit[i])
			continue;

		answer++;
		queue<int> check_com;
		check_com.push(i);

		while (!check_com.empty()) {
			int front = check_com.front();
			check_com.pop();
			visit[front] = true;

			for (int j = 0; j < n; j++) {
				if (computers[front][j] && !visit[j])
					check_com.push(j);
			}
		}
	}

	return answer;
}