#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <future>
#include "LockFreeStack.h"
#include "LockFreeQueue.h"
#include "SLockFreeStack.h"
#include "ThreadManager.h"

//LockFreeQueue<int32> q;
//LockFreeStack<int32> s;
//
//void Push() {
//	while (true) {
//		int32 value = rand() & 100;
//		q.Push(value);
//
//		//this_thread::sleep_for(10ms);
//	}
//}
//
//void Pop() {
//	while (true) {
//		auto data = q.TryPop();
//
//		if (data != nullptr)
//			cout << (*data) << endl;
//	}
//}
//
//int main()
//{
//	/*shared_ptr<int32> ptr;
//	bool value = atomic_is_lock_free(&ptr);*/
//
//	thread t1(Push);
//	thread t2(Pop);
//	//thread t3(Pop);
//
//	t1.join();
//	t2.join();
//	//t3.join();
//}

DECLSPEC_ALIGN(16)
class Data
{
public:
	SListEntry _entry;
	int64 _rand = rand() % 1000;
};

SListHeader* GHeader;

int main()
{
	GHeader = new SListHeader();
	ASSERT_CRASH(((uint64)GHeader % 16) == 0);
	InitializeHead(GHeader);

	for (int32 i = 0; i < 3; i++)
	{
		GThreadManager->Launch([]() {
			while (true)
			{
				Data* data = new Data();
				ASSERT_CRASH(((uint64)data % 16) == 0);
				PushEntrySList(GHeader, (SListEntry*)data);
				this_thread::sleep_for(1ms);
			}
			});
	}

	for (int32 i = 0; i < 3; i++)
	{
		GThreadManager->Launch([]() {
			while (true)
			{
				Data* pop = nullptr;
				pop = (Data*)PopEntrySList(GHeader);

				if (pop)
				{
					cout << pop->_rand << endl;
					delete pop;
				}
				else
				{
					cout << "NONE" << endl;
				}
			}
			});
	}

	GThreadManager->Join();
}
