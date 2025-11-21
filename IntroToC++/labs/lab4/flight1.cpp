#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ofstream out("flightData.dat");
    if (!out) {
        cerr << "Error: could not open flightData.dat for writing.\n";
        return 1;
    }

    // Column widths (tweak if your instructor wants slightly different spacing)
    const int W_FLT = 8;
    const int W_TIME = 10;

    // Title line
    out << left << setw(W_FLT) << "Flight"
        << setw(W_TIME) << "Scheduled"
        << "Actual" << '\n';

    string flight, sched, actual;

    while (true) {
        cout << "Enter the flight number: ";
        if (!(cin >> flight)) break;          // input error / EOF
        if (flight == "end") break;           // sentinel; do NOT write it

        cout << "Enter the scheduled/actual arrival times: ";
        if (!(cin >> sched >> actual)) {
            cerr << "Input error while reading times.\n";
            return 1;
        }

        // Write one formatted record
        out << left << setw(W_FLT) << flight
            << setw(W_TIME) << sched
            << actual << '\n';
    }

    out.close();
    cout << "Data written to flightData.dat\n";
    return 0;
}
