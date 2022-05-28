#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(string s) {
	int answer = s.length();

	string slice = "";
	string next_slice = "";
	int zipCount = 1;

	vector<int> zipSize;

	for (int i = 1; i <= s.length() / 2; i++) {
		string makeString = "";

		for (int j = 0; j < s.length(); j += i) {

			slice = s.substr(j, i);

			if (j + i > s.length() || slice != s.substr(j + i, i)) {
				if (zipCount > 1) {
					makeString += to_string(zipCount);

				}
				makeString += slice;
				zipCount = 1;
			}
			else
				zipCount++;
		}

		zipSize.push_back(makeString.length());
	}


	if (s.length() == 1)
		return 1;
	else
		return *min_element(zipSize.begin(), zipSize.end());
}