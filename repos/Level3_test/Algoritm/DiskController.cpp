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

int DiskController(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int>>, compare> progress;
    int curWork = 0;
    int work_time = 0;

    while (curWork < jobs.size() || !progress.empty()) {
        if (curWork < jobs.size() && jobs[curWork][0] <= work_time) {
            progress.push(jobs[curWork++]);
            continue;
        }

        if (!progress.empty()) {
            work_time += progress.top()[1];
            answer += work_time - progress.top()[0];
            progress.pop();
        }
        else {
            work_time = jobs[curWork][0];
        }
    }

    return answer / jobs.size();
}