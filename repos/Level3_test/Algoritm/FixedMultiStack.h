#pragma once
#include <iostream>
#include <memory>

class FixedMultiStack
{
public:
	FixedMultiStack(int stackSize) : _capacity(stackSize)
	{
		_numberOfStack = 3;
		_values = new int[stackSize * _numberOfStack];
		_sizes = new int[_numberOfStack];
	}

	~FixedMultiStack()
	{
		delete(_values);
		delete(_sizes);
	}
public:
	void Push(int stackNum, int value) {
		if (IsFull(stackNum))
			return;

		_sizes[stackNum]++;
		_values[IndexOfTop(stackNum)] = value;
	}

	int Pop(int stackNum)
	{
		if (IsEmpty(stackNum))
		{
			return -1;
		}

		int topIndex = IndexOfTop(stackNum);
		int value = _values[topIndex];
		_values[topIndex] = 0;
		_sizes[stackNum]--;
		return value;
	}

	bool IsEmpty(int stackNum)
	{
		return _sizes[stackNum] == 0;
	}

	bool IsFull(int stackNum)
	{
		return _sizes[stackNum] == _capacity;
	}

private:
	int IndexOfTop(int stackNum)
	{
		int offset = stackNum * _capacity;
		int size = _sizes[stackNum];
		return offset + size - 1;
	}

private:
	int _numberOfStack;
	int _capacity;
	int* _values;
	int* _sizes;
};

