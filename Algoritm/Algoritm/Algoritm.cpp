#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include "BinarySearchTree.h"
#include <thread>

using namespace std;


// map : Red-Black Tree
// - 추가 / 탐색 / 삭제 O(logN)

// unordered_map
// - 추가 / 탐색 / 삭제 O(1)

// 메모리를 내주고 속도를 취한다

void TestTable()
{
	struct User
	{
		int userid = 0;
		string username;
	};

	vector<User> users;
	users.resize(1000);

	users[777] = User{ 777, "test" };
	string name = users[777].username;

	cout << name << endl;

	// 살을 내주는 것도 정도것 해야지...

}

void TestHash()
{
	struct User
	{
		int userid = 0; // 1 ~ int64_maxs
		string username;
	};

	vector<User> users;
	users.resize(1000);

	const int userid = 123456789;
	int key = (userid % 1000);


	users[key] = User{ userid, "test" };
	

	User& user = users[key];

	if (user.userid == userid)
	{
		string name = user.username;
		cout << name << endl;
	}

	// 충돌문제

	// 선형조사법 (linear probing)
	// 	   hash(key) + 1 -> hash(key) + 2 -> ......
	// 이차 조사법
	//     hash(key) + 1 ^ 2 -> hash(key) + 2 ^ 2 -> ....

	// 체이닝

}

void TestHashTableChaining()
{
	struct User
	{
		int userid = 0; // 1 ~ int64_maxs
		string username;
	};
	vector<vector<User>> users;
	users.resize(1000);


	const int userid = 123456789;
	int key = (userid % 1000);


	users[key].push_back(User{ userid, "test" });

	vector<User>& bucket = users[key];

	for (User& user : bucket)
	{
		if (user.userid == userid)
		{
			string name = user.username;
			cout << name << endl;
		}
	}

}

int main()
{
	TestHashTableChaining();
	return 0;
}
