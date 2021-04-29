#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> ChartCheck(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    stack<int> time_stack;

    for (int i = 0; i < prices.size(); i++) {
        while (!time_stack.empty() && prices[time_stack.top()] > prices[i]) {
            answer[time_stack.top()] = i - time_stack.top();
            time_stack.pop();
        }

        time_stack.push(i);
    }

    while (!time_stack.empty()) {
        answer[time_stack.top()] = prices.size() - 1 - time_stack.top();
        time_stack.pop();
    }

    return answer;
}


int Chart() {

    vector<int> train{ 1,2,3,2,3 };

    vector<int> answer = ChartCheck(train);

    return 0;
}