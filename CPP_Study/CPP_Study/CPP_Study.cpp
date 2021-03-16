#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : 연습문제

class Knight {

};

int main()
{

	auto a = 3;
	auto b = 3.14f;
	auto c = 1.23;
	auto d = Knight();
	auto e = "Nero";

	// auto는 일종의 조커카드
	// 형식 연역 (type deduction)
	// -> 말이 되게 잘 맞춰봐라. (추론)
	// 추론 규칙은 생각보다 복잡해질 수 있다.

	auto f = &d;
	const auto test1 = b;
	auto* test2 = e;

	// 주의!
	// 기본 auto는 const, & 무시!!!!!!!!!!!

	int& reference = a;
	const int cst = a;
	
	auto test1 = reference;
	auto test2 = cst;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		int& data = v[i];

		data = 100;
	}

	// 아무튼 이제 기존의 타입은 잊어버리고 auto만 쓴다?
	// NO!
	// -> 타이핑이 길어지는 경우 OK
	// -> 가독성을 위해 일반적으로는 놔두는게 좋음
	
	return 0;
}
