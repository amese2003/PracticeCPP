#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long minTime = 1;
    long long midTime = 0;
    long long maxTime = (long long)times.back() * n;

    while (minTime <= maxTime) {
        long long midTime_people = 0;
        midTime = (minTime + maxTime) / 2;        

        for (int i = 0; i < times.size(); i++)
            midTime_people +=  midTime / times[i];

        if (midTime_people < n) {
            minTime = midTime + 1;
        }
        else {
            if (midTime <= minTime)
                minTime = midTime;
            maxTime = midTime - 1;
        }     
    }

    return minTime;
}

int main()
{
    std::cout << "Hello World!\n";
}