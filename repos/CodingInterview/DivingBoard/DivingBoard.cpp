#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<int> AllLength(int k, int shorter, int longer) {
    unordered_set<int> len;
    for (int nShorter = 0; nShorter <= k; nShorter++) {
        int nLonger = k - nShorter;
        int length = nShorter * shorter + nLonger * longer;
        len.insert(length);
    }
    return len;
}
//void GetAllLength(int k, int total, int shorter, int longer, hash_set<int>& length) {
//    if (k == 0) {
//        length.insert(total);
//        return;
//    }
//
//    GetAllLength(k - 1, total + shorter, shorter, longer, length);
//    GetAllLength(k - 1, total + longer, shorter, longer, length);
//}


int main()
{
    std::cout << "Hello World!\n";
}