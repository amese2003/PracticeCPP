#include "pch.h"


int shrinkLeft(vector<int> arr, int min_index, int start)
{
	int comp = arr[min_index];

	for (int i = start - 1; i >= 0; i--)
	{
		if (arr[i] <= comp)
			return i + 1;
	}

	return 0;
}

int shrinkRight(vector<int> arr, int max_index, int start)
{
	int cmp = arr[max_index];
	for (size_t i = start; i < arr.size(); i++)
	{
		if (arr[i] >= cmp)
			return i - 1;
	}

	return arr.size() - 1;
}

int FindStartOfRightSubSequence(vector<int> arr)
{
	for (int i = arr.size() - 2; i >= 0; i--)
	{
		if (arr[i] > arr[i + 1])
			return i + 1;
	}

	return 0;
}

int FindEndofLeftSubSequence(vector<int> arr)
{
	for (size_t i = 1; i < arr.size(); i++)
	{
		if (arr[i] < arr[i - 1])
			return i - 1;
	}

	return arr.size() - 1;
}

void FindUnsortedSequence(vector<int> arr)
{
	int end_left = FindEndofLeftSubSequence(arr);
	if (end_left >= arr.size() - 1)
		return;

	int start_right = FindStartOfRightSubSequence(arr);

	int max_index = end_left;
	int min_index = start_right;

	for (int i = end_left + 1; i < start_right; i++)
	{
		if (arr[i] < arr[min_index])
			min_index = i;

		if (arr[i] > arr[max_index])
			max_index = i;
	}

	int left_index = shrinkLeft(arr, min_index, end_left);
	int right_index = shrinkRight(arr, max_index, start_right);

	cout << left_index << " " << right_index << endl;

}



int ifsort()
{
	FindUnsortedSequence({ 1,2,4,7,10,11,7,12,6,7,16,18,19 });
	return 0;
}

