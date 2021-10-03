#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> clothesCount;

	for (auto clothe : clothes) {
		clothesCount[clothe[1]]++;
	}

	for (auto clothe : clothesCount) {
		answer *= clothe.second + 1;
	}

	return answer - 1;
}