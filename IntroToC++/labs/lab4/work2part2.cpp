#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

    //change time format from HH:MM to mins since midnight
    

    //ask for file name and open the file
    string file_name;
    cout << "Enter the name of the flight data file" << endl;
    cin >> file_name;
    if(!(cin >> file_name)){
        cout << "Error. No file with that name." << endl;
        return 1;
    }

    ifstream in;
    in.open(file_name.c_str());
    if(!in){
        cout << "Error. Failure to open file.";
        return 1;
    }

    //get info from file
    string header;
    getline(in, header);

    double totalDelays = 0;
    int count = 0;

    int min_delay, max_delay; 
    string minFlight, maxFlight;

    //output delays of all flights
    cout << left << setw(8) << "Flight" << "Delay";

    string flight, scheduled, actual;


    return 0;
}