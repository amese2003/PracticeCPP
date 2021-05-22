#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target);
void calculate(vector<int> numbers, int target, int cnt, int sum);
int target_count = 0;

int solution(vector<int> numbers, int target) {
	calculate(numbers, target, 0, 0);
	return target_count;
}

void calculate(vector<int> numbers, int target, int cnt, int sum) {
	if (cnt == numbers.size()) {
		if (sum == target)
			target_count++;

		return;
	}

	calculate(numbers, target, cnt + 1, sum + numbers[cnt]);
	calculate(numbers, targe