#include <iostream>
#include <vector>

using namespace std;

const int cow_Count = 5;
const int room_Count = 5;

const int MAX = 201;

vector<int> room_want[MAX];
int room_Residence[MAX];
bool room_Matched[MAX];

bool TryMatch(int cowNum) {
    for (vector<int>::size_type i = 0; i < room_want[cowNum].size(); i++) {
        int favorit = room_want[cowNum][i];

        if (room_Matched[favorit])
            continue;
        
        room_Matched[favorit] = true;

        if (room_Residence[favorit] == 0 || TryMatch(room_Residence[favorit])) {
            
            room_Residence[favorit] = cowNum;
            return true;
        }
    }

    return false;
}


int main()
{
    int answer = 0;

    room_want[1].push_back(2);
    room_want[1].push_back(5);

    room_want[2].push_back(2);
    room_want[2].push_back(3);
    room_want[2].push_back(4);

    room_want[3].push_back(1);
    room_want[3].push_back(5);

    room_want[4].push_back(1);
    room_want[4].push_back(2);
    room_want[4].push_back(5);

    room_want[5].push_back(2);

    for (int i = 1; i <= cow_Count; i++) {
        fill(room_Matched, room_Matched + MAX, false);

        if (TryMatch(i))
            answer++;
    }

    std::cout << "Hello World!\n";
}