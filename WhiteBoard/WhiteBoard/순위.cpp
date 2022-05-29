#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	vector<vector<bool>> check_win(n, vector<bool>(n, false));

	for (vector<int> result : results) {
		check_win[result[0] - 1][result[1] - 1] = true;
	}

	for (int pivot = 0; pivot < n; pivot++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (check_win[i][pivot] && check_win[pivot][j])
					check_win[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int count = 0;

		for (int j = 0; j < n; j++) {
			if (check_win[i][j] || check_win[j][i])
				count++;
		}

		if (count == n - 1) answer++;
	}

	return answer;
}