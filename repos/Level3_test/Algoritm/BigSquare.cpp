#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int BigSquare(vector<vector<int>> board)
{
    int answer = 0;
    int val = 1;
    bool check = false;
    vector<vector<int>> temp;
    int lengthY = board.size();
    temp = board;


    /*
    if(lengthY < 2 || lengthX < 2)
    {
        for(int i = 0; i< lengthY; i++)
        {
            for(int j = 0; j < lengthX; j++)
            {
                if(board[i][j] == 1)
                {
                    answer = 1;
                    check = true;
                    break;
                }
                else
                {
                    answer = 0;
                }
            }
            if(check == true)
                break;
        }
    }


    else
    {
        for(int i=1; i<lengthY; i++)
        {
            for(int j=1; j<lengthX; j++)
            {
                if(board[i][j] == 1)
                {
                    temp[i][j] =  max(min(board[i][j-1],board[i-1][j]) + 1,board[i-1][j-1]) + 1;
                }

                if(board[i][j] > answer)
                    answer = temp[i][j];
            }
        }
    }
    */


    for (int i = 0; i < lengthY; i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 0)
                continue;

            if (i < board.size() - 1 && j < board[i].size() - 1 && board[i + 1][j + 1] > 0 && board[i][j + 1] > 0 && board[i + 1][j] > 0)
            {
                val = min(board[i][j], min(board[i + 1][j], board[i][j + 1])) + 1;
                board[i + 1][j + 1] = val;
            }

            if (val > answer)
                answer = val;
        }
    }




    answer *= answer;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return answer;
}