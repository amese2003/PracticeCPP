#include <vector>
#include <map>
using namespace std;

int MakeBingo(vector<vector<int>> board, vector<int> nums);

int bingo(vector<vector<int>> board, vector<int> nums) {
    int answer = MakeBingo(board, nums);
    return answer;
}

int MakeBingo(vector<vector<int>> board, vector<int> nums) {
    map<int, bool> bingoAnswer;

    int rowBingo = 0;
    int colBingo = 0;

    int MAX_SIZE = board.size();


    for (int i = 0; i < nums.size(); i++)
        bingoAnswer.insert({ nums[i], true });

    for (int col = 0; col < MAX_SIZE; col++) {
        int rowCount = 0;
        for (int row = 0; row < MAX_SIZE; row++) {
            if (!bingoAnswer.count(board[col][row]))
                break;
            rowCount++;
        }
        if (rowCount == MAX_SIZE) rowBingo++;
    }

    for (int row = 0; row < board.size(); row++) {
        int colCount = 0;
        for (int col = 0; col < board.size(); col++) {
            if (!bingoAnswer.count(board[col][row]))
                break;
            colCount++;
        }
        if (colCount == MAX_SIZE) colBingo++;
    }

    int upperdiagonalCount = 0;
    int downerdiagonalCount = 0;
    for (int row = 0; row < board.size(); row++) {
        if (bingoAnswer.count(board[row][row]))
            upperdiagonalCount++;
        if (bingoAnswer.count(board[MAX_SIZE - 1 - row][row]))
            downerdiagonalCount++;

    }
    if (upperdiagonalCount == MAX_SIZE) colBingo++;
    if (downerdiagonalCount == MAX_SIZE) rowBingo++;

    return rowBingo + colBingo;
}