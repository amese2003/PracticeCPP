#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

using namespace std;

// 오늘의 주제 : 연습문제
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++) {
		int num = rand() % 100;
		v.push_back(num);
	}

	// Q1) number라는 숫자가 벡터에 체크하는 기능 (bool? 첫등장 iterator?)
	{
		int number = 50;

		bool found = false;
		vector<int>::iterator itFind;

		for (int i = 0; i < v.size(); i++) {
			int data = v[i];

			if (data == number) {
				found = true;
				itFind = v.begin() + i;
				break;
			}
		}
		
		//it = v.begin();
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			if ((*it) == number) {
				found = true;
				itFind = it;
				break;
			}
		}

		int b = 3;
	}

	// Q2) 11로 나뉘는 숫자가 벡터에 있는지?
	{
		bool found = false;
		vector<int>::iterator itFind;

		for (int i = 0; i < v.size(); i++) {
			int data = v[i];

			if (data % 11 == 0) {
				found = true;
				itFind = v.begin() + i;
				break;
			}
		}

		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			if ((*it) % 11 == 0) {
				found = true;
				itFind = it;
				break;
			}
		}
	}

	// Q3) 홀수인 숫자의 개수는? (count)
	{
		int count = 0;
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			if ((*it) % 2 == 1) {
				count++;
				break;
			}
		}
	}

	// Q4) 벡터에 들어가 있는 모든 숫자에 3을 곱해주세요!
	{
		/*for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			*it = (*it) * 3;
		}*/

		for (unsigned int i = 0; i < v.size(); i++) {
			v[i] *= 3;
		}
	}


	
	
	return 0;
}
