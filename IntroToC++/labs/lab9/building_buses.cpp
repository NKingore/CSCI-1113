#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX_STOPS = 100;
const int MAX_BUSES = 50;

struct Bus {
    int id;
    double fuelMultiplier;
    int capacity;
};

void loadPassengerData(int routeNum, int waiting[], int disembark[], int &count) {
    string filename = "Route" + to_string(routeNum) + "passengers.dat";
    ifstream file(filename);
    int w, d;
    char comma;
    count = 0;
    while (file >> w >> comma >> d && count < MAX_STOPS) {
        waiting[count] = w;
        disembark[count] = d;
        count++;
    }
}

int loadRouteData(int routeNum, int steps[]) {
    ifstream file("routes.dat");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        int r = stoi(token);
        if (r == routeNum) {
            int count = 0;
            while (getline(ss, token, ',') && count < MAX_STOPS)
                steps[count++] = stoi(token);
            return count;
        }
    }
    return 0;
}

int loadBusData(Bus buses[]) {
    ifstream file("buses.dat");
    string line;
    int count = 0;
    while (getline(file, line) && count < MAX_BUSES) {
        stringstream ss(line);
        string idStr, multStr, capStr;
        getline(ss, idStr, ',');
        getline(ss, multStr, ',');
        getline(ss, capStr, ',');
        buses[count].id = stoi(idStr);
        buses[count].fuelMultiplier = stod(multStr);
        buses[count].capacity = stoi(capStr);
        count++;
    }
    return count;
}

int main() {
    ifstream sim("sim.dat");
    int routeNum, busNum;
    sim >> routeNum >> busNum;

    int waiting[MAX_STOPS], disembark[MAX_STOPS], steps[MAX_STOPS];
    int numStops = loadRouteData(routeNum, steps);
    int numPassengers = 0;
    loadPassengerData(routeNum, waiting, disembark, numPassengers);

    Bus buses[MAX_BUSES];
    int numBuses = loadBusData(buses);

    int busIndex = -1;
    for (int i = 0; i < numBuses; i++)
        if (buses[i].id == busNum) busIndex = i;

    double fuelCost = 0;
    if (busIndex != -1) {
        for (int i = 0; i < numStops; i++)
            fuelCost += steps[i] * buses[busIndex].fuelMultiplier * 2.5;
    }

    cout << "Total fuel cost: " << fuelCost << endl;
    return 0;
}
