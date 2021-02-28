#include <iostream>

using namespace std;

// 오늘의 주제 : 연습문제

int StrLen(const char* str) {
	int count = 0;

	while (str[count] != '\0') 
		count++;	

	return count;
}

void StrCpy(const char* str1, char* str2) {

	int count = StrLen(str1);

	for (int i = 0; i <= count; i++) {
		str2[i] = str1[i];
	}
}

char* StrCat(char* dest, char* src) {

	/*int destCount = StrLen(dest);
	int srcCount = StrLen(src);

	char* pos = dest + destCount;

	for (int i = 0; i <=  srcCount; i++) {
		*(pos + i) = src[i];
	}*/

	char* ret = dest;

	while (*dest != '\0')
		dest++;

	while (*src) 
		*dest++ = *src++;
	
	*dest = '\0';

	return dest;
}

int StrCmp(char* dest, char* src) {

	int destCount = StrLen(dest);

	for (int i = 0; i < destCount; i++) {
		if (dest[i] < src[i])
			return -1;
		else
			return 1;
	}

	return 0;
}

void ReverseStr(char* src) {

	char temp = 0;


	int total = StrLen(src);

	for (int i = 0; i < total / 2; i++) {

		temp = src[i];
		src[i] = src[total - i - 1];
		src[total - i - 1] = temp;
	}



	// asdfg
	// asdf


}

int main() 
{	
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE];

	int leng = StrLen(a);
	cout << leng << endl;

	StrCpy(a, b);
	cout << b << endl;


	StrCat(b, a);
	cout << a << endl;

	char c[BUF_SIZE] = "Hellq";

	int cmp = StrCmp(a, c);

	cout << cmp << endl;
	
	ReverseStr(c);
	cout << c << endl;

	return 0;
}