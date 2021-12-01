#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include "BinarySearchTree.h"
#include <thread>

using namespace std;

// 오늘의 주제 : 이진 탐색 트리

void BubbleSort(vector<int>& v)
{
	const int n = v.size();

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[i];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

void SelectionSort(vector<int>& v)
{
	const int n = v.size();

	for (int i = 0; i < n - 1; i++)
	{
		int bestidx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[bestidx])
			{
				bestidx = j;
			}
		}

		int temp = v[i];
		v[i] = v[bestidx];
		v[bestidx] = temp;
	}

}

void InsertionSort(vector<int>& v) 
{
	const int n = v.size();

	for (int i = 1; i < n; i++)
	{
		int insertData = v[i];

		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (v[i] > insertData)
				v[j + 1] = v[j];
			else
				break;
		}

		v[j + 1] = insertData;
	}
}
   


int main()
{
	vector<int> v{ 1,5,3,4,2 };


	InsertionSort(v);

	return 0;
}
