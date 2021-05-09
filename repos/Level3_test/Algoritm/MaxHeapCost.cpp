#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class TeachData {
public:
	TeachData(int pay, int day) : _pay(pay), _day(day) {}

public:
	bool operator<(const TeachData& cmp) {
		return _day > cmp._day;
	}

	bool operator>(const TeachData& cmp) {
		return !operator<(cmp);
	}
public:
	int _pay;
	int _day;
};

template<typename T>
class PriorityQueue {
public:
	void Push(T data) {
		int pos = _data.size();
		_data.push_back(data);

		while (pos > 0) {
			int next = (pos - 1 == 0) ? 0 : (pos - 1) / 2;

			if (_data[next] > _data[pos])
				break;

			T temp = _data[next];
			_data[next] = _data[pos];
			_data[pos] = temp;

			pos = next;
		}
	}

	T Pop() {
		T data = _data[0];

		int last = _data.size() - 1;
		int pos = 0;

		T temp = _data[0];
		_data[0] = _data[last];
		_data[last] = temp;
		last--;

		_data.pop_back();


		while (true) {
			int left = pos * 2 + 1;
			int right = pos * 2 + 2;

			int next = pos;

			if (left <= last && _data[next] < _data[left])
				next = left;

			if (right <= last && _data[next] < _data[right])
				next = right;

			if (next == pos)
				break;

			T temp = _data[next];
			_data[next] = _data[pos];
			_data[pos] = temp;

			pos = next;
		}

		return data;
	}

	T Front() {
		return _data[0];
	}

	bool empty() {
		return _data.size() == 0;
	}

private:
	vector<T> _data;
};

int MakeTable() {
	vector<TeachData> data;

	int maxDay = INT32_MIN;
	int maxPay = 0;

	data.push_back(TeachData(50, 2));
	data.push_back(TeachData(20, 1));
	data.push_back(TeachData(40, 2));
	data.push_back(TeachData(60, 3));
	data.push_back(TeachData(30, 3));
	data.push_back(TeachData(30, 1));

	sort(data.begin(), data.end());

	maxDay = 3;

	PriorityQueue<int> check;
	int pos = 0;

	for (int day = maxDay; day > 0; day--) {

		for (pos; pos < data.size(); pos++) {
			if (data[pos]._day < day)
				break;

			check.Push(data[pos]._pay);
		}

		if (check.empty() == false) {
			maxPay += check.Pop();
		}
	}

	return maxPay;
}

int main() {
	MakeTable();
	return 0;
}