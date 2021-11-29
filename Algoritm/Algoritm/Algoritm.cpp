#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include "BinarySearchTree.h"
#include <thread>

using namespace std;

// 오늘의 주제 : 이진 탐색 트리


int main()
{
	BinarySearchTree bst;

	bst.insert(30);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.insert(10);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.insert(20);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.insert(25);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.insert(40);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.insert(50);
	bst.Print();
	this_thread::sleep_for(1s);


	bst.Print();

	return 0;
}
