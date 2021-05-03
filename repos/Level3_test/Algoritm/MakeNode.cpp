#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;




int MakeNode() {

	const int N = 6;

	vector<pair<int, int>> sum[N + 1];

	sum[1].push_back({ 2,7 });
	sum[1].push_back({ 3,4 });

	sum[2].push_back({ 1,2 });
	sum[2].push_back({ 3,5 });
	sum[2].push_back({ 5,5 });

	sum[3].push_back({ 4,5 });

	sum[4].push_back({ 2,2 });
	sum[4].push_back({ 5,5 });

	sum[6].push_back({ 4,5 });

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < sum[i].size(); j++) {
			cout << i << " " << sum[i][j].first << " " << sum[i][j].second << endl;
		}
	}

	return 0;
}