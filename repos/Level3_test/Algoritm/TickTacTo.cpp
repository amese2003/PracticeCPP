#include <iostream>
#include <string>
#include <vector>

using namespace std;

int hashMap[19683];

enum
{
	DEFAULT = 2,
	WIN = 1,
	LOSE = -1,
	DRAW = 0,
};

int HashBoard(vector<vector<char>>& board)
{
	int ret = 0;

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			ret = ret * 3;

			if (board[y][x] == 'o')
				ret += 1;
			else if (board[y][x] == 'x')
				ret += 2;
		}
	}

	return ret;
}

bool IsFinished(vector<vector<char>>& board, char turn)
{
	for (int i = 0; i < 3; i++)
		if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn)
			return true;

	for (int i = 0; i < 3; i++)
		if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn)
			return true;

	if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)
		return true;

	if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
		return true;

	return false;
}

int CanWin(vector<vector<char>>& board, char turn)
{
	if (IsFinished(board, 'o' + 'x' - turn))
		return LOSE;

	int key = HashBoard(board);
	int& ret = hashMap[key];

	if (ret != DEFAULT)
		return ret;

	int minVal = DEFAULT;

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[y][x] != '.')
				continue;

			board[y][x] = turn;
			minVal = min(minVal, CanWin(board, 'o' + 'x' - turn));
			board[y][x] = '.';
		}
	}

	if (minVal == DRAW || minVal == DEFAULT)
		return ret = DRAW;

	return ret = -minVal;
}



int TickTacTo()
{
	vector<vector<char>> board = vector<vector<char>>
	{
		{'o', 'x', 'x'},
		{'.', 'o', '.'},
		{'o', '.', '.'},
	};

	for (int i = 0; i < 19683; i++)
		hashMap[i] = DEFAULT;

	//memset(hashMap, 0, 19683);

	int x = CanWin(board, 'o');
	cout << x << endl;
	return 0;
}
