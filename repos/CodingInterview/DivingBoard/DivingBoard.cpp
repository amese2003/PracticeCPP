#include <iostream>
#include <vector>
#include <string>
#include <hash_set>

using namespace std;

hash_set<int> AllLength(int k, int shorter, int longer) {
    hash_set<int> len;
    GetAllLength(k, 0, shorter, longer, len);
    return len;
}
void GetAllLength(int k, int total, int shorter, int longer, hash_set<int>& length) {
    if (k == 0) {
        length.insert(total);
        return;
    }

    GetAllLength(k - 1, total + shorter, shorter, longer, length);
    GetAllLength(k - 1, total + longer, shorter, longer, length);
}


int main()
{
    std::cout << "Hello World!\n";
}