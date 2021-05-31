#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct State {
	State(int posY, int posX, int dist) : _posY(posY), _posX(posX), _dist(dist) {}

	bool operator<(const State& cmp) const {
		if (_dist == cmp._dist) {
			if (_posX == cmp._posX)
				return _posY > cmp._posY;
			else
				return _posX > cmp._posX;
		}
		else {
			return _dist > cmp._dist;
		}
	}

	int _posY;
	int _posX;
	int _dist;
};

class Lion {
public:
	Lion() {
		_size = 2;
		_eatCount = 0;
		_posX = 0;
		_posY = 0;
	}

public:
	int& GetSize() { return _size; }
	void Eat() {
		_eatCount++;
		Grow();
	}

	void Grow() {
		if (_size <= _eatCount) {
			_eatCount = 0;
			_size++;
		}
	}

public:
	int _posX;
	int _posY;

private:
	int _size;
	int _eatCount;
};

void LionKing() {

	const int mapSize = 3;
	int lionSize = 2;

	int dirY[4] = { -1,0,1,0 };
	int dirX[4] = { 0,1,0,-1 };

	vector<vector<int>> map{
		{0,1,3},
		{1,9,1},
		{0,1,1}
	};

	vector<vector<bool>> visit(mapSize, vector<bool>(mapSize, false));

	Lion simba;
	priority_queue<State> search;
	search.push({ 0,0,0 });

	int result = 0;

	while (search.empty() == false) {
		State currentState = search.top();
		int curY = currentState._posY;
		int curX = currentState._posX;
		int curDist = currentState._dist;
		search.pop();

		if (map[curY][curX] != 0 && map[curY][curX] < simba.GetSize()) {
			simba.Eat();
			map[curY][curX] = 0;

			simba._posY = curY;
			simba._posX = curX;


			while (search.empty() == false)
				search.pop();

			for (size_t col = 0; col < visit.size(); col++) {
				for (size_t row = 0; row < visit.size(); row++) {
					visit[col][row] = false;
				}
			}

			result = curDist;
		}


		for (int i = 0; i < 4; i++) {

			int nextY = curY + dirY[i];
			int nextX = curX + dirX[i];

			if (nextY < 0 || nextY >= mapSize || nextX < 0 || nextX >= mapSize)
				continue;

			if (visit[nextY][nextX])
				continue;

			if (map[nextY][nextX] > simba.GetSize())
				continue;

			visit[nextY][nextX] = true;
			search.push({ nextY, nextX, curDist + 1 });
		}
	}

	cout << result << endl;
}