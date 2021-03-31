#include <string>
#include <vector>

using namespace std;

vector<int> TestDevelop(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> progress = progresses;
	vector<int> speed = speeds;

	while (true) {
		if (progress.size() == 0) break;

		for (int i = 0; i < speed.size(); i++) {
			if (progress[i] >= 100) continue;
			progress[i] += speed[i];
		}

		if (progress.front() >= 100)
		{
			int count = 0;
			while (progress.size() > 0 && progress.front() >= 100) {
				progress.erase(progress.begin());
				speed.erase(speed.begin());
				count++;
			}
			answer.push_back(count);
		}
	}

	return answer;
}