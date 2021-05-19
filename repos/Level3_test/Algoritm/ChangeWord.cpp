#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void changeWord(string begin, string target, vector<string> words, vector<bool> visit, int cnt);
int change_cnt;

int UseChange(string begin, string target, vector<string> words) {
	vector<bool> visit(words.size(), false);
	change_cnt = 0;
	changeWord(begin, target, words, visit, 0);
	return change_cnt;
}

void changeWord(string begin, string target, vector<string> words, vector<bool> visit, int cnt) {
	for (int i = 0; i < words.size(); i++) {
		if (visit[i] == true)
			continue;

		int diff_size = 0;

		for (int j = 0; j < words[i].size(); j++) {
			if (begin[j] != words[i][j])
				diff_size++;
		}

		if (diff_size == 1) {
			if (words[i] == target) {
				if (change_cnt == 0)
					change_cnt = ++cnt;
				else
					change_cnt = min(change_cnt, ++cnt);
				return;
			}

			visit[i] = true;
			changeWord(words[i], target, words, visit, cnt + 1);
			visit[i] = false;
		}
	}
}