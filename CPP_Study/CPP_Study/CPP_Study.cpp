#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 연습문제

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

enum Dir {
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3	
};

void PrintBoard() {

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}

		cout << endl;
	}
}


bool CanGo(int y, int x) {

	if (y < 0 || y >= N)
		return false;

	if (x < 0 || x >= N)
		return false;

	if (board[y][x] != 0)
		return false;

	return true;
}



void SetBoard() {
	int dir = RIGHT;
	int count = 1;
	int y = 0;
	int x = 0;


	int dy[] = { 0, 1, 0, -1 };
	int dx[] = { 1, 0, -1, 0 };

	while(true) {		

		board[y][x] = count;

		if (count == N * N)
			break;

		int nextY = y + dy[dir];
		int nextX = x + dx[dir];


		if (CanGo(nextY, nextX)) {
			y = nextY;
			x = nextX;
			count++;
		}
		else {
			dir = (dir + 1) % 4;
		}
	}
}


int main() 
{	
	cin >> N;

	SetBoard();
	PrintBoard();


	return 0;
}