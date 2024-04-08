#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstring>
#include <iterator>
#include <iomanip>
#include <random>
#include <limits>
#include <math.h>
#include <list>
#include <string>
#include <array>

using namespace std;

void addUnit(array<array<array<list<string>,3>,7>,9>& units, char time, char length, char mass, string name) {
    units[time+4][length+3][mass+1].push_back(name);
}
list<string> getUnit(array<array<array<list<string>,3>,7>,9>& units, char time, char length, char mass) {
    return units[time+4][length+3][mass+1];
}

void printAll(array<array<array<list<string>,3>,7>,9>& units) {
    for(int i = 0; i<9; i++) {
        for(int j = 0; j<7; j++) {
            for(int k = 0; k<3; k++) {
                list<string> results = units[i][j][k];
                
                for(string unit : results) {
                    cout << unit << endl;
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    array<array<array<list<string>,3>,7>,9> units;

    addUnit(units, 0, 0, 0, "Unitless");
    addUnit(units, 1, 0, 0, "Time");
    addUnit(units, 0, 1, 0, "Length");
    addUnit(units, 0, 0, 1, "Mass");

    addUnit(units, -1, 1, 0, "Velocity");
    addUnit(units, -2, 1, 0, "Acceleration");
    addUnit(units, -3, 1, 0, "Jerk");
    addUnit(units, -4, 1, 0, "Snap");

    addUnit(units, -1, 1, 1, "Momentum");
    addUnit(units, -1, 1, 1, "Impulse");
    addUnit(units, -2, 1, 1, "Force");
    addUnit(units, -2, 2, 1, "Energy");
    addUnit(units, -3, 2, 1, "Power");
    addUnit(units, -2, -1, 1, "Pressure");

    addUnit(units, 0, 2, 1, "Moment Of Inertia");
    addUnit(units, -2, 2, 1, "Torque");
    addUnit(units, 0, 0, 0, "Angle");
    addUnit(units, -1, 0, 0, "Angular Velocity");
    addUnit(units, -2, 0, 0, "Angular Acceleration");

    addUnit(units, 0, 2, 0, "Area");
    addUnit(units, 0, 2, 0, "Volume");

    addUnit(units, -1, 0, 0, "Frequency");

    printAll(units);
}
