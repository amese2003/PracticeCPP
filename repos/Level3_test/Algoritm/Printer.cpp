#include <string>
#include <vector>
#include <queue>

using namespace std;

int Printer(vector<int> priorities, int location) {
	using print_Num = pair<int, int>;

	priority_queue<int> print_Order;
	queue<print_Num> check_printNum;

	int answer = 0;

	for (int i = 0; i < priorities.size(); i++) {
		check_printNum.push(make_pair(i, priorities[i]));
		print_Order.push(priorities[i]);
	}

	while (!check_printNum.empty()) {
		print_Num checkFront = check_printNum.front();
		check_printNum.pop();

		if (checkFront.second == print_Order.top()) {
			print_Order.pop();
			answer += 1;

			if (checkFront.first == location) {
				return answer;
			}
		}
		else {
			check_printNum.push(checkFront);
		}
	}

	return -1;
}