#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

void CheckPrime(vector<bool>& isPrime, int num) {
    for (int i = 2; i < sqrt(num); i++) {

        if (isPrime[i] == false)
            continue;


        for (int j = i + i; j <= num; j += i) {
            isPrime[j] = false;
        }
    }
}


void MakePrime(vector<int>& nums, const vector<bool>& isPrime, int& ans, int L, int index, int sum) {
    if (L == 3) {
        if (isPrime[sum])
            ans++;


        return;
    }
    for (int i = index; i < nums.size(); i++) {
        MakePrime(nums, isPrime, ans, L + 1, i + 1, sum + nums[i]);
    }
}

int MakePrimeSol(vector<int> nums) {
    int answer = 0;
    int max = 0;

    for (int i = 0; i < nums.size(); i++)
        max += nums[i];


    vector<bool> isPrime(max + 1, true);
    CheckPrime(isPrime, max + 1);

    MakePrime(nums, isPrime, answer, 0, 0, 0);

    cout << "Hello Cpp" << endl;
    return answer;
}

//void main() {
//    vector<int> nums{ 1,2,3,4 };
//    MakePrimeSol(nums);
//}