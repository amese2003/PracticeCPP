//#include <string.h>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include <iostream>
//
//using namespace std;
//
//class Trie {
//private:
//	Trie* next[26];
//	bool finish = false;
//	unordered_map<int, int> length_count;
//
//public:
//	Trie()
//	{
//		memset(next, 0, sizeof(next));
//	}
//
//	~Trie()
//	{
//		for (int i = 0; i < 26; i++)
//			if (next[i])
//				delete next[i];
//	}
//
//	void insert(const string& str)
//	{
//		Trie* curr = this;
//
//		for (char c : str) {
//			curr->length_count[str.size()]++;
//
//			if (curr->next[c - 'a'] == nullptr) {
//				curr->next[c - 'a'] = new Trie();
//			}
//
//			curr = curr->next[c - 'a'];
//		}
//
//		curr->finish = true;
//	}
//
//	bool contain(string str) {
//		Trie* curr = this;
//		int count = 0;
//
//		for (char c : str) {
//			if (curr->next[c - 'a'] == nullptr) {
//				return false;
//			}
//			curr = curr->next[c - 'a'];
//		}
//
//		return true;
//	}
//
//	int find(string str, int size) {
//		Trie* curr = this;
//
//		for (char c : str) {
//			if (c == '?')
//				return curr->length_count[str.size()];
//
//			if (curr->next[c - 'a'] == nullptr) {
//				return 0;
//			}
//
//			curr = curr->next[c - 'a'];
//		}
//
//		return curr->length_count[str.size()];
//	}
//};
//
//
//
//vector<int> solution(vector<string> words, vector<string> queries) {
//	vector<int> answer(queries.size(), 0);
//
//	Trie root;
//	Trie root_reverse;
//
//	for (string word : words) {
//		root.insert(word);
//		reverse(word.begin(), word.end());
//		root_reverse.insert(word);
//	}
//
//	for (int i = 0; i < queries.size(); i++) {
//		int num = 0;
//
//		if (queries[i].front() == '?') {
//			reverse(queries[i].begin(), queries[i].end());
//			num = root_reverse.find(queries[i], queries[i].size());
//		}
//		else
//			num = root.find(queries[i], queries[i].size());
//
//		answer[i] = num;
//	}
//
//	return answer;
//}