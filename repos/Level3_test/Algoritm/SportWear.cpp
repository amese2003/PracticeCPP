#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int SportWear(int n, vector<int> lost, vector<int> reserve) {
	vector<int> people(n, 1);

	int own_people = 0;

	for (int i = 0; i < lost.size(); i++) {
		people[lost[i] - 1]--;
	}

	for (int i = 0; i < reserve.size(); i++) {
		people[reserve[i] - 1]++;
	}

	for (int i = 0; i < n; i++) {
		if (people[i] == 0) {
			if ((i > 0 && people[i - 1] > 1) || (i < n - 1 && people[i + 1] > 1)) {
				int* lendless = (people[i - 1] > people[i + 1]) ? &people[i - 1] : &people[i + 1];
				--* lendless;
				people[i]++;
			}
		}

		if (people[i] > 0)
			own_people++;
	}

	return own_people;
}