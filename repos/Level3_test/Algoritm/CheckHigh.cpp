#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int CheckHigh(vector<vector<int>> map, int mapSize) {

	vector<int> dirY{ -1 ,0 ,1 , 0 };
	vector<int> dirX{ 0 ,1 ,0 ,-1 };

	int count = 0;

	for (int col = 1; col <= mapSize; col++) {
		for (int row = 1; row <= mapSize; row++) {

			int height = map[col][row];
			int compare = height;

			for (int i = 0; i < dirY.size(); i++) {
				int temp = map[col + dirY[i]][row + dirX[i]];
				compare = max(compare, temp);
			}

			if (height == compare)
				count++;
		}
	}

	return count;
}


int UseHigh() {
	int mapSize = 5;

	vector<vector<int>> map{
		{0,0,0,0,0,0,0},
		{0,5,3,7,2,3,0},
		{0,3,7,1,6,1,0},
		{0,7,2,5,3,4,0},
		{0,4,3,6,4,1,0},
		{0,8,7,3,5,2,0},
		{0,0,0,0,0,0,0}
	};

	CheckHigh(map, mapSize);
	return 0;
}