#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

// 오늘의 주제 : 이진 탐색 트리

// binary search

vector<int> numbers;
void BinarySearch(int N)
{
	int left = 0;
	int right = (int)numbers.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (N < numbers[mid])
		{
			cout << N << " < " << numbers[mid] << endl;
			right = mid - 1;
		}
		else if (N > numbers[mid])
		{
			cout << N << " > " << numbers[mid] << endl;
			left = mid + 1;
		}
		else
		{
			cout << "찾았다!" << endl;
			break;
		}
	}

	cout << "몰?루" << endl;
}

int main()
{

	numbers = vector<int>{ 1,8,15,23,32,44,56,63,81,91 };
	BinarySearch(82);
	return 0;
}
