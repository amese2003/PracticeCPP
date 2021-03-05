#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, MinCount;
vector<int> Weak;
vector<int> Dist;

void TryVisit(int count, int pos, int visited) {
    if (count > Dist.size()) return;
    if (count >= MinCount) return;


    for (int i = 0; i < Weak.size(); i++) {
        int nextPos = (pos + i) % Weak.size();
        int delta = Weak[nextPos] - Weak[pos];

        if (nextPos < pos)
            delta += N;

        if (delta > Dist[Dist.size() - count])
            break;

        visited |= 1 << nextPos;
    }

    if (visited == (1 << Weak.size()) - 1) {
        MinCount = min(MinCount, count);
        return;
    }

    for (int i = 0; i < Weak.size(); i++) {
        if (visited & (1 << i)) continue;

        TryVisit(count + 1, i, visited);
    }

}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;

    sort(dist.begin(), dist.end());

    MinCount = INT32_MAX;
    N = n;
    Weak = weak;
    Dist = dist;

    for (int i = 0; i < weak.size(); i++) {
        TryVisit(1, i, 0);
    }

    if (MinCount == INT32_MAX)
        return -1;

    return MinCount;
}

int main() {
    solution(12, { 1,5,6,10 }, { 1,2,3,4 });
}