#include <iostream>
#include <string>
#include <fstream>
using namespace std;

double fuel_cost(double multiplier, int sim_steps, int pass, int max_pass){
    double base_fuel_cost, tot_fuel_cost;
    base_fuel_cost = multiplier * sim_steps;
    tot_fuel_cost = base_fuel_cost + (pass / max_pass);

}

string get_route_data(string file_name){
    ifstream my_file;
    my_file.open(file_name);
    string line;
    getline(my_file, line);
    size_t found;
    size_t prior = 0;
    int route;
    int time = 0, stop_num = 1;
    found = line.find(",");
    route = stoi(line.substr(0, found));
    prior = found;
    while ( getline(my_file, line) && found != std::string::npos){
        found = line.find(",");
        prior = found;
        time = stoi(line.substr(prior, found)) + time;
        stop_num++;

        route_pass_data(route);
    }

}


int route_pass_data(int route){
    ifstream my_file;
    if(route == 3){
        my_file.open("Route3passengers.dat");
    }else if (route == 6){
        my_file.open("Route6passengers.dat");
    }else if (route == 16){
        my_file.open("Route16passengers.dat");
    }else if (route == 113){
        my_file.open("Route113passengers.dat");
    };

    string line;
    getline(my_file, line);
    size_t found;
    size_t prior = 0;
    int waiting_pass, pass_lost, line_count = 0;

    while ( getline(my_file, line) && found != std::string::npos){
        found = line.find(",");
        waiting_pass = stoi(line.substr(prior, found));
        prior = found;

        found = line.find("\n");
        pass_lost = stoi(line.substr(prior, found));
        line_count++;
    }
    

}

string get_bus_data(){
    ifstream my_file;
    my_file.open("buses.dat");
    string line;
    getline(my_file, line);
    size_t found, prior = 0;
    int bus_num, max_pass, linecount = 0;
    double multiplier;

    while( getline(my_file, line) && found != std::string::npos){
        found = line.find(",");
        bus_num = stoi(line.substr(prior, found));
        prior = found;

        found = line.find(",");
        multiplier = stod(line.substr(prior, found));
        prior = found;

        found = line.find("\n");
        max_pass = stoi(line.substr(prior,found));
        linecount++;
    }
}
void get_sim_data(){
    ifstream my_file;
    my_file.open("sim.dat");
    string line;
    getline(my_file, line);
    size_t found, prior:



}

int main(){



    return 0;
}