#include <iostream>
#include <string>


using namespace std;

int countOf(string pattern, char c)
{
    int count = 0;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (pattern[i] == c)
            count++;
    }

    return count;
}

string buildFromPattern(string pattern, string main, string sub)
{
    string sb = "";
    char first = pattern[0];

    for (char c : pattern)
    {
        if (c == first)
            sb += main;
        else
            sb += sub;
    }

    return sb;
}

bool doesMatch(string pattern, string value)
{
    if (pattern.size() == 0)
        return value.size() == 0;

    char mainChar = pattern[0];
    char altChar = mainChar == 'a' ? 'b' : 'a';
    int size = value.size();

    int countOfMain = countOf(pattern, mainChar);
    int countOfAlt = pattern.size() - countOfMain;
    int firstAlt = pattern.find(altChar);
    int maxMainSize = size / countOfMain;

    for (int mainSize = 0; mainSize <= maxMainSize; mainSize++)
    {
        int remainingLength = size - mainSize * countOfMain;
        string first = value.substr(0, mainSize);

        if (countOfAlt == 0 || remainingLength % countOfAlt == 0)
        {
            int altIndex = firstAlt * mainSize;
            int altSize = countOfAlt == 0 ? 0 : remainingLength / countOfAlt;
            string second = countOfAlt == 0 ? "" : value.substr(altIndex, altSize);

            string cand = buildFromPattern(pattern, first, second);

            if (cand == value)
                return true;
        }
    }

    return false;
}



int MatchPattern()
{
    bool match = doesMatch("aabab", "catcatgocatgo");
    cout << match << endl;
    return 0;
}
