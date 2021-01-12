#include <iostream>

#pragma once
class LocationPair {
public:
    int location1, location2;

    LocationPair(int _loc1, int _loc2) {
        location1 = _loc1;
        location2 = _loc2;
    }

    ~LocationPair() {

    }

    void SetLocation(int first, int second) {
        location1 = first;
        location2 = second;
    }

    void SetLocation(LocationPair loc) {
        SetLocation(loc.location1, loc.location2);
    }

    int Distance() {
        return abs(location1 - location2);
    }

    bool IsValid() {
        return location1 >= 0 && location2 >= 0;
    }

    void UpdateWithMin(LocationPair& loc) {
        if (!IsValid() || loc.Distance() < Distance()) {
            SetLocation(loc);
        }
    }
};