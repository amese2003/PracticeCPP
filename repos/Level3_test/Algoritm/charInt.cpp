#include <vector>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int WordInt(string s) {
    int answer = 0;

    unordered_map<string, int> charMap;

    charMap["zero"] = 0;
    charMap["one"] = 1;
    charMap["two"] = 2;
    charMap["three"] = 3;
    charMap["four"] = 4;
    charMap["five"] = 5;
    charMap["six"] = 6;
    charMap["seven"] = 7;
    charMap["eight"] = 8;
    charMap["nine"] = 9;

    string get = "";

    for (int i = 0; i < s.length(); i++) {
        char temp = s[i];
        get += temp;

        if (charMap.find(get) != charMap.end()) {
            answer *= 10;
            answer += charMap[get];
            get = "";
        }

        if (temp >= '0' && temp <= '9') {
            int ans = temp - '0';
            answer *= 10;
            answer += ans;
            get = "";
        }
    }


    return answer;
}
