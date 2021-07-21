
#include <iostream>
#include <string>
using namespace std;
int VisitWay(string dirs);
int solution(string dirs);



class Direction {
public:
	bool left;
	bool right;
	bool up;
	bool down;
};


int solution(string dirs) {
	int answer = VisitWay(dirs);
	return answer;
}

int VisitWay(string dirs) {
	Direction map[11][11] = { false };
	int col = 5;
	int row = 5;
	int count = 0;

	for (int i = 0; i < dirs.length(); i++) {
		if (dirs[i] == 'U') {
			if (col > 0) {
				if (map[col][row].up == false) {
					count++;
					map[col][row].up = true;
					map[col - 1][row].down = true;
				}
				col--;
			}
		}

		if (dirs[i] == 'D') {
			if (col < 10) {
				if (map[col][row].down == false) {
					count++;
					map[col][row].down = true;
					map[col + 1][row].up = true;
				}
				col++;
			}
		}

		if (dirs[i] == 'R') {
			if (row < 10) {
				if (map[col][row].right == false) {
					count++;
					map[col][row].right = true;
					map[col][row + 1].left = true;
				}
				row++;
			}
		}

		if (dirs[i] == 'L') {
			if (row > 0) {
				if (map[col][row].left == false) {
					count++;
					map[col][row].left = true;
					map[col][row - 1].right = true;
				}
				row--;
			}
		}
	}
	return count;
}