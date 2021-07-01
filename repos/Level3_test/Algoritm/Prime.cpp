#include <vector>
#include <iostream>
using namespace std;

bool visit[51];

bool is_prime(int num)
{
    int base = 2;
    while (base < num / 2)
    {
        if (num % base == 0)
            return false;
        ++base;
    }
    return true;
}

void dfs(vector<int> nums, int idx, int sum, int nCandi, int* nPrime)
{
    int num_size = nums.size();

    if (nCandi == 3)
    {
        if (is_prime(sum))
            (*nPrime)++;
        return;
    }
    for (int i = idx; i < num_size; i++)
    {
        if (visit[i])
            continue;
        visit[i] = true;
        dfs(nums, i, sum + nums[i], nCandi + 1, nPrime);
        visit[i] = false;
    }
}

int Prime(vector<int> nums) {
    int answer = 0;
    int num_size = nums.size();
    for (int i = 0; i < num_size; i++)
    {
        visit[i] = true;
        dfs(nums, i, nums[i], 1, &answer);
        visit[i] = false;
    }

    return answer;
}