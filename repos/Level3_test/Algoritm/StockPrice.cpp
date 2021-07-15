#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> Stock(vector<int> prices) {
	vector<int> answer;
	stack<int> time_Stack;

	int price = 0;

	for (int i = 0; i < prices.size(); i++) {
		while (!time_Stack.empty() && prices[time_Stack.top()] > prices[i]) {
			answer[time_Stack.top()] = i - time_Stack.top();
			time_Stack.pop();
		}

		time_Stack.push(i);
	}

	while (!time_Stack.empty()) {
		answer[time_Stack.top()] = prices.size() - 1 - time_Stack.top();
		time_Stack.pop();
	}

	return answer;
}