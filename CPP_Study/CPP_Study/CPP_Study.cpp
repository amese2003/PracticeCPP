#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : 중괄호 초기화

class Knight {
public:
	Knight() {

	}

	Knight(initializer_list<int> li) {
		cout << "Knight(initializer_list)" << endl;
	}
};

int main()
{
	// 중괄호 초기화 { }
	int a = 0;
	int b{ 0 };
	int c{ 0 };

	Knight k1;
	Knight k2 = k1; // 복사 생성자 (대입 연산자가 아님!)

	Knight k3{ k2 };

	vector<int> v1;

	int arr[] = { 1,2,3,4 };

	

	// 중괄호 초기화
	// 1) vector 등 container과 잘 어울림
	vector<int> v3{ 1,2,3,4 };

	// 2) 축소 변환 방지
	int x = 0;
	double y{ x };

	// 3) Bonus
	Knight k4{};

	// 괄호 초기화 () 기본으로 간다
	// - 전통적인 c++ (거부감이 없다)
	// - vector등 특이한 케이스에 대해서만 {} 사용

	// 중괄호 초기화 {} 기본으로 간다
	// - 초기화 문법의 일치화
	// - 축소 변환 방지


	return 0;
}
