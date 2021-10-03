#include <iostream>
#include <string>
#include <vector>
#define min(a,b) ((a>b)?(b):(a))

using namespace std;

int solution(vector<string> strs, string t)
{
    vector<int> result(t.length(), t.length() + 1);

    for (int t_pos = 0; t_pos < t.length(); t_pos++)
    {
        for (int i = 0; i < strs.size(); i++)
        {
            int str_i_size = strs[i].size() - 1;
            int str_cnt = 0;

            for (str_cnt = 0; str_cnt < strs[i].size(); str_cnt++)
            {
                if (!(str_i_size - str_cnt < 0 || t_pos - str_cnt < 0) && strs[i][str_i_size - str_cnt] == t[t_pos - str_cnt])
                    continue;
                else
                    break;
            }

            if (str_cnt == strs[i].size())
            {
                if (t_pos - str_cnt >= 0)
                    result[t_pos] = min(result[t_pos], 1 + result[t_pos - str_cnt]);
                else
                    result[t_pos] = 1;
            }
        }
    }

    if (result[t.length() - 1] == t.length() + 1)
        return -1;

    return result[t.length() - 1];
}