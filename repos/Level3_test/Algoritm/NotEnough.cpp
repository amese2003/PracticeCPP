#include <vector>
#include <iostream>
#include <math.h>

using namespace std;



long long NotEnough(int price, int money, int count) {
    long long answer = 0;

    for (size_t i = 1; i <= count; i++) {
        long long expect = (long long)price * i;
        answer += expect;
    }

    answer = answer - money;

    if (answer <= 0)
        return 0;

    return answer;
}


