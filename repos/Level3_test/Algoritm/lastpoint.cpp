#include <iostream>
#include <vector>
using namespace std;

vector<int> lastpoint(vector<vector<int> > v) {
    vector<int> ans(2, 0);

    ans[0] = v[0][0] ^ v[1][0] ^ v[2][0];
    ans[1] = v[0][1] ^ v[1][1] ^ v[2][1];

    return ans;
}