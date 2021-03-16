#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MakeString(string& pattern, const int count) {
	pattern += "I";
	string addPattern = "OI";

	for (int i = 0; i < count; i++) 
		pattern += addPattern;
}

void MakePatternNum(vector<int>& table, string pattern) {

	int count = 0;
	int j = 0;

	for (int i = 1; i < pattern.length(); i++) {
		while (j > 0 && pattern[j] != pattern[i]) {
			j = table[j - 1];
		}

		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
}

int KMP(const string& pattern, const string& question) {

	int count = 0;
	vector<int> table(question.length(), 0);
	int j = 0;
	int patternLength = pattern.length() - 1;

	for (int i = 0; i < question.size(); i++) {
		while (j > 0 && question[i] != pattern[j]) {
			j = table[j - 1];
		}

		if (question[i] == pattern[j]) {
			if (j == patternLength) {
				count++;
				j = table[j];
			}
			else {
				table[i] = ++j;
			}
		}
	}

	return count;
}


int main() {

	int count = 1;
	string pattern = "";
	string Question = "OOIOIOIOIIOII";
	int answer = 0;

	MakeString(pattern, count);

	vector<int> patternNum(pattern.length(), 0);

	KMP(pattern, Question);


	return answer;
}