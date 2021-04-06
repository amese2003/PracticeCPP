#include <string>
#include <queue>
#include <vector>

using namespace std;

int TruckPassing(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int total_Weight = 0;

	queue<int> onBridge, drive;
	vector<int> truck = truck_weights;

	while (1) {
		int size = onBridge.size();
		for (int i = 0; i < size; i++) {
			int lenght = onBridge.front();
			onBridge.pop();

			if (lenght <= 1) {
				total_Weight -= drive.front();
				drive.pop();
				continue;
			}
			onBridge.push(lenght - 1);
		}

		if (truck.size() > 0 && total_Weight + truck[0] <= weight) {
			drive.push(truck[0]);
			total_Weight += truck[0];
			onBridge.push(bridge_length);
			truck.erase(truck.begin());
		}

		answer++;
		if (truck.size() == 0 && onBridge.size() == 0)
			break;
	}

	return answer;
}