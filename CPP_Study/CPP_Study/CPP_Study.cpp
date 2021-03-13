#include <iostream>
#include <vector>
using namespace std;

// 오늘의 주제 : vector

int main()
{
	// STL (Standard Template Library)
	// 프로그래밍 할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structrue)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	// 반복자 (iterator) : 포인터와 유사한 개념. 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능
	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		v[i] = i;
	}

	/*vector<int>::iterator it;
	int* ptr;

	it = v.begin();
	ptr = &v[0];

	cout << (*it) << endl;
	cout << (*ptr) << endl;*/

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();

	// 더 복잡해보이는데?
	// 다른 컨테이너는 v[i] 와 같은 인덱스 접근이 안 될 수도 있음
	// iterator는 vector뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it) << endl;
	}

	vector<int>::const_iterator cit1 = v.cbegin();

	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
		cout << (*it) << endl;
	}

	// - 중간 삽입/삭제 (매우 비효율)
	// - 처음/끝 삽입/삭제 (비효율 / good)
	// - 임의 접근 (Random Access)

	// vector = 동적 배열 = 동적으로 커지는 배열 = 배열
	// 원소가 하나의 메모리 블록에 연속하게 저장되는 특징

	// [                        ]
	// {0}{1}{2}{3}{4} [] []    ]
	//v.insert(v.begin() + 2, 5);

	// 쭉 스캔을 하면서 3이라는 데이터가 있으면 일괄 삭제하고싶다?

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		int data = *it;

	}
	


	return 0;
}
