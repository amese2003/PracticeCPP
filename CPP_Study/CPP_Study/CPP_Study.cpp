#include <iostream>
using namespace std;

// 오늘의 주제 : 템플릿 기초

// typename T를 붙이면 '조커카드' (어떤 타입도 다 넣을 수 있음)
// 근데 무조건 TYPENAME을 붙여야 하는 것은 아니다.
// template<> 안에 들어가는건 [골라줘야 하는 목록]

template<typename T, int SIZE = 10>
class RandomBox {
public:
	T GetRandomData() {
		int idx = rand() % SIZE;
		return _data[idx];
	}

public:
	T _data[10];
};

// 템플릿 특수화
template<int SIZE>
class RandomBox<double, SIZE> 
{
public:
	double GetRandomData() {
		cout << "RandomBox Double" << endl;
		int idx = rand() % SIZE;
		return _data[idx];
	}

public:
	double _data[SIZE];
};

int main()
{
	// 템플릿 : 함수나 클래스를 찍어내는 틀
	// 1) 함수 템플릿
	// 2) 클래스 템플릿
	srand(static_cast<unsigned int>(time(nullptr)));
	RandomBox<int, 10> rb1;
	for (int i = 0; i < 10; i++) {
		rb1._data[i] = i;
	}

	int value1 = rb1.GetRandomData();
	cout << value1 << endl;

	RandomBox<double, 20> rb2;
	for (int i = 0; i < 20; i++) {
		rb2._data[i] = i + 0.5;
	}
	double value2 = rb2.GetRandomData();
	cout << value2 << endl;
	

	return 0;
}
