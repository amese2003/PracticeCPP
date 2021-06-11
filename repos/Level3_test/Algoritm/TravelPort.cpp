#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool tryVisit(string from, vector<string>& root, vector<string>& pathFind, vector<bool>& ticketUsed, vector<vector<string>> ticket, int count) {
    pathFind.push_back(from);

    if (count == ticket.size()) {
        root = pathFind;
        return true;
    }

    for (int i = 0; i < ticket.size(); i++) {
        if (ticket[i][0] == from && !ticketUsed[i]) {
            ticketUsed[i] = true;
            bool check = tryVisit(ticket[i][1], root, pathFind, ticketUsed, ticket, count + 1);
            if (check) return true;
            ticketUsed[i] = false;
        }
    }

    pathFind.pop_back();
    return false;
}


vector<string> TravelPort(vector<vector<string>> tickets) {
    vector<bool> ticketUsed(tickets.size(), false);
    vector<string> root;
    vector<string> pathFind;
    int count = 0;

    sort(tickets.begin(), tickets.end());

    tryVisit("ICN", root, pathFind, ticketUsed, tickets, count);

    return root;
}