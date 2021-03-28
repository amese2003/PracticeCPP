#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


bool CheckInsideCount(vector<int>& room, int distance, int horseCount) {

	int pos = room[0];
	int placeCount = 1;

	for (int i = 1; i < room.size(); i++) {
		int delta = room[i] - pos;

		if (delta >= distance) {
			pos = room[i];
			placeCount++;
		}

		if (placeCount >= horseCount)
			break;
	}

	bool ret = placeCount >= horseCount;

	return ret;
}

int CheckRoom(vector<int> room, int horseCount) {

	sort(room.begin(), room.end());

	int start = INT32_MAX, end = INT32_MIN;
	for (int i = 0; i < room.size(); i++) {

		if (end < room[i])
			end = room[i];

		if (start > room[i])
			start = room[i];
	}

	int mid;
	int maxDist = INT32_MIN;

	while (start <= end) {
		mid = (start + end) / 2;

		bool check = CheckInsideCount(room, mid, horseCount);


		if (!check) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			maxDist = max(maxDist, mid);
		}
	}

	return maxDist;
}

int UseHorseHouse() {
	vector<int> horseRoom{ 1,2,8,4,9 };
	CheckRoom(horseRoom, 3);
	return 0;
}