#include <iostream>

using namespace std;

// 오늘의 주제 : 이차원 배열

int main() {	

	int a[10] = { 1,2,3 };

	// [4] [2] [3] [4] [1] << 0
	// [1] [1] [5] [2] [2] << 1

	int first[5] = { 4,2,3,4,1 };
	int secound[5] = { 1,1,5,2,2 };

	int apartment2D[2][5] = { { 4,2,3,4,1 }, { 1,1,5,2,2 } };

	for (int floor = 0; floor < 2; floor++) {
		for (int room = 0; room < 5; room++) {

			int num = apartment2D[floor][room];
			cout << num << "";
		}

		cout << endl;
	}

	int apartment1D[10] = { 4,2,3,4,1, 1,1,5,2,2 };

	for (int floor = 0; floor < 2; floor++) {
		for (int room = 0; room < 5; room++) {

			int index = (floor * 5) + room;
			// apartment1d + (floor * 20) + 4  * room;
			int num = apartment1D[index];
			cout << num << "";
		}

		cout << endl;
	}

	// 2차 배열은 언제 사용할까? 대표적으로 2d 로그라이크
	int map[5][5] = {
		{1,1,1,1,1},
		{1,0,0,1,1},
		{0,0,0,0,1},
		{1,0,0,0,0},
		{1,1,1,1,1}
	};

	return 0;
}