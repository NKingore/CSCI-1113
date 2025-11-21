#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

#include <cmath>
using namespace std;

// Parse "HH:MM" -> minutes since midnight
int toMinutes(const string& hhmm) {
    int h = 0, m = 0;
    char colon;
    stringstream ss(hhmm);
    ss >> h >> colon >> m;               // expects h:m with ':'
    return h * 60 + m;
}

// Format signed minutes -> "h:mm" (with leading '-' if early)
string fmtSignedHM(int minutes) {
    char sign = minutes < 0 ? '-' : '\0';
    int a = abs(minutes);
    int h = a / 60;
    int m = a % 60;
    stringstream out;
    if (sign) out << sign;
    out << h << ':' << setw(2) << setfill('0') << m;
    return out.str();
}

int main() {
    // 1) Ask for filename and open it
    cout << "Enter flight data filename: ";
    string filename;
    if (!(cin >> filename)) {
        cerr << "No filename provided.\n";
        return 1;
    }

    ifstream in;
    in.open(filename.c_str());           // note: use c_str() on a string
    if (!in) {
        cerr << "Error: could not open '" << filename << "'.\n";
        return 1;
    }

    // 2) Read header line (e.g., "Flight Scheduled Actual")
    string header;
    getline(in, header);                 // consume end of line after filename read
    if (header.empty() && in) getline(in, header); // handle if previous >> left newline

    // 3) Running stats
    long long sumDelays = 0;
    int count = 0;

    int minDelay = INT_MAX, maxDelay = INT_MIN;
    string minFlight, maxFlight;

    // 4) Print per-flight delays
    cout << left << setw(10) << "Flight" << "Delay\n";

    string flight, sched, actual;
    while (in >> flight >> sched >> actual) {
        int s = toMinutes(sched);
        int a = toMinutes(actual);

        // If actual < scheduled, assume arrival after midnight (next day)
        if (a < s) a += 24 * 60;

        int delay = a - s;               // signed minutes (negative = early)
        cout << left << setw(10) << flight << fmtSignedHM(delay) << '\n';

        sumDelays += delay;
        ++count;

        if (delay < minDelay) { minDelay = delay; minFlight = flight; }
        if (delay > maxDelay) { maxDelay = delay; maxFlight = flight; }
    }

    if (count == 0) {
        cerr << "No flight records found.\n";
        return 1;
    }

    // 5) Averages and extremums
    int avgDelayRounded = static_cast<int>(llround(static_cast<double>(sumDelays) / count));

    cout << "\nStatistics\n";
    cout << "----------\n";
    cout << "Average delay: " << fmtSignedHM(avgDelayRounded) << '\n';
    cout << "Minimum delay: " << left << setw(10) << minFlight << fmtSignedHM(minDelay) << '\n';
    cout << "Maximum delay: " << left << setw(10) << maxFlight << fmtSignedHM(maxDelay) << '\n';

    return 0;
}
