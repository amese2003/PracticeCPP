#include <iostream>
#include <vector>

using namespace std;

__int64 init(vector<__int64>& arr, vector<__int64>& tree, int nodeNum, int leafStart, int leafEnd) {
    if (leafStart == leafEnd)
        return tree[nodeNum] == tree[leafStart];

    int mid = (leafStart + leafEnd) / 2;

    return init(arr, tree, nodeNum * 2, leafStart, mid) + init(arr, tree, nodeNum * 2 + 1, mid + 1, leafEnd);
}

__int64 sum(vector<__int64>& tree, int nodeNum, int start, int end, int leafLeft, int leafRight) {
    if (leafLeft > end || leafRight < start) return 0;

    if (start <= leafLeft && end <= leafRight) {
        return tree[nodeNum];
    }
    int mid = (start + end) / 2;
    return sum(tree, nodeNum * 2, start, mid, leafLeft, leafRight) + sum(tree, nodeNum * 2 + 1, mid + 1, end, leafLeft, leafRight);
}

void Update(vector<__int64>& tree, int nodeNum, int start, int end, int index, int delta) {
    if (index < start || index > end) return;
    tree[nodeNum] = tree[nodeNum] + delta;

    int mid = (start + end) / 2;

    if (start != end) {
        Update(tree, nodeNum * 2, start, mid, index, delta);
        Update(tree, nodeNum * 2 + 1, mid + 1, end, index, delta);
    }
}

int main()
{
    const int N = 16;

    vector<__int64> arr{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    int height = (int)ceil(log2(N));
    int tree_size = (1 << (height + 1));
    vector<__int64> tree(tree_size);

    init(arr, tree, 1, 0, arr.size() - 1);

    // case Update
    {
        long long newValue = 12;
        int pos = 2;

        pos--;
        long long delta = newValue - arr[pos];
        Update(tree, 0, 0, N - 1, pos, delta);
    }

    // case 구간 합
    {
        int left = 0;
        int right = 3;
        int value = sum(tree, 0, 0, N - 1, left - 1, right - 1);        
    }



    std::cout << "Hello World!\n";
}