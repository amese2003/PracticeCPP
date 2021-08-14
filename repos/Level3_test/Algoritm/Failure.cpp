#include <vector>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Failure {
public:
    Failure(int stage, float fail) : _stage(stage), _failure(fail) {}

public:
    int _stage;
    float _failure;


public:
    bool operator<=(const Failure& other)  const {

        if (_failure == other._failure)
            return _stage >= other._stage;

        return _failure <= other._failure;
    }

    bool operator>=(const Failure& other) const {

        if (_failure == other._failure)
            return _stage <= other._stage;

        return _failure >= other._failure;
    }

    bool operator<(const Failure& other) const {
        if (_failure == other._failure)
            return _stage > other._stage;

        return _failure < other._failure;
    }

    bool operator>(const Failure& other) const {
        if (_failure == other._failure)
            return _stage < other._stage;

        return _failure > other._failure;
    }
};


vector<int> FailureFind(int N, vector<int> stages) {
    vector<int> answer;


    priority_queue<Failure> failCheck;
    unordered_map<int, int> stageMap;

    for (int i = 0; i < stages.size(); i++) {
        stageMap[stages[i]]++;
    }

    int challanger = stages.size();
    for (int i = 1; i < N + 1; i++) {

        if (challanger == 0) {
            failCheck.push({ i, 0 });
            continue;
        }

        failCheck.push({ i, (float)stageMap[i] / challanger });
        challanger -= stageMap[i];
    }


    while (failCheck.empty() == false) {
        int stage = failCheck.top()._stage;
        failCheck.pop();

        answer.push_back(stage);
    }

    return answer;
}

void FailureUse() {
    vector<int> result = FailureFind(4, { 4,4,4,4,4 });
}