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
   
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int num : v)
		pq.push(num);

	v.clear();

	while (pq.empty() == false)
	{
		v.push_back(pq.top());;
		pq.pop();
	}
}

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftidx = left;
	int rightidx = mid + 1;

	vector<int> res;

	while (leftidx <= mid && rightidx <= right)
	{
		if (v[leftidx] <= v[rightidx])
		{
			res.push_back(v[leftidx]);
			leftidx++;
		}
		else
		{
			res.push_back(v[rightidx]);
			rightidx++;
		}
	}

	if (leftidx > mid)
	{
		while (rightidx <= right)
		{
			res.push_back(v[rightidx]);
			rightidx++;
		}
	}
	else 
	{
		while (leftidx <= mid)
		{
			res.push_back(v[leftidx]);
			leftidx++;
		}
	}


	for (int i = 0; i < res.size(); i++)
		v[left + i] = res[i];
	

}

void MergeSort(vector<int>& v, int left, int right) 
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	MergeResult(v, left, mid, right);
}

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (low <= right && pivot >= v[low])
			low++;

		while (high >= left + 1 &&pivot <= v[high])
			high--;

		if (low < high)
			swap(v[low], v[high]);
	}

	swap(v[left], v[high]);
	return high;
}

void QuickSort(vector < int>& v, int left, int right)
{
	if (left > right)
		return;

	int pivot = Partition(v, left, right);
	QuickSort(v, left, pivot - 1);
	QuickSort(v, pivot + 1, right);
	
}


int main()
{
	vector<int> v;
	srand(time(0));

	for (int i = 0; i < 50; i++)
	{
		int randValue = rand() % 100;
		v.push_back(randValue);
	}

	QuickSort(v, 0, v.size() - 1);

	return 0;
}
