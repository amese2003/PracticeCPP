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

	// 배열
	const int MAX_SIZE = 10;
	int arr[MAX_SIZE] = {};

	for (int i = 0; i < MAX_SIZE; i++)
		arr[i] = i;

	for (int i = 0; i < MAX_SIZE; i++)
		cout << arr[i] << endl;

	// 동적 벼열
	// 매우 매우 중요한 개념 -> 어떤 마법을 부렸길래 배열을 '유동적으로' 사용한 것인가?

	// 1) (여유분을 두고) 메모리를 할당
	// 2) 여유분깢 꽉 찼으면, 메모리를 증설한다

	// Q1) 여유분은 얼만큼이 적당할까?
	// Q2) 증설을 얼만큼 해야 할까?
	// Q3) 기존 데이터를 어떻게 처리할까?

	// [ 1 2 3 4 5 ]
	// [                        ]


	vector<int> v;

	cout << v.size() << " " << v.capacity() << endl;
	//v.resize(1000);
	// size (실제 사용 데이터 개수)
	// 1 2 3 4 5 6 7


	//v.reserve(1000);
	// capacity (여유분을 포함한 용량 개수)
	//
	// 1 2 3 4 6 9 13 19 28 42 63

	for (int i = 0; i < 1000; i++) {
		v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.clear();
	cout << v.size() << " " << v.capacity() << endl;

	return 0;
}
