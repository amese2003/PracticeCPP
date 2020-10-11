// Network.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<bool> visit(computers.size(), false);

    for (int i = 0; i < n; i++) {
        if (visit[i]) continue;

        answer++;
        queue<int> computer;
        computer.push(i);        
        

        while (!computer.empty()) {
            int cur = computer.front();
            computer.pop();
            visit[cur] = true;

            for (int j = 0; j < n; j++) {
                if (computers[cur][j] && !visit[j]) 
                    computer.push(j);                
            }
        }
    }

    return answer;
}

int main() {

    int count = solution(3, { {1,1,0}, {1,1,0}, {0,0,1} });

}