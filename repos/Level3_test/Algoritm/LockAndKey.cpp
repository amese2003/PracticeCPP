#include <string>
#include <iostream>
#include <vector>
using namespace std;


bool LockAndKey(vector<vector<int>> key, vector<vector<int>> lock);
void RotateKey(vector<vector<int>>& key);
bool InsertKey(int colPos, int rowPos, vector<vector<int>> key, vector<vector<int>> board);
int KEY_SIZE = 0;
int LOCK_SIZE = 0;
int BOARD_SIZE = 0;


bool LockAndKey(vector<vector<int>> key, vector<vector<int>> lock) {
	KEY_SIZE = key.size();
	LOCK_SIZE = lock.size();
	BOARD_SIZE = KEY_SIZE * 2 + LOCK_SIZE;

	vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));

	for (int col = 0; col < LOCK_SIZE; col++) {
		for (int row = 0; row < LOCK_SIZE; row++) {
			board[col + KEY_SIZE][row + KEY_SIZE] = lock[col][row];
		}
	}

	for (int col = 0; col < BOARD_SIZE - KEY_SIZE; col++) {
		for (int row = 0; row < BOARD_SIZE - KEY_SIZE; row++) {
			for (int i = 0; i < 4; i++) {
				if (InsertKey(col, row, key, board))
					return true;

				RotateKey(key);
			}

			RotateKey(key);
		}
	}

	return false;
}


void RotateKey(vector<vector<int>>& key) {
	vector<vector<int>> buffer(KEY_SIZE, vector<int>(KEY_SIZE, 0));

	for (int col = 0; col < KEY_SIZE; col++) {
		for (int row = 0; row < KEY_SIZE; row++) {
			buffer[row][KEY_SIZE - 1 - col] = key[col][row];
		}
	}

	key = buffer;
}

bool InsertKey(int colPos, int rowPos, vector<vector<int>> key, vector<vector<int>> board) {

	for (int col = 0; col < KEY_SIZE; col++) {
		for (int row = 0; row < KEY_SIZE; row++) {
			board[col + colPos][row + rowPos] += key[col][row];
		}
	}

	for (int col = KEY_SIZE; col < BOARD_SIZE - KEY_SIZE; col++) {
		for (int row = KEY_SIZE; row < BOARD_SIZE - KEY_SIZE; row++) {
			if (board[col][row] != 1)
				return false;
		}
	}

	return true;
}