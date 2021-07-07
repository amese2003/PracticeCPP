#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string unfinish(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> completeCount;

	for (int i = 0; i < completion.size(); i++) {
		if (completeCount.find(completion[i]) == completeCount.end())
			completeCount[completion[i]] = 1;
		else
			completeCount[completion[i]]++;
	}

	for (int i = 0; i < participant.size(); i++) {
		if (completeCount.find(participant[i]) != completeCount.end()) {
			completeCount[participant[i]]--;

			if (completeCount[participant[i]] < 1)
				completeCount.erase(participant[i]);
		}
		else
			return participant[i];
	}

	return "";
}