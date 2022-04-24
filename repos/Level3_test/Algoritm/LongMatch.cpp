#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<char> extract(vector<char> arr, int start, int end)
{
	vector<char> subarray(end - start + 1, ' ');
	for (int i = start; i <= end; i++)
	{
		subarray[i - start] = arr[i];
	}

	return subarray;
}

vector<int> findLongestMatch(vector<int> deltas)
{
	unordered_map<int, int> charmap;
	charmap[0] = -1;

	vector<int> ret(2, 0);

	for (int i = 0; i < deltas.size(); i++)
	{
		if (charmap.find(deltas[i]) == charmap.end())
		{
			charmap[deltas[i]] = i;
		}
		else
		{
			int match = charmap[deltas[i]];
			int dist = i - match;
			int longest = ret[1] - ret[0];
			if (dist > longest)
			{
				ret[1] = i;
				ret[0] = match;
			}
		}
	}

	return ret;
}

vector<int>  computeDeltaArray(vector<char> _array)
{
	vector<int> deltas = vector<int>(_array.size(), 0);
	int delta = 0;

	for (int i = 0; i < _array.size(); i++)
	{
		if (isalpha(_array[i]))
		{
			delta++;
		}
		else if (isdigit(_array[i]))
		{
			delta--;
		}

		deltas[i] = delta;
	}

	return deltas;
}

vector<char> findLongestSubArray(vector<char> _array)
{
	vector<int> deltas = computeDeltaArray(_array);
	vector<int> match = findLongestMatch(deltas);
	return extract(_array, match[0] + 1, match[1]);
}


int LongMatch()
{
	vector<char> arr{ 'a','a','a','a','1','1','a','1','1','a','a','1','a','a','1','a','a','a','a','a' };
	vector<char> result = findLongestSubArray(arr);

	for (char c : result)
	{
		cout << c << " ";
	}

	cout << endl;

	return 0;
}
