#include <iostream>
#include <unordered_set>

using namespace std;

// 오늘의 주제 : 로또 번호 생성기

void Swap(int& a, int& b);
void Sort(int numbers[], int count);
void ChooseLotto(int numbers[]);



int main() {	

	// 1) Swap 함수 만들기

	int a = 1;
	int b = 2;

	const int count = 6;
	int numbers[count] = { 1, 42, 3, 15, 5, 6 };
	ChooseLotto(numbers);	

	return 0;
}

void Swap(int& a, int& b) {

	int temp = a;
	a = b;
	b = temp;
}

void Sort(int numbers[], int count) {
	for (int pivot = 0; pivot < count; pivot++) {
		for (int swap = 0; swap < count - 1 - pivot; swap++) {
			if (numbers[swap] > numbers[swap + 1]) {
				int temp = numbers[swap];
				numbers[swap] = numbers[swap + 1];
				numbers[swap + 1] = temp;
			}
		}
	}

	for (int i = 0; i < count; i++) {
		cout << numbers[i] << " ";
	}

	cout << "\n";

	/*cout << sizeof(numbers) << endl;
	int size = count;


	int pivot = 0;
	int start = pivot + 1;
	int end = size - 1;*/

	// 1, 42, 3, 15, 5, 6
	// 1, 6, 3, 15, 5, 42
	// 1, 5, 3, 15, 6, 42

	// 1, 5, 3  15, 6, 42
	// 1, 3, 5  6, 15, 42



	/*while (start < end) {
		if (*(numbers + start) > *(numbers + end)) {

			int temp = *(numbers + start);
			*(numbers + start) = *(numbers + end);
			*(numbers + end) = temp;

			end--;
		}

		if (*(numbers + start) < *(numbers + end)) {
			start++;
		}
	}


	if (start >= end && *(numbers + pivot) > *(numbers + start)) {
		int temp = *(numbers + pivot);
		*(numbers + pivot) = *(numbers + start);
		*(numbers + start) = temp;
	}*/
}

void ChooseLotto(int numbers[]) {
	srand((unsigned)time(0));

	int count = 0;

	unordered_set<int> lotto;

	while (count < 6) {
		int num = 1 + (rand() % 45);		

		if (lotto.find(num) == lotto.end()) {
			*(numbers + count) = num;
			lotto.insert(num);
			count++;
		}	
	}


	Sort(numbers, lotto.size());
}