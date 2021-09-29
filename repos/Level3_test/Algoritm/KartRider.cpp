#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct Shoe
{
	Shoe(int a, int b, int c, int d) {
		_time = a;
		_start = a + b;
		_end = a + b + c;
		_speed = d;
	}

	int _time;
	int _start;
	int _end;
	int _speed;
};

int T;
vector<Shoe> shoes;
vector<int> cache(4, -1);


int Solve(int num)
{
	if (num > shoes.size() - 1)
		return 0;

	int& ret = cache[num];
	if (ret != -1)
		return ret;


	Shoe& currentShoe = shoes[num];
	int putShoesDist = (currentShoe._end - currentShoe._start) * currentShoe._speed + (T - currentShoe._end) * 1;
	ret = max(putShoesDist, ret);

	for (int i = num + 1; i < shoes.size(); i++)
	{
		Shoe& nextShoe = shoes[i];

		if (nextShoe._time <= currentShoe._start)
			continue;

		int moveDist = 0;

		if (nextShoe._time <= currentShoe._end)
		{
			moveDist = (nextShoe._time - currentShoe._start) * currentShoe._speed;
		}
		else {
			moveDist = (currentShoe._end - currentShoe._start) * currentShoe._speed;
			moveDist += (nextShoe._time - currentShoe._end) * 1;
		}

		ret = max(ret, moveDist + Solve(i));
	}

	return ret;
}

int UseKarts() {
	T = 20;

	//cache = vector<int>(shoes.size(), -1);

	shoes.push_back(Shoe(3, 4, 10, 3));
	shoes.push_back(Shoe(4, 1, 4, 2));
	shoes.push_back(Shoe(10, 2, 5, 5));
	shoes.push_back(Shoe(15, 1, 3, 7));

	std::sort(shoes.begin(), shoes.end(), [=](Shoe& left, Shoe& right) { return left._time < right._time; });
	int ans = Solve(2);

	cout << ans << endl;


	return 0;
}