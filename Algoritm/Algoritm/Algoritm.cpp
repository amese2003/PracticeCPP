#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));

	adjacent[0][1] = 15;
	adjacent[0][3] = 35;
	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;
	adjacent[3][4] = 5;
	adjacent[5][4] = 5;

}

void Dijikstra(int here)
{
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	list<VertexCost> discovered;
	vector<int> best(6, INT32_MAX);
	vector<int> parent(6, -1);

	discovered.push_back(VertexCost{ here, 0 });
	best[here] = 0;
	parent[here] = here;

	while (discovered.empty() == false)
	{
		list<VertexCost>::iterator bestit;
		int bestCost = INT32_MAX;

		for (auto it = discovered.begin(); it != discovered.end(); it++)
		{
			const int vertex = it->vertex;
			const int cost = it->cost;

			if (cost < bestCost)
			{
				bestCost = it->cost;
				bestit = it;
			}
		}

		int cost = bestit->cost;
		here = bestit->vertex;
		discovered.erase(bestit);

		if (best[here] < cost)
			continue;

		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == -1)
				continue;

			int nextCost = best[here] + adjacent[here][there];
			if (nextCost >= best[there])
				continue;


			discovered.push_back(VertexCost{ there, nextCost });
			best[there] = nextCost;
			parent[there] = here;
		}

	}

}


int main()
{
	CreateGraph();
	Dijikstra(0);

	return 0;
}
