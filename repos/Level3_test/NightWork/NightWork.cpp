#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> workQueue(works.begin(), works.end());


    int count = 0;
    while (count < n && !workQueue.empty()) {

        int front = workQueue.top();
        workQueue.pop();

        front--;

        if (front > 0)
            workQueue.push(front);

        count++;
    }

    while (!workQueue.empty()) {

        long long front = workQueue.top();
        workQueue.pop();
        
        answer += front * front;
    }


    cout << answer << endl;
    return answer;
}

int main() {

    solution(3, {1,1 });
    return 0;
}