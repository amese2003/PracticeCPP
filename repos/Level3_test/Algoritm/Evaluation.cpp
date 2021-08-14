#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

char GetRank(float num)
{
    if (num >= 90)
        return 'A';
    else if (num >= 80 && num < 90)
        return 'B';
    else if (num >= 70 && num < 80)
        return 'C';
    else if (num >= 50 && num < 70)
        return 'D';
    else
        return 'F';
}

string Evaluation(vector<vector<int>> scores) {
    string answer = "";

    int people = scores.size();

    for (int row = 0; row < people; row++) {
        pair<int, int> maxScore = { 0 ,0 };
        pair<int, int> minScore = { 100, 0 };

        int score = 0;

        for (int col = 0; col < people; col++) {
            score += scores[col][row];


            if (maxScore.first < scores[col][row]) {
                maxScore.first = scores[col][row];
                maxScore.second = 1;
            }
            else if (maxScore.first == scores[col][row])
                maxScore.second++;

            if (minScore.first > scores[col][row]) {
                minScore.first = scores[col][row];
                minScore.second = 1;
            }
            else if (minScore.first == scores[col][row])
                minScore.second++;
        }

        int myScore = scores[row][row];
        int countPeople = people;

        if ((myScore == maxScore.first && maxScore.second == 1) || (myScore == minScore.first && minScore.second == 1)) {
            score -= myScore;
            countPeople--;
        }

        char rank = GetRank((float)score / countPeople);
        answer += rank;
    }


    return answer;
}


void main() {
    vector<vector<int>> nums;

    /*nums = vector<vector<int>>(
        {
            {100,90,98,88,65},
            {50,45,99,85,77},
            {47,88,95,80,67},
            {61,57,100,80,65},
            {24,90,94,75,65}
        }
    );*/

    /*nums = vector<vector<int>>(
        {
            {50,97},
            {50,87}
        }
    );*/

    nums = vector<vector<int>>(
        {
            {70,49,90},
            {68,50,38},
            {73,31,100},
        }
    );

    Evaluation(nums);
}