// DiskController.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

//int solution(vector<vector<int>> jobs) {
//    int answer = 0;
//
//    int work_time = 0;
//    int work = 0;
//
//    sort(jobs.begin(), jobs.end());
//
//    priority_queue<vector<int>, vector<vector<int>>, compare> progress;
//
//    while (work < jobs.size() || !progress.empty()) {
//
//        if (work < jobs.size() && jobs[work][0] <= work_time) {
//            progress.push(jobs[work++]);
//            continue;
//        }
//
//        if (!progress.empty()) {
//            work_time += progress.top()[1];
//            answer += work_time - progress.top()[0];
//            progress.pop();
//        } 
//        else {
//            work_time = jobs[work][0];
//        }
//    }
//
//    return answer / jobs.size();
//}

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int>>, compare> progress;
    int cur_work = 0;
    int work_time = 0;

    while (cur_work < jobs.size() || !progress.empty()) {

        if (cur_work < jobs.size() && jobs[cur_work][0] <= work_time) {
            progress.push(jobs[cur_work++]);
            continue;
        }

        if (!progress.empty()) {
            work_time += progress.top()[1];
            answer += work_time - progress.top()[0];
            progress.pop();
        }
        else {
            work_time = jobs[cur_work][0];
        }
    }

    return answer / jobs.size();
}



int main()
{
    int count = solution({ {0,3}, {1,9}, {2,6} });
    cout << count;
}