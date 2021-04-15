#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string ConvertK(int N, int K) {
	stack<char> check;
	vector<char> hash_check;
	for (int i = 0; i < K; i++) {
		if (i > 9)
			hash_check.push_back(i + 87);
		else
			hash_check.push_back(i + '0');
	}

	while (N > 0) {
		int temp = N % K;
		check.push(hash_check[temp]);
		N /= K;
	}

	string answer = "";

	while (!check.empty()) {
		cout << check.top();
		answer += check.top();
		check.pop();
	}

	cout << endl;
	return answer;
}


int UseConvert() {
	string ans = ConvertK(11, 2);

	return 0;
}