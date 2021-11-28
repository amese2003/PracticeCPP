#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include "BinarySearchTree.h"

using namespace std;

// 오늘의 주제 : 이진 탐색 트리


int main()
{
	BinarySearchTree bst;

	bst.insert(20);
	bst.insert(10);
	bst.insert(30);
	bst.insert(25);
	bst.insert(26);
	bst.insert(40);
	bst.insert(50);

	bst.Delete(20);
	bst.Delete(26);

	bst.Print();

	return 0;
}
