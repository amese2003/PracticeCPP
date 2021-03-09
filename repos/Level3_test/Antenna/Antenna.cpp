#include <iostream>
#include <vector>
using namespace std;

int buildAntenna(int no_signal, int w) {

    int needCount = 0;
    if (no_signal > 0) {
        needCount = no_signal / ((w * 2) + 1);
        int remainder = no_signal % ((w * 2) + 1);
        
        if (remainder) 
            needCount++;
    }

    return needCount;
}


int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int no_signal;

    no_signal = stations[0] - w - 1;
    answer += buildAntenna(no_signal, w);


    for (int i = 1; i < stations.size(); i++) {
        int prevAntenna = stations[i - 1];
        int currAntenna = stations[i];

        no_signal = (currAntenna - w - 1) - (prevAntenna + w + 1) + 1;
        answer += buildAntenna(no_signal, w);
    }


    no_signal = n - (stations[stations.size() - 1] + w + 1) + 1;
    answer += buildAntenna(no_signal, w);


    return answer;
}

int main() {

    int test = solution(16, { 9 }, 2);


    return 0;
}