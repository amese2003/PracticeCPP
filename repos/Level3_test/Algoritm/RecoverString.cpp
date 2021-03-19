#include <iostream>
#include <string>

using namespace std;

string RecoverString(string virused) {
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

void Input() {
	//string temp = solution("bE        au T I fu   L");
}