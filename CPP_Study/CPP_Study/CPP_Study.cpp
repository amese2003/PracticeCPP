#include <iostream>
using namespace std;

#include "Player.h"

// 오늘의 주제 : 전방선언



int main() 
{	
	//Player는 몇바이트?
	Player p1; // stack

	Player* p2 = new Player(); // heap

	return 0;
}