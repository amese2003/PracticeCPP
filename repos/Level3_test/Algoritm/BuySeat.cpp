#include <vector>
#include <iostream>
#include <map>
using namespace std;

int BuySeat(vector<vector<int>> seat)
{
    int buy_failure = 0;
    int total_people = seat.size();

    using pos = pair<int, int>;
    map<pos, int> sold_seat;

    for (int i = 0; i < seat.size(); i++) {
        pos buy_pos = make_pair(seat[i][0], seat[i][1]);

        if (sold_seat[buy_pos])
            buy_failure++;
        else
            sold_seat[buy_pos]++;
    }

    return total_people - buy_failure;
}