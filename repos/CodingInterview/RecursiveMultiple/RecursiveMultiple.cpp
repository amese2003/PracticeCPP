#include <iostream>
#include <vector>

using namespace std;

int productMultiple(int large, int small) {
    if (small == 0) return 0;
    else if (small == 1) return large;

    int s = small >> 1;
    int halfProd = productMultiple(large, s);

    if (small % 2 == 0)
        return halfProd + halfProd;
    else
        return halfProd + halfProd + large;
}


int minProducet(int a, int b) {
    int large = (a < b) ? b : a;
    int small = (a < b) ? a : b;

    return productMultiple(large, small);
}

int main()
{
    int temp = minProducet(8, 7);

    cout << temp << endl;
    std::cout << "Hello World!\n";
}