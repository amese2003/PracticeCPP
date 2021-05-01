#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Node {
public:
	Node() {
		_data = 0;
	}

	Node(int data) : _data(data) {}
	~Node() {}

public:
	shared_ptr<Node> _left;
	shared_ptr<Node> _right;

private:
	int _data;
};

void UseFront(int num, vector<int> heap) {
	if (num >= heap.size()) {
		return;
	}

	int left = num * 2 + 1;
	int right = num * 2 + 2;


	cout << heap[num] << " ";
	UseFront(left, heap);
	UseFront(right, heap);
}

void UseMiddle(int num, vector<int> heap) {
	if (num >= heap.size()) {
		return;
	}

	int left = num * 2 + 1;
	int right = num * 2 + 2;

	UseMiddle(left, heap);
	cout << heap[num] << " ";
	UseMiddle(right, heap);
}

void UseBack(int num, vector<int> heap) {
	if (num >= heap.size()) {
		return;
	}

	int left = num * 2 + 1;
	int right = num * 2 + 2;

	UseBack(left, heap);
	UseBack(right, heap);
	cout << heap[num] << " ";
}