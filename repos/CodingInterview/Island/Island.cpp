﻿#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int> &a, const vector<int> &b){
    return a[2] <= b[2];
}

int getParent(int n, vector<int> parent) {
    if (parent[n] == n) return n;
    else return getParent(parent[n], parent);
}

void unionParent(int n, int m, vector<int> &parent) {
    int nParent = getParent(n, parent);
    int mParent = getParent(m, parent);

    if (nParent <= mParent) parent[m] = nParent;
    else parent[n] = mParent;
}

bool findParent(int n, int m, vector<int> parent) {
    int nParent = parent[n];
    int mParent = parent[m];

    if (nParent == mParent) return true;
    else return false;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parent(costs.size());

    for (int i = 0; i < parent.size(); i++)
        parent[i] = i;

    sort(costs.begin(), costs.end(), compare);

    for (int i = 0; i < costs.size(); i++) {
        int start = getParent(costs[i][0], parent);
        int dest = getParent(costs[i][1], parent);
        int cost = costs[i][2];

        if (start != dest) {            
            unionParent(start, dest, parent);      
            answer += cost;
        }
    }

    return answer;
}

int main()
{
    int temp = solution(4, { {0, 1, 1} ,{0, 2, 2},{1, 2, 5},{1, 3, 1},{2, 3, 8} });
    std::cout << "Hello World!\n";
}