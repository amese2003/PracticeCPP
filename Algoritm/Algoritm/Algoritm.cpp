#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include "BinarySearchTree.h"
#include <thread>

using namespace std;

// 오늘의 주제 : 최소 스패닝 트리

// 상호 베타적 집합 (Disjoint Set)
// -> Union-Find (합치기 - 찾기)

class NaiveDisjointSet
{
public:
	NaiveDisjointSet(int n) : _parent(n)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return Find(_parent[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		_parent[u] = v;
	}

private:
	vector<int> _parent;
};

// (Union-By-Rank)

class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n), _rank(n, 1)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return _parent[u] = Find(_parent[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			::swap(u, v);

		//_rank[u] <= _rank[v]
		_parent[u] = v;

		if (_rank[u] == _rank[v])
			_rank[v]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;
};

int main()
{
	DisjointSet teams(1000);

	teams.Merge(10, 1);

	int teamId = teams.Find(1);
	int teamId2 = teams.Find(10);

	teams.Merge(1, 3);

	int teamId3 = teams.Find(1);
	int teamId4 = teams.Find(3);

	return 0;
}
