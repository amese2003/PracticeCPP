#include <string>
#include <vector>

using namespace std;

vector<long long> Xterm(int x, int n) {
    vector<long long> answer;

    for (int i = 1; i < n + 1; i++)
    {
        answer.push_back(x * i);
    }


    return answer;
}