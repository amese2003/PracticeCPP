#include "pch.h"


int GetMaxSum(vector<int> a)
{
	int maxSum = 0;
	int sum = 0;

	for (size_t i = 0; i < a.size(); i++)
	{
		sum += a[i];
		if (maxSum < sum)
			maxSum = sum;
		else if (sum < 0)
			sum = 0;
	}

	return maxSum;
}

int GetMaxSum()
{

	int a = GetMaxSum({ 2,-8,3,2,4,-10 });
	cout << a << endl;
	return 0;
}

