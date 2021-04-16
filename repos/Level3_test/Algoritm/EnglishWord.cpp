#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> EnglishWord(int n, vector<string> words) {
    vector<int> answer;
    answer.clear();
    vector<string> usedWord;
    int playGame = 1;
    int totalturn = 0;
    int recentturn = 0;
    int turnloop = 0;
    int playerturn = 0;
    int playerLoop = 0;
    bool gameOver = false;

    while (playGame)
    {
        usedWord.push_back(words[totalturn]);


        for (int i = 0; i < totalturn; i++)
        {
            if (words[totalturn] == usedWord[i])
            {
                gameOver = true;
                answer.push_back(playerturn + 1);
                answer.push_back(playerLoop + 1);
                break;
            }
        }

        if (gameOver == true)
            playGame = false;

        if ((usedWord[totalturn][0] != usedWord[recentturn][usedWord[recentturn].size() - 1]) && totalturn != recentturn)
        {
            gameOver = true;
            answer.push_back(playerturn + 1);
            answer.push_back(playerLoop + 1);
            break;
        }

        recentturn = totalturn;
        totalturn++;
        playerturn++;


        if (gameOver == true)
            playGame = 0;

        if (playerturn >= n)
        {
            playerturn = 0;
            turnloop++;
        }

        if (totalturn >= words.size())
        {
            playGame = false;
            if (gameOver == false)
            {
                answer.push_back(0);
                answer.push_back(0);
            }
        }

        if (totalturn % n == 0)
            playerLoop++;

    }
    return answer;
}