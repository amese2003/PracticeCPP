#pragma once
#include <mutex>

template<typename T>
class LockFreeStack
{
	struct Node
	{
		Node(const T& value) : data(value), next(nullptr) {};

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
		++_popCount;
		Node* oldHead = _head;

		while (oldHead && _head.compare_exchange_weak(oldHead, oldHead->next) == false)
		{

		}

		if (oldHead == nullptr) 
		{
			--_popCount;
			return false;
		}

		value = oldHead->data;
		TryDelete(oldHead);
		return true;
	}

	void TryDelete(Node* oldHead)
	{
		if (_popCount == 1) {
			Node* node = _pendingList.exchange(nullptr);

			if (--_popCount == 0)
			{
				DeleteNodes(node);
			}
			else if (node)
			{
				ChainPendingNodeList(node);
			}

			delete oldHead;
		}
		else
		{
			ChainPendingNode(oldHead);
			--_popCount;
		}
	}

	void ChainPendingNodeList(Node* first, Node* last)
	{
		last->next = _pendingList;

		while (_pendingList.compare_exchange_weak(last->next, first) == false)
		{
		}
	}

	void ChainPendingNodeList(Node* node)
	{
		Node* last = node;
		while (last->next)
			last = last->next;

		ChainPendingNodeList(node, last);
	}

	void ChainPendingNode(Node* node)
	{
		ChainPendingNodeList(node, node);
	}

	static void DeleteNodes(Node* node)
	{
		while (node)
		{
			Node* next = node->next;
			delete node;
			node = next;
		}
	}
private:
	atomic<Node*> _head;

	atomic<uint32> _popCount = 0;
	atomic<Node*> _pendingList;
};

