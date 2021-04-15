#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string CheckBurket(string test) {
	stack<char> check;

	int pos = 0;

	while (pos < test.length()) {

		if (test[pos] == '(')
			check.push('(');
		else {
			if (check.empty() == true)
				return "NO";

			check.pop();
		}

		pos++;
	}

	if (check.empty() == false)
		return "NO";

	return "YES";
}


int main() {

	string answer = CheckBurket("(()(()))(()");

	return 0;
}