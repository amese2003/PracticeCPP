#include <iostream>
#include <vector>

using namespace std;

void quickSort(int* data, int begin, int end) {
	if (begin >= end)
		return;

	int pivot = begin;
	int front = begin + 1;
	int back = end;

	int swap;

	while (front <= back) {
		while (front <= end && data[front] <= data[pivot]) 
			front++;

		while (back > begin && data[back] >= data[pivot])
			back--;
		
		if (front > back) {
			swap = data[back];
			data[back] = data[pivot];
			data[pivot] = swap;
		}
		else {
			swap = data[front];
			data[front] = data[back];
			data[back] = swap;
		}
	}

	quickSort(data, begin, back - 1);
	quickSort(data, back + 1, end);	
}


int main() {

	int data[10] = { 1,10,5,8,6,7,2,9,4,3 };

	int num = 10;

	quickSort(data, 0, num - 1);

	for (int i = 0; i < num; i++)
		cout << data[i] << endl;


	return 0;
}