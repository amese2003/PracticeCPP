#include <iostream>
#include <vector>

#define MAX 101


using namespace std;

vector<int> graph[MAX];
int match[MAX];
bool visit[MAX];
int nodecount = 3;

bool Matchmaking(int node)
{
	for (int i = 0; i < graph[node].size(); i++)
	{
		int target = graph[node][i];

		if (visit[target])
			continue;

		visit[target] = true;

		if (match[target] == 0 || Matchmaking(match[target]))
		{
			match[target] = node;
			return true;
		}
	}

	return false;
}

int tryMatch() {

	graph[1].push_back(1);
	graph[1].push_back(2);
	graph[1].push_back(3);

	graph[2].push_back(1);
	graph[3].push_back(2);

	int count = 0;

	for (int i = 1; i <= nodecount; i++)
	{
		fill(visit, visit + MAX, false);

		if (Matchmaking(i))
			count++;
	}

	for (int i = 1; i <= 100; i++)
	{
		if (match[i] != 0)
		{
			cout << match[i] << "->" << i << endl;
		}
	}


	return 0;
}