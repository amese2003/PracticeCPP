#include "pch.h"

#define INF 2000000000

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    vector<vector<int>> edge(n + 1);

    for (int i = 0; i < edge_list.size(); i++)
    {
        int start = edge_list[i][0];
        int dest = edge_list[i][1];

        edge[start].push_back(dest);
        edge[dest].push_back(start);
    }

    vector<vector<int>> routeCost(k, vector<int>(n + 1, 2000000000));
    routeCost[0][gps_log[0]] = 0;


    for (int i = 1; i < k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (routeCost[i - 1][j] == 2000000000)
                continue;

            for (int mid = 0; mid < edge[j].size(); mid++)
            {
                int next = edge[j][mid];
                int delta = 0;
                if (gps_log[i] != next)
                    delta++;

                routeCost[i][next] = min(routeCost[i][next], routeCost[i - 1][j] + delta);
            }
        }
    }



    if (routeCost[k - 1][gps_log[k - 1]] < 2000000000)
        return routeCost[k - 1][gps_log[k - 1]];

    return -1;

    /*vector<vector<int>> Node(n + 1);
    vector<vector<int>> DP(k, vector<int>(n + 1, INF));
    for (int i = 0; i < edge_list.size(); i++)
    {
        int N1 = edge_list[i][0];
        int N2 = edge_list[i][1];
        Node[N1].push_back(N2);
        Node[N2].push_back(N1);
    }

    DP[0][gps_log[0]] = 0;
    for (int i = 1; i < k; i++)
    {
        for (int Cur = 1; Cur <= n; Cur++)
        {
            if (DP[i - 1][Cur] == INF) continue;

            for (int j = 0; j < Node[Cur].size(); j++)
            {
                int Next = Node[Cur][j];
                int Alpha = 0;
                if (gps_log[i] != Next) Alpha++;

                DP[i][Next] = min(DP[i][Next], DP[i - 1][Cur] + Alpha);
            }
        }
    }

    if (DP[k - 1][gps_log[k - 1]] < INF) return DP[k - 1][gps_log[k - 1]];
    return -1;*/

}

int bellman()
{
    solution(7, 10, { {1,2}, {1,3}, {2,3}, {2,4}, {3,4}, {3,5}, {4,6}, {5,6}, {5,7}, {6,7} }, 6, { 1,2,3,3,6,7 });
}

