#include <string>
#include <stack>

using namespace std;

string bracket(string pending) {

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