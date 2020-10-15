// BipartiteMatch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

const int node_count = 4;

vector<int> connected_node[node_count];
int node[node_count];
bool check_node[node_count];
int edge;

bool tryMatch(int n) {
    for (int i = 0; i < connected_node[n].size(); i++) {
        int match = connected_node[n][i];

        if (check_node[match]) 
            continue;
        check_node[match] = true;

        if (node[match] == 0 || tryMatch(node[match])) {
            node[match] = n;
            return true;
        }
    }
    return false;
}


int main()
{
    std::cout << "Hello World!\n";

    connected_node[1].push_back(1);
    connected_node[1].push_back(2);
    connected_node[1].push_back(3);

    connected_node[2].push_back(1);
    connected_node[3].push_back(2);

    int count = 0;
    for (int i = 1; i < node_count; i++) {
        fill(check_node, check_node + node_count, false);

        if (tryMatch(i))
            count++;
    }

    for (int i = 1; i < node_count; i++) {
        if (check_node[i])
            cout << node[i] << "->" << i << endl;
    }
}