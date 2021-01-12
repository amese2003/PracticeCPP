// WorldDistanceDelta.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include "LocationPair.h"

using namespace std;

LocationPair FindCloset(std::vector<std::string> words, std::string word1, std::string word2) {
    LocationPair* best = new LocationPair(-1, -1);
    LocationPair* current = new LocationPair(-1, -1);


    for (int i = 0; i < words.size(); i++) {
        std::string word = words[i];

        if (word.compare(word1) == 0) {
            current->location1 = i;
            best->UpdateWithMin(*current);
        }
        else if (word.compare(word2) == 0) {
            current->location2 = i;
            best->UpdateWithMin(*current);
        }
    }


    LocationPair answer = *best;

    delete(best);
    return answer;
}


int main()
{
    vector<string> test{ "test", "apple", "emp" };
    LocationPair temp = FindCloset(test, "test", "emp");

    cout << temp.location1 << " " << temp.location2 << endl;

	return 0;
}