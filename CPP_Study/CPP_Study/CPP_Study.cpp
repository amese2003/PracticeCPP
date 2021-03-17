#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 오늘의 주제 : 전달 참조

class Knight {
public:
	Knight() { cout << "기본 생성자" << endl; }
	Knight(const Knight&) { cout << "복사 생성자" << endl; }
	Knight(Knight&&) noexcept { cout << "이동 생성자" << endl; }
};

void Test_RValueRef(Knight&& k) // 오른값 참조
{

}

void Test_Copy(Knight k) {

}

template<typename T>
void Test_ForwardingRef(T&& param) // 전달 참조
{
	Test_Copy(std::forward<T>(param));

	// 왼값 참조라면 복사
	//Test_Copy(param);

	// 오른값 참조라면 이동
	//Test_Copy(std::move(param));
}

int main()
{
	// 보편 참조 (universal reference)
	// 전달 참조 (forwarding reference) C++ 17

	// &&	&를 두 번 -> 오른값 참조
	//

	Knight k1;

	//Test_RValueRef(std::move(k1)); // rvalue_cast

	//Test_ForwardingRef(k1);
	//Test_ForwardingRef(std::move(k1));

	auto&& k2 = k1;
	auto&& k3 = std::move(k1);

	// 공통점 : 형식 영역(type deduction)이 일어날 때

	// 전달 참조를 구별하는 방법

	Knight& k4 = k1;
	Knight&& k5 = std::move(k1);

	// 오른값 : 왼값이 아니다 = 단일식에서 벗어나면 사용안됨
	// 오른값 참조 : 오른값만을 참조할수 있는 참조 타입

	//Test_RValueRef(std::move(k5));
	Test_ForwardingRef(k1);
	Test_ForwardingRef(std::move(k1));


	return 0;
}
