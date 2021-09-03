#include <iostream>
#include<string>
#include <stack>

using namespace std;

int makePair(string s)
{
	stack<int> charStack;

	for (char c : s) {
		if (!charStack.empty() && charStack.top() == c)
			charStack.pop();
		else
			charStack.push(c);
	}

	return charStack.empty();
}