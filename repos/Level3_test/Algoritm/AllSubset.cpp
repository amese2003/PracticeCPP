#include <iostream>
#include <vector>


using namespace std;

vector<vector<int>> GetSubset(vector<int> nums, int index)
{
	vector<vector<int>> allsubset;

	if (nums.size() == index)
	{
		vector<int> emptySubset = {};
		allsubset.push_back(emptySubset);
	}
	else
	{
		allsubset = GetSubset(nums, index + 1);
		int item = nums[index];

		vector<vector<int>> cachesubset{};

		for (vector<int> subset : allsubset)
		{
			vector<int> newsubset{};
			newsubset = subset;
			newsubset.push_back(item);
			cachesubset.push_back(newsubset);
		}

		for (auto cache : cachesubset)
		{
			allsubset.push_back(cache);
		}
	}

	return allsubset;
}