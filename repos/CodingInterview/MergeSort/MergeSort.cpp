#include <iostream>
#include <vector>

using namespace std;

const int sort_size = 8;
int sorted[sort_size];

void merge(int data[], int leftpos, int middle, int rightpos) {
    int left = leftpos;
    int right = middle + 1;
    int pos = leftpos;

    while (left <= middle && right <= rightpos) {
        if (data[left] <= data[right]) {
            sorted[pos] = data[left];
            left++;
        }
        else {
            sorted[pos] = data[right];
            right++;
        }
        pos++;         
    }

    if (left > middle) {
        for (int remain = right; remain <= rightpos; remain++) {
            sorted[pos] = data[remain];
            pos++;
        }
    }
    else {
        for (int remain = left; remain <= middle; remain++) {
            sorted[pos] = data[remain];
            pos++;
        }
    }

    for (int t = leftpos; t <= rightpos; t++) 
        data[t] = sorted[t];  
}

void mergeSort(int data[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(data, left, middle);
        mergeSort(data, middle + 1, right);
        merge(data, left, middle, right);
    }
}


int main()
{
    int test[sort_size] = { 7,6,5,8,3,5,9,1 };
    mergeSort(test, 0, sort_size - 1);

    for (int i = 0; i < sort_size; i++)
        cout << sorted[i] << endl;

    std::cout << "Hello World!\n";
}