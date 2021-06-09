#include <string>
#include <vector>

using namespace std;

long long Immigration(int n, vector<int> times) {
	long long min_time = 1;
	long long max_time = (long long)times.back() * n;
	long long mid_time = 0;

	long long midTime_people = 0;
	long long less_time = max_time;

	while (min_time <= max_time) {
		midTime_people = 0;
		mid_time = (min_time + max_time) / 2;

		for (int i = 0; i < times.size(); i++)
			midTime_people += mid_time / times[i];

		if (midTime_people < n)
			min_time = mid_time + 1;
		else {
			if (mid_time <= less_time)
				less_time = mid_time;

			max_time = mid_time - 1;
		}
	}

	return less_time;
}