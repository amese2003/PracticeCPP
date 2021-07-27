#include <string>
#include <vector>

using namespace std;

string MiddleChar(string s) {
    string answer = "";
    int length = s.size();
    int temp = length % 2;

    if (temp == 0)
    {
        answer.push_back(s[(length / 2) - 1]);
        answer.push_back(s[(length / 2)]);
    }
    else
        answer.push_back(s[length / 2]);



    return answer;
}