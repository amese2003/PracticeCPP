#include <string>
#include <vector>
#include <queue>

using namespace std;

int Scovill(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> hot_order;

	for (int hot : scoville)
		hot_order.push(hot);

	while (hot_order.top() < K) {
		if (hot_order.size() <= 1)
			return -1;

		int first = 0;
		int second = 0;
		int new_Scoville = 0;

		first = hot_order.top();
		hot_order.pop();

		second = hot_order.top();
		hot_order.pop();

		new_Scoville = first + (second * 2);
		hot_order.push(new_Scoville);
		answer++;
	}

	return answer;
}