#pragma once
#include <mutex>

template<typename T>
class LockFreeStack
{
	struct Node;

	struct CountedNodePtr
	{
		int32 externalCount = 0;
		Node* ptr = nullptr;
	};

	struct Node
	{
		Node(const T& value) : data(make_shared<T>(value)) {}

		shared_ptr<T> data;
		atomic<int32> internalCount = 0;
		CountedNodePtr next;
	};

public:
	void Push(const T& value)
	{
		CountedNodePtr node;
		node.ptr = new Node(value);
		node.externalCount = 1;
		node.ptr->next = _head;

		while (_head.compare_exchange_weak(node.ptr->next, node) == false)
		{

		}
	}

	shared_ptr<T> TryPop()
	{
		CountedNodePtr oldHead = _head;

		while (true)
		{
			IncreaseHeadCount(oldHead);

			Node* ptr = oldHead.ptr;

			if (ptr == nullptr)
				return shared_ptr<T>();

			if (_head.compare_exchange_strong(oldHead, ptr->next))
			{
				shared_ptr<T> res;
				res.swap(ptr->data);

				const int32 countincrease = oldHead.externalCount - 2;
				if (ptr->internalCount.fetch_add(countincrease) == -countincrease)
					delete ptr;

				return res;
			}
			else if (ptr->internalCount.fetch_sub(1) == 1)
			{
				delete ptr;
			}

		}

	}

private:
	void IncreaseHeadCount(CountedNodePtr& oldCounter)
	{
		while (true)
		{
			CountedNodePtr newCounter = oldCounter;
			newCounter.externalCount++;

			if (_head.compare_exchange_strong(oldCounter, newCounter))
			{
				oldCounter.externalCount = newCounter.externalCount;
				break;
			}
		}
	}


private:
	atomic<CountedNodePtr> _head;
};

