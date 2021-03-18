#include <iostream>
#include <string>
#include <queue>

using namespace std;

string solution(string virused) {
	string fixed = "";
	char delta = 'a' - 'A';

	for (int i = 0; i < virused.length(); i++) {		
		char word = virused[i];

		if (word < 'A')
			continue;

		if (word >= 'A' && word <= 'Z') {
			word += delta;
			fixed += word;
			continue;
		}

		if (word >= 'a' && word <= 'z') {
			fixed += word;
			continue;
		}
	}

	return fixed;
}


int main() {

	string temp = solution("bE        au T I fu   L");

	return 0;
}