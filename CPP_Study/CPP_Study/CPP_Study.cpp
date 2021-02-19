#include <iostream>

using namespace std;

// 오늘의 주제 : 문자와 문자열
// bool은 그냥 정수지만, 참/거짓을 나타내기 위해 사용
// 사실 char도 마찬가지. 그냥 정수지만 '문자' 의미를 나타내기 위해 사용

// char : 알파벳 / 숫자 문자
// wchar_t : 유니코드 문자를 나타낸다

// unicode
// 복습
// UTF8
// - 알파벳, 숫자 1바이트 (ASCII 동일)
// - 유렵 지역의 문자는 2바이트
// - 한글, 한자 등 3바이트

// UTF16
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트
// - 매~~~우 예외적인 고대 문자만 4바이트 (사실상 무시해도 됨)

// wchar_t test = L'안';
wchar_t test = 0xc548;
wchar_t wch = '\'';



// Esacape Sequence
// 표기하기 애매한 애들을 표현
// \0 = 아스키코드 0 = NULL
// \t = 아스키코드 9 = Tab
// \n = 아스키코드 10 = LineFeed (한줄 아래로)
// \r = 아스키코드 13 = CarriageReturn (커서 <<)
// \'

// 문자열
// 문자들이 열을 지어서 모여 있는 것 (문자 배열?)
// 정수 (1~8바이트) 고정 길이로
// Ex) Hello World
char str[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
char str2[] = "Hello World";

int main()
{
    std::cout << "Hello World!\n";
    

    cout << str << endl;

    wcout.imbue(locale("kor"));
    wcout << wch << endl;


    return 0;
}