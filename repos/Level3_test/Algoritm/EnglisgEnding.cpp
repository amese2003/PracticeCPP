#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool CheckUse(vector<string> words, string useWord, int pos);
vector<int> EnglishEnd(int n, vector<string> words);

vector<int> EnglishEnd(int n, vector<string> words) {
	vector<int> answer(2, 0);

	int turn = 0;
	int person = 0;
	char nextChar = ' ';

	for (int i = 0; i < words.size(); i++) {
		person = i % n;
		if (person == 0) turn++;

		if (nextChar != ' ') {
			if (nextChar != words[i][0] || CheckUse(words, i)) {
				answer[0] = person + 1;
				answer[1] = turn;
				return answer;
			}
		}
		nextChar = words[i].back();
	}
	return answer;
}


bool CheckUse(vector<string> words, int pos) {
	for (int i = 0; i < pos; i++)
		if (words[i] == words[pos]) return true;
	return false;
}