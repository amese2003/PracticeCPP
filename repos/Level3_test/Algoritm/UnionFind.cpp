//#include <iostream>
//#include <string>
//#include <queue>
//#include <stack>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
//
//using namespace std;
//
//int GetParent(vector<int>& parent, int n) {
//	if (parent[n] == n) return n;
//	return parent[n] = GetParent(parent, parent[n]);
//}
//
//void UnionParent(vector<int>& parent, int n, int m) {
//	int N = GetParent(parent, n);
//	int M = GetParent(parent, m);
//	if (N < M)
//		parent[M] = N;
//	else
//		parent[N] = M;
//}
//
//bool SameParent(vector<int>& parent, int n, int m) {
//	int N = GetParent(parent, n);
//	int M = GetParent(parent, m);
//	if (N == M)
//		return true;
//	else
//		return false;
//}
//
//int UseFindUnion() {
//
//	vector<pair<int, int>> pairFriend;
//
//	pairFriend.push_back({ 9,7 });
//	pairFriend.push_back({ 1,2 });
//	pairFriend.push_back({ 2,3 });
//	pairFriend.push_back({ 4,3 });
//	pairFriend.push_back({ 1,5 });
//	pairFriend.push_back({ 6,7 });
//	pairFriend.push_back({ 7,8 });
//	pairFriend.push_back({ 8,9 });
//	pairFriend.push_back({ 3,8 });
//
//	int maxSum = 0;
//
//	for (int i = 0; i < pairFriend.size(); i++) {
//		maxSum = max(maxSum, max(pairFriend[i].first, pairFriend[i].second));
//	}
//
//	vector<int> friends(maxSum + 1, 0);
//
//	for (int i = 0; i < friends.size(); i++)
//		friends[i] = i;
//
//	for (int i = 0; i < pairFriend.size(); i++) {
//		UnionParent(friends, pairFriend[i].first, pairFriend[i].second);
//	}
//
//	int parent = friends[1];
//	for (int i = 1; i <= friends.size(); i++) {
//		if (parent != friends[i]) {
//			cout << "¾Æ´Ï´Ù!" << endl;
//			break;
//		}
//
//	}
//
//
//	return 0;
//}
//
