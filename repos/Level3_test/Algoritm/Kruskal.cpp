#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node {
public:
	Node(int cur, int next, int cost) : _current(cur), _next(next), _cost(cost) {}

public:
	bool operator<(const Node& cmp) {
		return _cost < cmp._cost;
	}

	bool operator>(const Node& cmp) {
		return _cost > cmp._cost;
	}

	bool operator<=(const Node& cmp) {
		return _cost <= cmp._cost;
	}

	bool operator>=(const Node& cmp) {
		return _cost >= cmp._cost;
	}

	bool operator==(const Node& cmp) {
		return _cost == cmp._cost;
	}

	bool operator!=(const Node& cmp) {
		return _cost != cmp._cost;
	}

public:
	int _current;
	int _next;
	int _cost;
};

int FindParent(vector<int>& parent, int n) {
	if (parent[n] == n)
		return n;

	return parent[n] = FindParent(parent, parent[n]);
}

void UnionParent(vector<int>& parent, int n, int m) {
	int parentN = FindParent(parent, n);
	int parentM = FindParent(parent, m);

	if (parentN < parentM)
		parent[m] = parent[n];
	else
		parent[n] = parent[m];
}

bool CheckSameParent(vector<int>& parent, int n, int m) {
	int N = FindParent(parent, n);
	int M = FindParent(parent, m);
	if (N == M)
		return true;
	else
		return false;
}

void WonderLand() {
	const int nodeCount = 9;
	vector<Node> node;
	vector<int> parent(nodeCount + 1);

	for (int i = 1; i < parent.size(); i++)
		parent[i] = i;



	node.push_back({ 1,2,12 });
	node.push_back({ 1, 9,25 });

	node.push_back({ 2, 1, 12 });
	node.push_back({ 2, 3,10 });
	node.push_back({ 2, 8,17 });
	node.push_back({ 2, 9,8 });

	node.push_back({ 3, 2,10 });
	node.push_back({ 3, 7,55 });
	node.push_back({ 3, 4,18 });

	node.push_back({ 4, 3,18 });
	node.push_back({ 4, 5,44 });

	node.push_back({ 5, 4, 44 });
	node.push_back({ 5, 7, 38 });
	node.push_back({ 5, 6, 60 });

	node.push_back({ 6, 5,60 });

	node.push_back({ 7, 3, 55 });
	node.push_back({ 7, 5, 38 });
	node.push_back({ 7, 8, 35 });

	node.push_back({ 8, 7, 35 });
	node.push_back({ 8, 2, 17 });
	node.push_back({ 8, 9, 15 });

	node.push_back({ 9, 1, 25 });
	node.push_back({ 9, 2, 8 });
	node.push_back({ 9, 8, 15 });
	sort(node.begin(), node.end());

	vector<Node> connect;
	int maxCount = nodeCount - 1;
	int checkPos = 0;

	int sum = 0;
	while (checkPos < node.size()) {
		Node checkNode = node[checkPos];

		int curPos = checkNode._current;
		int nextPos = checkNode._next;

		checkPos++;

		if (CheckSameParent(parent, curPos, nextPos) == false) {
			sum += checkNode._cost;
			UnionParent(parent, curPos, nextPos);
			connect.push_back(checkNode);
		}
	}
}