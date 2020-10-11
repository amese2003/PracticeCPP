// TempBridge.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int size = stones.size();
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());

    while (left <= right) {
        int mid = (left + right) / 2;
        int count = 0;

        bool check = false;

        for (int i = 0; i < size; i++) {
            if (stones[i] - mid <= 0)
                count++;
            else
                count = 0;

            if (count >= k) {
                check = true;
                break;
            }
        }

        if (check)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

int main()
{
    int temp = solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3);
    std::cout << "Hello World!\n";
}