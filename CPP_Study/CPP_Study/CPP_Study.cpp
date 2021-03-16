#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

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

		itFind = find(v.begin(), v.end(), number);

		if (itFind == v.end()) {
			cout << "못찾음" << endl;
		}
		else {
			cout << "찾음" << endl;
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

		struct CanDivideBy11 {
			bool operator() (int n) {
				return (n % 11 == 0);
			}
		};		

		itFind = find_if(v.begin(), v.end(), CanDivideBy11());
		//itFind = find_if(v.begin(), v.end(), [](int n) {return n % 11 == 0; });

		if (itFind == v.end()) {
			cout << "못찾음" << endl;
		}
		else {
			cout << "찾음" << endl;
		}
	}

	// Q3) 홀수인 숫자의 개수는? (count)
	{
		vector<int>::iterator itFind;
		int count = 0;
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			if ((*it) % 2 == 1) {
				count++;
				break;
			}
		}

		struct IsOdd {
			bool operator()(int n) {
				return (n % 2) != 0;
			}
		};

		int n = std::count_if(v.begin(), v.end(), IsOdd());

		// 모든 데이터가 홀수?
		bool b1 = std::all_of(v.begin(), v.end(), IsOdd());
		// 홀수인 데이터가 적어도 하나라도 있나?
		bool b2 = std::any_of(v.begin(), v.end(), IsOdd());
		// 모든 데이터가 홀수가 아닌가?
		bool b3 = std::none_of(v.begin(), v.end(), IsOdd());
		
	}

	// Q4) 벡터에 들어가 있는 모든 숫자에 3을 곱해주세요!
	{
		/*for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			*it = (*it) * 3;
		}*/

		for (unsigned int i = 0; i < v.size(); i++) {
			v[i] *= 3;
		}

		struct MultiplyBy3 {
			void operator()(int& n) {
				n = n * 3;
			}
		};



		std::for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// 홀수인 데이터를 일괄 삭제
	{
		vector<int>::iterator itFind;

		v.clear();

		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);

		struct IsOdd {
			bool operator()(int n) {
				return (n % 2) != 0;
			}
		};

		//std::remove(v.begin(), v.end(), 4);

		itFind = std::remove_if(v.begin(), v.end(), IsOdd());
		v.erase(itFind, v.end());

		int a = 3;
	}	
	
	return 0;
}
