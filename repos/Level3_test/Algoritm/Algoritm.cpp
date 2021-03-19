#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

string solution(string pending) {

	stack<char> check;

	for (int i = 0; i < pending.length(); i++) {

		if (pending[i] == '(')
			check.push(pending[i]);
		else {

			if (check.empty())
				return "NO";
			

			if (check.top() == '(')
				check.pop();
		}
	}

	if (check.empty())
		return "YES";
	else
		return "NO";
}


int main() {
	string answer1 = solution("(()(()))(()");

	string answer2 = solution("()()(()())");
	return 0;
}