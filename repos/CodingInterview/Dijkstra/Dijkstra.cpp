// Dijkstra.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 100000000;
vector<pair<int, int>> connect_node[7];
int cost[7];

void dijkstra(int start) {
    cost[start] = 0;
    priority_queue<pair<int, int>> visit;

    visit.push(make_pair(start, 0));

    while (!visit.empty()) {
        int currentNode = visit.top().first;
        int cur_cost = -visit.top().second;
        visit.pop();

        if (cost[currentNode] < cur_cost) continue;

        for (int i = 0; i < connect_node[currentNode].size(); i++) {
            int nextNode = connect_node[currentNode][i].first;
            int next_cost = cur_cost + connect_node[currentNode][i].second;

            if (next_cost < cost[nextNode]) {
                cost[nextNode] = next_cost;
                visit.push(make_pair(nextNode, -next_cost));
            }
        }
    }
}



int main()
{
    std::cout << "Hello World!\n";
    
    int node = 6;

    for (int i = 1; i <= node; i++) 
        cost[i] = inf;
    
    connect_node[1].push_back(make_pair(2, 2));
    connect_node[1].push_back(make_pair(3, 5));
    connect_node[1].push_back(make_pair(4, 1));

    connect_node[2].push_back(make_pair(1, 2));
    connect_node[2].push_back(make_pair(3, 3));
    connect_node[2].push_back(make_pair(4, 2));

    connect_node[3].push_back(make_pair(1, 5));
    connect_node[3].push_back(make_pair(2, 3));
    connect_node[3].push_back(make_pair(4, 3));
    connect_node[3].push_back(make_pair(5, 1));
    connect_node[3].push_back(make_pair(6, 5));

    connect_node[4].push_back(make_pair(1, 1));
    connect_node[4].push_back(make_pair(2, 2));
    connect_node[4].push_back(make_pair(3, 3));
    connect_node[4].push_back(make_pair(5, 1));

    connect_node[5].push_back(make_pair(3, 1));
    connect_node[5].push_back(make_pair(4, 1));
    connect_node[5].push_back(make_pair(6, 2));

    connect_node[6].push_back(make_pair(3, 5));
    connect_node[6].push_back(make_pair(5, 2));

    dijkstra(1);

    for (int i = 1; i <= node; i++)
        cout << cost[i] << endl;
}