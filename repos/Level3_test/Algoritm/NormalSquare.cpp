#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

long long solution(int w, int h) {
	long long width = (long long)w;
	long long height = (long long)h;

	return width * height - (width + height - gcd(width, height));
}