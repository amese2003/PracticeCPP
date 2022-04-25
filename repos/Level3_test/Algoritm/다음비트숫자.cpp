#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int getNext(int n)
{
	int c = n;
	int c0 = 0;
	int c1 = 0;

	while (((c & 1) == 0) && (c != 0))
	{
		c0++;
		c >>= 1;
	}

	while ((c & 1) == 1)
	{
		c1++;
		c >>= 1;
	}

	if ((c0 + c1 == 31) || (c0 + c1 == 0))
		return -1;

	int p = c0 + c1;

	return n - (1 << c1) - (1 << (c0 - 1)) + 1;

}