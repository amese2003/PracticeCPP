#include <iostream>
#include <vector>

using namespace std;


void CreateGraph_1()
{
	struct Node
	{
		Node* prev;
		Node* next;
		int data;
	};

	struct Vertex
	{
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(0);

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	bool check = false;
	for (Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			check = true;
			break;
		}
	}

}



void CreateGraph_2()
{
	struct Node
	{
		Node* prev;
		Node* next;
		int data;
	};

	struct Vertex
	{
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(6);
	
	// 연결 목록을 따로 관리
	vector<vector<int>> adjacent(6);


	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	bool check = false;
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			check = true;
			break;
		}
	}

	vector<int>& adj = adjacent[0];
	bool find2 = (std::find(adj.begin(), adj.end(), 3) != adj.end());
}




void CreateGraph_3()
{
	struct Node
	{
		Node* prev;
		Node* next;
		int data;
	};

	struct Vertex
	{
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(6);

	// 연결 목록을 따로 관리
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	vector<vector<int>> adjacent2 = 
	{
		vector<int> {-1, 15, -1, 35, -1, -1},
		vector<int> {15, -1, 5, 10, -1, -1},
		vector<int> {-1 ,-1 ,-1 ,-1 ,-1, -1},
		vector<int> {-1 ,-1 ,-1 ,-1 ,5, -1},
		vector<int> {-1 ,-1 ,-1 ,-1 ,-1, -1},
		vector<int> {-1 ,-1 ,-1 ,-1 ,5, -1},
	}

}
int main()
{


}
