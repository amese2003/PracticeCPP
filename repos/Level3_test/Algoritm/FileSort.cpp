#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

char makeLower(char c)
{
    if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
    return c;
}
int findNumIdx(const string& str)
{
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            break;
    }
    return i;
}
int getNumber(string str)
{
    return std::stoi(str.substr(findNumIdx(str)));
}
string getHeader(string str)
{
    string rtn = str.substr(0, findNumIdx(str));

    std::transform(rtn.begin(), rtn.end(), rtn.begin(), makeLower);

    return rtn;
}

bool numComp(string str1, string str2) { return getNumber(str1) < getNumber(str2); }
bool headComp(string str1, string str2) { return getHeader(str1).compare(getHeader(str2)) < 0; }

vector<string> solution(vector<string> files)
{
    std::stable_sort(files.begin(), files.end(), numComp);

    std::stable_sort(files.begin(), files.end(), headComp);

    return files;
}


int FileSort()
{

    vector<string> ans = solution({ "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" });

    cout << ans[0] << endl;

    return 0;
}