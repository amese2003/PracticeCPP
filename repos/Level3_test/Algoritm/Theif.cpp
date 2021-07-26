#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Thief(vector<int> money) {
	int answer = 0;

	vector<int> theif_money1(money.size(), 0);
	vector<int> theif_money2(money.size(), 0);

	theif_money1[0] = money[0];
	theif_money1[1] = money[0];

	theif_money2[0] = 0;
	theif_money2[1] = money[1];

	for (int i = 2; i < money.size() - 1; i++)
		theif_money1[i] = max(theif_money1[i - 1], theif_money1[i - 2] + money[i]);

	for (int i = 2; i < money.size(); i++)
		theif_money2[i] = max(theif_money2[i - 1], theif_money2[i - 2] + money[i]);


	return max(theif_money1[money.size() - 2], theif_money2[money.size() - 1]);
}