#include <iostream>
#include <iomanip>
using namespace std;
#include "Test1.h"
#include "Test2.h"

// 오늘의 주제 : 파일 분할 관리

#ifndef  _TEST1_H__
#define _TEST1_H__

struct StatInfo {
	int hp;
	int attack;
	int defence;
};

void Test_1();

void Test_2();

void Test_3();

#endif // ! _TEST1_H__


int main() 
{	
	Test_2();

	return 0;
}