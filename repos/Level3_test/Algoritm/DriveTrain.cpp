#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string TrainDrive(vector<int> trainNum) {

	stack<int> middle;
	vector<int> trainArrive(trainNum.size(), 0);
	string work = "";

	int pos = 0;
	int driveTrain = 0;

	for (int i = 0; i < trainArrive.size(); i++)
		trainArrive[i] = i + 1;

	while (driveTrain < trainNum.size()) {
		if (!middle.empty() && middle.top() == trainArrive[pos]) {
			while (!middle.empty() && middle.top() == trainArrive[pos]) {
				middle.pop();
				work += 'O';
				pos++;
			}
		}

		middle.push(trainNum[driveTrain]);
		work += 'P';
		driveTrain++;
	}



	while (!middle.empty() && middle.top() == trainArrive[pos]) {
		middle.pop();
		work += 'O';
		pos++;
	}

	if (!middle.empty())
		return "Impossible";


	return work;
}


int UseDriveTrain() {

	vector<int> train{ 2,3,1,4 };

	string answer = TrainDrive(train);

	return 0;
}