#include "pch.h"
#include "CoreGlobal.h"
#include "Memory.h"
#include "ThreadManager.h"

ThreadManager* GThreadManager = nullptr;
Memory* GMemory = nullptr;

class CoreGlobal
{
public:
	CoreGlobal()
	{
		GThreadManager = new ThreadManager();
		GMemory = new Memory();
	}

	~CoreGlobal()
	{
		delete GThreadManager;
		delete GMemory;
	}

} GCoreGlobal;