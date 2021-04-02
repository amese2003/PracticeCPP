#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> GetColAvar(vector<vector<int>> map) {
	vector<int> ans(map.size(), 0);

	vector<int> avar(map.size(), 0);

	for (int col = 0; col < map.size(); col++) {

		float coltemp = 0;

		for (int row = 0; row < map.size(); row++)
			coltemp += map[col][row];


		coltemp /= map[col].size();
		int avarage = round(coltemp);
		avar[col] = avarage;


		int delta = 0;
		int deltaMin = INT32_MAX;

		for (int row = 0; row < map.size(); row++) {
			delta = abs(avarage - map[col][row]);


			if (delta < deltaMin) {
				deltaMin = delta;
				ans[col] = map[col][row];
			}
			else if (delta == deltaMin) {
				ans[col] = max(ans[col], map[col][row]);
			}
		}
	}

	return ans;
}


int AvarUse() {


	vector<vector<int>> map{
		{3,23,85,34,17,74,26,52,65},
		{10,7,39,42,88,32,14,72,63},
		{87,42,18,78,53,45,18,84,53},
		{34,28,64,85,12,16,75,36,55},
		{21,77,45,35,28,75,90,76,1},
		{25,87,65,15,28,11,37,28,74},
		{65,27,75,41,7,89,78,64,39},
		{47,47,70,45,23,65,3,41,44},
		{87,13,82,38,50,12,48,29,89}
	};

	GetColAvar(map);

	return 0;
}