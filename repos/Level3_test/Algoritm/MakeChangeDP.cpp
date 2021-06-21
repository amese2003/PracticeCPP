#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void MakeChangeDP() {

	const int target = 15;
	vector<int> change{ 1,2,5 };
	vector<int> changeCost(target + 1, 1000);

	changeCost[0] = 0;

	for (int i = 0; i < change.size(); i++) {

		int cost = change[i];
		for (int j = cost; j <= target; j++) {
			changeCost[j] = min(changeCost[j], changeCost[j - cost] + 1);
		}
	}

	cout << changeCost[target] << endl;
}
