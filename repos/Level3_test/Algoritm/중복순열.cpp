#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void PrintPerms(unordered_map<char, int> charmap, string prifix, int remain, vector<string>& result)
{
	if (remain == 0)
	{
		result.push_back(prifix);
		return;
	}

	for (auto data : charmap)
	{
		char c = data.first;
		int count = data.second;

		if (count > 0)
		{
			charmap[c] = count - 1;
			PrintPerms(charmap, prifix + c, remain - 1, result);
		}

	}

}

unordered_map<char, int> BuildFreqTable(string s)
{
	unordered_map<char, int> charmap;

	for (char c : s) {
		charmap[c] = charmap[c] + 1;
	}

	return charmap;
}

vector<string> PrintPerms(string s)
{
	vector<string> result;
	unordered_map<char, int> charmap = BuildFreqTable(s);

	string prifix = "";
	int charsize = s.length();
	vector<string> res;

	PrintPerms(charmap, prifix, charsize, res);
}

