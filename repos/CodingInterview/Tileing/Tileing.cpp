// Tileing.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

//vector<int> tile(1001);

//1 * 2, 2 * 1 2 * n개로 채운것
//int tileCount(int n) {
//    if (n == 1) return 1;
//    if (n == 2) return 2;
//
//    if (tile[n] != 0) return tile[n];
//    return tile[n] = tileCount(n - 1) + tileCount(n - 2);
//}

//2 * 1, 2 * 2 .. 2 * n개로 채운것
//int tileCount(int n) {
//    if (n == 1) return 1;
//    if (n == 2) return 2;
//
//    if (tile[n] != 0) return tile[n];
//    return tile[n] = tileCount(n - 1) + 2 * tileCount(n - 2);
//}

// 2 * 1, 1 * 2, 1 * 1 .. 2 x n time over
//int tileCount(int n) {
//    if (n == 0) return 1;
//    if (n == 1) return 2;
//    if (n == 2) return 7;
//
//    if (tile[n] != 0) return tile[n];
//
//    int result = 2 * tileCount(n - 1) + 3 * tileCount(n - 2);
//
//    for (int i = 3; i <= n; i++) {
//        result += 2 * tileCount(n - i);
//    }
//
//    return tile[n] = result;
//}

//1 * 2, 2 * 1 .. 3 * n
//int tileCount(int n) {
//    if (n == 0) return 1;
//    if (n == 1) return 0;
//    if (n == 2) return 3;
//
//    if (tile[n] != 0) return tile[n];
//    int result = 3 * tileCount(n - 2);
//
//    for (int i = 3; i <= n; i++) 
//        if (i % 2 == 0)
//            result += 2 * tileCount(n - i);
//    
//    return tile[n] = result;
//}


// 2 * 1, 1 * 2, 1 * 1 .. 2 x n
vector<vector<int>> tile(1001, vector<int>(2, 0));

long long tile_count(int n) {
    tile[0][0] = 0;
    tile[1][0] = 2;
    tile[2][0] = 7;
    tile[2][1] = 1;

    for (int i = 3; i <= n; i++) {
        tile[i][1] = tile[i - 1][1] + tile[i - 3][0];
        tile[i][0] = tile[i - 1][0] * 2 + tile[i - 2][0] * 3 + tile[i][1] * 2;
    }
    return tile[n][0];
}



int main()
{
    std::cout << "Hello World!\n";
}