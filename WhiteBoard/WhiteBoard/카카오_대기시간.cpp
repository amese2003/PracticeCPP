#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int get_Time(string str_time) {
    string str_hour = str_time.substr(0, 2);
    string str_minute = str_time.substr(3, 2);

    int hour = stoi(str_hour) * 60;
    int minute = stoi(str_minute);

    return hour + minute;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> mate_arrive_time(timetable.size(), 0);

    for (int i = 0; i < timetable.size(); i++)
        mate_arrive_time[i] = get_Time(timetable[i]);

    sort(mate_arrive_time.begin(), mate_arrive_time.end());
    int bus_time = 540;

    int arrive_crew = 0;
    int crew_time = 0;

    for (int i = 0; i < n; i++) {
        int bus_people = 0;

        for (int j = arrive_crew; j < mate_arrive_time.size(); j++) {
            if (mate_arrive_time[j] <= bus_time) {
                arrive_crew++;
                bus_people++;

                if (bus_people == m)
                    break;
            }
        }

        if (i + 1 == n) {
            if (bus_people == m)
                crew_time = mate_arrive_time[arrive_crew - 1] - 1;
            else
                crew_time = bus_time;
        }

        bus_time += t;
        if (bus_time >= (60 * 24)) break;
    }

    string arrive_str = "";

    int hour = crew_time / 60;
    if (hour < 10)
        arrive_str += "0" + to_string(hour);
    else
        arrive_str += to_string(hour);

    arrive_str += ":";
    int min = crew_time % 60;
    if (min < 10)
        arrive_str += "0" + to_string(min);
    else
        arrive_str += to_string(min);


    return arrive_str;
}