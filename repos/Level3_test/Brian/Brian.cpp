#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool checkLower(char a) {
    if (a >= 97 && a <= 122) return true;
    return false;
}

bool checkHigher(char a) {    
    if (a > 65 && a <= 90) return true;
    return false;
}

string toLower(string sentence) {
    string temp = "";

    for (int i = 0; i < sentence.length(); i++) {
        if (checkHigher(sentence[i]))
            temp += sentence[i] + 32;
        else
            temp += sentence[i];
    }

    return temp;
}

string toUpper(string sentence) {
    string temp = "";

    for (int i = 0; i < sentence.length(); i++) {
        if (checkLower(sentence[i]))
            temp += sentence[i] - 32;
        else
            temp += sentence[i];
    }
    
    return temp;
}

string solution(string sentence) {
    string answer = "";

    vector<char> ans;
    
    int secPos = 0;

    //unordered_set<char> 

    return answer;
}





int main()
{
    string input = "";

    input = "aHELLOa";
    //		input = "aHbEbLbLbOa";
    //		input = "Ab";
    //		input = "H";
    //		input = "Ha";
    //		input = "HaEaLaLaO";
    //		input = "HaEaLaLaObWORLDb";
    //		input = "SpIpGpOpNpGJqOqA";
    //		input = "AxAxAxAoBoBoB";
    //		input = "oBoBo";
    //		input = "aTAEaHbObObN";
    //		input = "AabAPPLEb";
    //		input = "aTbAbEbHbObObNa";
    //		input = "aTbAbEHbObOcNa";
    //		input = "cA";
    //		input = "AaBbAbNbAbNbAa";
    //		input = "AaBbAbNbAbNbAaTRIPcHOOOc";
    //		input = "AaBbAbNbAbNbAaTRIPcdHOOOd";
    //		input = "AaBbAbNbAbNbAaTRIPHcOcOcO";
    //		input = "AaBbAbNbAbNbAadTeReIePdHcOcO";
    //		input = "AaBbAbNbAbNbAaTeReIePHcOcO";
    //		input = "TRIP";
    //		input = "aIaAM";
    //		input = "bAaOb";
    //		input = "HaEaLaLaOWaOaRaLaD";
    //		input = "HaEaLaLObWORLDb";
    //		input = "abHELLObaWORLD";
    //		input = "SpIpGpOpNpGJqOqAB";
    //		input = "SpIpGpOpNpGJqOqAkB";
    //		input = "SpIpGpOpNpGJqOqAkBr";
    //		input = "AaA";
    //		input = "aA";
    //		input = "aAaAaAaAa";
    //		input = "AaAaAaAaA";
    //		input = "aacc";
    //input = "aAa";

    //string temp = solution(input);;

            
    
    //amp.insert(test.begin(), test.end());

    //temp[0] += 32;
    vector<bool> temp(7, false);

    fill(temp.begin(), temp.end(), true);

    vector<int> test(2, 0);
    test[0] = 1;
    test[1] = 2;

    sort(test.begin(), test.end());

    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
