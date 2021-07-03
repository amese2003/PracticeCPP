#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LifeBoat(vector<int> people, int limit) {
	int boat_cnt = 0;
	sort(people.begin(), people.end(), greater<int>());

	int less_point = 0;
	int max_point = people.size() - 1;

	while (less_point <= max_point) {
		if (people[less_point] + people[max_point] <= limit)
			max_point--;

		less_point++;
		boat_cnt;
	}

	return boat_cnt;
}