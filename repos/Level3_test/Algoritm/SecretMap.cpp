#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> SecretMap(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> temp;
    string saving = "";


    for (int i = 0; i < n; i++)
    {
        temp.push_back(arr1[i] | arr2[i]);
        cout << temp[i] << endl;

        while (temp[i] != 0)
        {
            if (temp[i] % 2 == 1)
                saving.insert(0, "#");
            else
                saving.insert(0, " ");

            temp[i] /= 2;
        }

        while (saving.length() != n)
        {
            saving.insert(0, " ");
        }

        answer.push_back(saving);
        saving.clear();

    }


    return answer;
}