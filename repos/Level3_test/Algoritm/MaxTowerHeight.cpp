#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Block {
public:
	Block(int size, int height, int weight) : _size(size), _height(height), _weight(weight) {}

public:
	bool operator<(const Block& cmp) const {
		return _size < cmp._size;
	}

	bool operator>(const Block& cmp) const {
		return !operator<(cmp);
	}

public:
	int _size;
	int _height;
	int _weight;
};

void MaxTower() {

	vector<Block> block;
	block.push_back({ 25,3,4 });
	block.push_back({ 4,4,6 });
	block.push_back({ 9,2,3 });
	block.push_back({ 16,2,5 });
	block.push_back({ 1,5,2 });

	sort(block.begin(), block.end(), greater<Block>());

	vector<int> count(block.size(), 0);

	for (int i = 0; i < block.size(); i++)
		count[i] = block[i]._height;

	for (int i = 1; i < block.size(); i++) {

		for (int j = i - 1; j >= 0; j--) {

			if (block[j]._weight > block[i]._weight) {
				count[i] = max(count[i], count[j] + block[i]._height);
			}

		}
	}
}