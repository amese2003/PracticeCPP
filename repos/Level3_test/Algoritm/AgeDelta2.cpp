#include <iostream>
#include <string>

using namespace std;

pair<int, char> solution(string data) {

	char dec_10 = data[0];
	char dec_1 = data[1];

	int num_10 = data[0] - '0';
	int num_1 = data[1] - '0';

	int num = (num_10 * 10 + num_1);
	num += (dec_10 == '0') ? 2000 : 1900;

	int currentYear = 2019;
	int age = currentYear - num + 1;

	char sexual;

	if (num < 2000) {
		sexual = (data[7] == '1' ? 'M' : 'W');
	}
	else {
		sexual = (data[7] == '3' ? 'M' : 'W');
	}


	return make_pair(age, sexual);
}