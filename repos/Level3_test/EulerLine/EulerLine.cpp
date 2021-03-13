#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int _neighbor, _count;
	Edge* _reverse;
	
	Edge() : Edge(-1, 0) {}
	Edge(int neighbor, int count) : _neighbor(neighbor), _count(count), _reverse(nullptr){}

	~Edge() {
		if (_reverse != nullptr)
			delete _reverse;
	}
};

int N, degree[1000];
vector<Edge*> ways[1000];
bool visited[1000];

int dfs(int current) {
	int result = 1;
	visited[current] = true;

	for (auto w : ways[current]) {
		int next = w->_neighbor;

		if (visited[current] == false)
			result == dfs(next);
	}

	return result;
}

void Eulerian(int curr) {
	for (auto w : ways[curr]) {
		if (w->_count > 0) {
			w->_count--;
			w->_reverse->_count--;
			Eulerian(w->_neighbor);
		}
	}

	cout << curr + 1 << endl;
}

int main() {
	cout << "노드수는 몇개?" << "\n" << ">> ";
	cin >> N;
	cout << "\n";

	vector<vector<int>> nodeValue =
	{
		{0, 1, 0, 1, 1, 1},
		{1, 0, 1, 1, 1, 0},
		{0, 1, 0, 1, 0, 0},
		{1, 1, 1, 0, 1, 0},
		{1, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 1, 0}
	};


	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int value = nodeValue[y][x];

			if (x > y && value > 0) {
				Edge* edge1 = new Edge(x, value);
				Edge* edge2 = new Edge(y, value);

				edge1->_reverse = edge2;
				edge2->_reverse = edge1;

				ways[y].push_back(edge1);
				ways[x].push_back(edge2);

				degree[y] += value;
				degree[x] += value;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (degree[i] % 2 == 1) {
			return 0;
		}
	}

	bool flag = false;
	int start = -1;

	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			int visitSize = dfs(i);

			if (visitSize > 1) {
				if (flag) {
					return 0;
				}
				else {
					start = i;
					flag = true;					
				}
			}
		}
	}

	if (start == -1)
		start = 0;


	Eulerian(start);
}