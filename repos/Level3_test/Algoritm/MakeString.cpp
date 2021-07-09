#include <iostream>
#include <vector>

using namespace std;

bool CheckString(string n);
string MakeString(string bracket);
string solution(string p);

bool CheckString(string n) {
	int count = 0;
	for (int i = 0; i < n.length(); i++) {
		if (n[i] == '(') {
			count++;
		}
		else {
			if (count <= 0) return false;
			count--;
		}
	}
	return true;
}

string MakeString(string bracket) {
	if (bracket == "") return bracket;
	string u = "";
	string v = "";
	int count = 0;

	for (int i = 0; i < bracket.length(); i++) {
		if (bracket[i] == '(')
			count++;
		else
			count--;

		if (count == 0) {
			u = bracket.substr(0, i + 1);
			v = bracket.substr(i + 1);
			break;
		}
	}

	if (CheckString(u)) {
		return u + MakeString(v);
	}
	else {
		string making = "(";
		making += MakeString(v) + ')';
		u = u.substr(1, u.length() - 2);

		for (int i = 0; i < u.length(); i++) {
			if (u[i] == '(') making += ')';
			else making += '(';
		}
		return making;
	}
}

string MakingString(string p) {
	return MakeString(p);
}