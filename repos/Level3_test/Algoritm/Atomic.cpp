//#include <iostream>
//#include <thread>
//#include <atomic>
//
//using namespace std;
//
//// atomic atom(¿øÀÚ)
//atomic<int> sum = 0;
//
//void Add()
//{
//	for (int i = 0; i < 1'000'000; i++) {
//
//		sum.fetch_add(1);
//		//sum++;
//		/*int32 eax = sum;
//		eax = eax + 1;
//		sum = eax;*/
//	}
//}
//
//void Sub()
//{
//	for (int i = 0; i < 1'000'000; i++) {
//
//
//		sum.fetch_add(-1);
//
//		//int ebx = sum;
//		//ebx = ebx + 1;
//		//sum = ebx;
//
//	}
//}
//
//int atomicExample()
//{
//	Add();
//	Sub();
//	cout << sum << endl;
//
//	std::thread t1(Add);
//	std::thread t2(Sub);
//
//	t1.join();
//	t2.join();
//	cout << sum << endl;
//
//}
//
