#include <iostream>
#include <vector>
#define max(a,b) ((a<b)?(b):(a))

using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;

    vector<int> sticker_max(sticker.size(), 0);

    if (sticker.size() == 1)
        return sticker.back();

    sticker_max[0] = sticker[0];
    sticker_max[1] = sticker[0];

    for (int i = 2; i < sticker.size() - 1; i++) {
        sticker_max[i] = max(sticker[i] + sticker_max[i - 2], sticker_max[i - 1]);
    }

    answer = sticker_max[sticker.size() - 2];

    sticker_max[0] = 0;
    sticker_max[1] = sticker[1];

    for (int i = 2; i < sticker.size(); i++) {
        sticker_max[i] = max(sticker[i] + sticker_max[i - 2], sticker_max[i - 1]);
    }

    answer = max(answer, sticker_max[sticker_max.size() - 1]);
    return answer;
}