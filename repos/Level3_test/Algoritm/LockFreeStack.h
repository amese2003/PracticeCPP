#pragma once
#include <mutex>

template<typename T>
class LockFreeStack
{
	struct Node
	{
		Node(const T& value) : data(value) {};

		T data;
		Node* next;
	};

public:
	void Push(const T& value)
	{
		Node* node = new Node(value);
		node->Next = _head;
		
		while (_head.compare_exchange_weak(node->next, node) == false)
		{

		}
	}

	bool TryPop(T& value)
	{
		Node* oldHead = _head;

		while (oldHead && _head.compare_exchange_weak(oldHead, oldHead->next) == false)
		{

		}

		if (oldHead == nullptr)
			return false;

		value = oldHead->data;

		return true;

	}

private:
	atomic<Node*> _head;
};

