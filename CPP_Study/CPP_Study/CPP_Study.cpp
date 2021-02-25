#include <iostream>

using namespace std;

// 오늘의 주제 : 다중 포인터

void SetMessage(const char* a) {
	a = "bye";
}

void SetMessage(const char** a) {
	*a = "Bye";
}


void SetMessage2(const char*& a) {
	a = "Wow";
}

int main() {	

	int a = 0;

	const char* msg = "Hello";
	SetMessage(msg);

	//cout << msg << endl; // Hello? bye?

	// 주소2 [] << 1바이트 바구니
	// 주소1 [ 주소2  ] << 8바이트
	// pptr[ 주소1 ] << 8바이트
	const char** pptr = &msg;


	// [매개변수][ret][지역변수(msg(Hello 주소))][매개변수(a(&msg))][ret][지역변수]
	SetMessage(&msg);
	cout << msg << endl;

	// 다중 포인터 : 혼동스럽다?
	// 그냥 양파까기라고 생각하면 된다.
	SetMessage2(msg);
	cout << msg << endl;

	return 0;
}