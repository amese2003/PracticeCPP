#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char check_char) {
	vector<string> internal;
	stringstream ss(str);

	string temp;

	while (getline(ss, temp, check_char))
		internal.push_back(temp);

	return internal;
}

vector<int> DoublePrioirty(vector<string> operations) {
	vector<int> answer(2, 0);

	priority_queue<int, vector<int>, greater<int>> high;
	priority_queue<int, vector<int>, less<int>> low;

	for (int i = 0; i < operations.size(); i++) {
		string oper_string = operations[i];
		vector<string> split_str = split(oper_string, ' ');

		char oper = split_str[0].front();
		int num = atoi(split_str[1].c_str());


		if (oper == 'I') {
			high.push(num);
			low.push(num);
		}

		if (oper == 'D') {
			queue<int> temp;

			if (!high.empty()) {
				int size = high.size();
				int cmp = 0, front;

				if (num == -1) {
					front = high.top();
					high.pop();

					for (int i = 0; i < size; i++) {
						cmp = low.top();
						low.pop();

						if (cmp != front)
							temp.push(cmp);
					}

					while (!temp.empty()) {
						int fr = temp.front();
						temp.pop();
						low.push(fr);
					}
				}
				else {
					front = low.top();
					low.pop();

					for (int i = 0; i < size; i++) {
						cmp = high.top();
						high.pop();

						if (cmp != front)
							temp.push(cmp);
					}

					while (!temp.empty()) {
						int fr = temp.front();
						temp.pop();
						high.push(fr);
					}
				}
			}
		}
	}

	if (!high.empty()) return { low.top(), high.top() };

	return answer;
}