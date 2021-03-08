#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>;

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);

    unordered_map<string, int> gemMap;
    unordered_set<string> gemSet(gems.begin(), gems.end());

    int minSize = 0;
    int startPos = 0;
    int endPos = 0;

    for (int i = 0; i < gems.size(); i++) {
        gemMap[gems[i]]++;

        if (gemMap.size() == gemSet.size())
            break;

        endPos++;
    }

    minSize = endPos - startPos;
    answer[0] = startPos + 1;
    answer[1] = endPos + 1;

    while (endPos < gems.size()) {
        string key = gems[startPos];
        gemMap[key]--;
        startPos++;

        if (gemMap[key] == 0) {
            endPos++;

            while (endPos < gems.size()) {
                gemMap[gems[endPos]]++;

                if (key == gems[endPos])
                    break;

                endPos++;
            }
            
            if (endPos == gems.size())
                break;
        }

        if (endPos - startPos < minSize) {
            answer[0] = startPos + 1;
            answer[1] = endPos + 1;
            minSize = endPos - startPos;
        }
    }


    return answer;
}


int main()
{
    std::cout << "Hello World!\n";
    solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
}