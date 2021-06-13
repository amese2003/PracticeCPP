#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;


void KnapSack() {

	int maxWeight = 11;
	int count = 5;

	vector<int> bag(maxWeight + 1, 0);

	int weight;
	int value;

	for (int i = 0; i < count; i++) {
		cin >> weight >> value;

		for (int j = weight; j <= maxWeight; j++) {
			bag[j] = max(bag[j], bag[j - weight] + value);
		}
	}

	cout << bag[maxWeight] << endl;
}
