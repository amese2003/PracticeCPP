// NetworkFlow.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int node_count = 7;
const int inf = 2000000000;
int result;

int capacity[node_count][node_count];
int flow[node_count][node_count];
int visit_from[node_count];

vector<int> connect_node[node_count];

void maxFlow(int start, int end) {    
    while (1) {
        fill(visit_from, visit_from + node_count, -1);
        queue<int> visit;

        visit.push(start);

        while (!visit.empty()) {
            int current = visit.front();
            visit.pop();

            for (int i = 0; i < connect_node[current].size(); i++) {
                int next_node = connect_node[current][i];

                if (capacity[current][next_node] - flow[current][next_node] > 0 && visit_from[next_node] == -1) {
                    visit.push(next_node);
                    visit_from[next_node] = current;

                    if (next_node == end)
                        break;
                }
            }
        }

        if (visit_from[end] == -1)
            break;

        int min_flow = inf;
        for (int i = end; i != start; i = visit_from[i]) 
            min_flow = min(min_flow, capacity[visit_from[i]][i] - flow[visit_from[i]][i]);

        for (int i = end; i != start; i = visit_from[i]) {
            flow[visit_from[i]][i] += min_flow;
            flow[i][visit_from[i]] -= min_flow;
        }        

        result += min_flow;
    }
}

int main()
{
    connect_node[1].push_back(2);
    connect_node[2].push_back(1);
    capacity[1][2] = 12;

    connect_node[1].push_back(4);
    connect_node[4].push_back(1);
    capacity[1][4] = 11;

    connect_node[2].push_back(3);
    connect_node[3].push_back(2);
    capacity[2][3] = 6;

    connect_node[2].push_back(4);
    connect_node[4].push_back(2);
    capacity[2][4] = 3;

    connect_node[2].push_back(5);
    connect_node[5].push_back(2);
    capacity[2][5] = 12;

    connect_node[2].push_back(6);
    connect_node[6].push_back(2);
    capacity[2][6] = 9;

    connect_node[3].push_back(6);
    connect_node[6].push_back(3);
    capacity[3][6] = 8;

    connect_node[4].push_back(5);
    connect_node[5].push_back(4);
    capacity[4][5] = 9;

    connect_node[5].push_back(3);
    connect_node[3].push_back(5);
    capacity[5][3] = 3;

    connect_node[5].push_back(6);
    connect_node[6].push_back(5);

    capacity[5][6] = 4;
    maxFlow(1, 6);

    cout << result << endl;

    std::cout << "Hello World!\n";
}