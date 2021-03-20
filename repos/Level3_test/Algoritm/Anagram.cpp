#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isAnagram(string target1, string target2) {

	if (target1.length() != target2.length())
		return false;

	unordered_map<char, int> check;

	for (int i = 0; i < target1.length(); i++)
		check[target1[i]]++;

	for (int i = 0; i < target2.length(); i++) {
		if (check[target2[i]] == 0)
			return false;

		check[target2[i]]--;
		if (check[target2[i]] == 0)
			check.erase(check[target2[i]]);
	}

	for (unordered_map<char, int>::iterator it = check.begin(); it != check.end(); it++) {
		pair<const char, int>& get = (*it);

		if (get.second > 0)
			return false;
	}

	return true;

}