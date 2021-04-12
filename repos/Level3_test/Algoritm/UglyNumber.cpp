#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int UglyNumber(vector<int> map, int target) {

	int mapCur = 1;
	int p2 = 1;
	int p3 = 1;
	int p5 = 1;

	while (map.size() <= target) {
		int cal2 = map[p2] * 2;
		int cal3 = map[p3] * 3;
		int cal5 = map[p5] * 5;


		int minNum = min(cal2, min(cal3, cal5));


		if (minNum == cal2) {
			p2++;
			if (map.size() - 1 == mapCur)
				map.push_back(cal2);
		}

		if (minNum == cal3) {
			p3++;
			if (map.size() - 1 == mapCur)
				map.push_back(cal3);
		}

		if (minNum == cal5) {
			p5++;
			if (map.size() - 1 == mapCur)
				map.push_back(cal5);
		}

		mapCur++;
	}



	return map[mapCur];
}

int FindUgly() {
	vector<int> map;
	map.push_back(0);
	map.push_back(1);

	int targetNum = 1500;

	int temp = UglyNumber(map, targetNum);

	return 0;
}