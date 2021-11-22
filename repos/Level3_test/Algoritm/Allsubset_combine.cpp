//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int>> GetSubCom(vector<int> nums)
//{
//	vector<vector<int>> allsubset;
//
//	int max = 1 << nums.size();
//
//	for (int k = 0; k < max; k++)
//	{
//		vector<int> subset = convertIntToSet(k, nums);
//		allsubset.push_back(subset);
//	}
//
//	return allsubset;
//}
//
//vector<int> convertIntToSet(int x, vector<int> nums)
//{
//	vector<int> subset{};
//	int index = 0;
//
//	for (int k = x; k > 0; k >>= 1)
//	{
//		if ((k & 1) == 1)
//			subset.push_back(nums[index]);
//
//		index++;
//	}
//
//	return subset;
//}