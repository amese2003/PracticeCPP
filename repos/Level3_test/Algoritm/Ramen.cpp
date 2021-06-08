
#include <string>
#include <vector>
#include <queue>

using namespace std;

int Ramen(int stock, vector<int> dates, vector<int> supplies, int k) {
	int receive_count = 0;
	int day_num = 0;
	priority_queue<int> supply_receive;

	for (int i = 0; i < k; i++) {
		if (dates[day_num] == i) {
			supply_receive.push(supplies[day_num]);
			day_num++;
		}

		if (stock == 0) {
			stock = supply_receive.top();
			supply_receive.pop();
			receive_count++;
		}

		stock--;
	}

	return receive_count;
}