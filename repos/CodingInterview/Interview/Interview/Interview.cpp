#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
public:
    int Y;
    int X;
    int cost;
    int dir;
};



int solution(vector<vector<int>> board) {

    int answer = 2100000000;

    pair<int, int> dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    queue<Node> find_path;

    Node firstNode;
    firstNode.Y = 0;
    firstNode.X = 0;
    firstNode.cost = 0;
    firstNode.dir = -1;

    find_path.push(firstNode);
    board[0][0] = 1;

    while (!find_path.empty()) {
        Node cur = find_path.front();
        find_path.pop();


        if (cur.Y == board.size() - 1 && cur.X == board.size() - 1) {
            if (cur.cost < answer) answer = cur.cost;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nextY = cur.Y + dir[i].first;
            int nextX = cur.X + dir[i].second;

            if (nextY < 0 || nextY >= board.size()) continue;
            if (nextX < 0 || nextX >= board.size()) continue;
            if (board[nextY][nextX] == 1) continue;

            int nextCost = 0;

            if (cur.dir == -1 || cur.dir == i)
                nextCost = cur.cost + 100;
            else if(cur.dir != i)
                nextCost = cur.cost + 600;

            if (board[nextY][nextX] == 0 || board[nextY][nextX] >= nextCost) {
                board[nextY][nextX] = nextCost;
                Node nextNode;
                nextNode.Y = nextY;
                nextNode.X = nextX;
                nextNode.cost = nextCost;
                nextNode.dir = i;
                find_path.push(nextNode);
            }
        }
    }
    
    return answer;
}



int main()
{
    /*vector<vector<int>> map = {
        {0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };*/

    vector<vector<int>> map = {
        {0,0,1,0}, 
        {0,0,0,0},
        {0,1,0,1},
        {1,0,0,0}
    };


    /*vector<vector<int>> map = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };*/

    int ans = solution(map);

    cout << ans << endl;

}