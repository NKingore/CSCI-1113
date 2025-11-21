#include <iostream>
#include <string>
#include <algorithm>  //for shuffle
#include <cstdlib>    //for time
#include <ctime>      //for time (some platforms)
#include <random>     //for default_random_engine
#include <windows.h>
#include <chrono>
#include <thread>
using namespace std;

void line(){
    cout << "-------------"<< endl;
}

int main(){
    int num_teams = 0;

    line();
    cout << "How many teams?" << endl;
    cin >> num_teams;
    line();
    cout << "Do you want to name your teams(y/n)?" << endl;
    string val;
    cin >> val;

    //How to store names
    string * team_name = new string[num_teams];

    line();
    for (int i = 0; i < num_teams; i++){
        if (val == "y" || val == "Y"){
            //if they want to
            cout << "Enter the name for team "<< (i + 1) << ": " << endl;

            cin >> team_name[i];
        }else if (val == "n" || val == "N"){
            //if the dont want to
            team_name[i] = "Team " + to_string(i + 1);
        }else {
            //if they enter a invalid character
            cerr << "Error. Please enter a valid character(y/n)" << endl;
        }
    }

    //RANDOMIZE
    cout << "SHUFFLING.." << endl;
    line();
    std::this_thread::sleep_for(std::chrono::seconds(3));

    shuffle(team_name, team_name + num_teams, default_random_engine(time(0)));
    cout << "SHUFFLED!" << endl;
    cout << "PRINTING..." << endl;
    line();

    for (int i = 0; i < num_teams; i++){
        cout << team_name[i] << endl;
    }
    line();

    delete[] team_name;

    return 0;
}