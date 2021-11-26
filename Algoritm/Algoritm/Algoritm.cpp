#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

template<typename T, typename Container = vector<T>, typename Predicate = less<T>>
class Priority_Queue
{
public:
	void push(const T& data)
	{
		_heap.push_back(data);

		int now = static_cast<int>(_heap.size()) - 1;

		while (now > 0)
		{
			int next = (now - 1) / 2;
			/*if (_heap[now] < _heap[next])
				break;*/

			if (_predicate(_heap[now], _heap[next]))
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	void Pop()
	{
		cout << _heap[0] << endl;
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = now * 2 + 1;
			int right = now * 2 + 2;

			if (left >= _heap.size())
				break;

			int next = now;

			if (_predicate(_heap[next], _heap[left]))
				next = left;
			
			if (right < static_cast<int>(_heap.size()) && _predicate(_heap[next], _heap[right]))
				next = right;

			if (next == now)
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	T& Top()
	{
		return _heap[0];
	}

	bool empty()
	{
		return _heap.empty();
	}

private:
	Container _heap = {};
	Predicate _predicate = {};
};


int main()
{
	Priority_Queue<int, vector<int>, greater<int>> test;

	test.push(100);
	test.push(101);
	test.push(102);
	test.push(103);
	test.push(104);

	test.Pop();
	test.Pop();
	test.Pop();
	test.Pop();
	test.Pop();



	return 0;
}
