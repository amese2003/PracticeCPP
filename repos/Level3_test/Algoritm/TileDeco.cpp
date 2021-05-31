
#include <string>
#include <vector>

using namespace std;

long long TileDeco(int N) {
	vector<long long> side_length(2, 1);

	for (int i = 2; i < N; i++) {
		long long new_length = side_length[i - 1] + side_length[i - 2];
		side_length.push_back(new_length);
	}

	return (side_length[N - 1] + (side_length[N - 1] + side_length[N - 2])) * 2;
}