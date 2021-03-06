#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int NodeCount = 201;
int Node[NodeCount][NodeCount];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == i)
                Node[i][j] = 0;
            else
                Node[i][j] = 10000000;
        }
    }

    for (auto fare : fares) {
        Node[fare[0]][fare[1]] = fare[2];
        Node[fare[1]][fare[0]] = fare[2];
    }


    for (int pivot = 1; pivot <= n; pivot++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                Node[i][j] = min(Node[i][j], Node[i][pivot] + Node[pivot][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        answer = min(answer, Node[s][i] + Node[i][a] + Node[i][b]);

    return answer;
}

int main()
{
    


    std::cout << "Hello World!\n";
}