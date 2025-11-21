#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>


int main(){
    //opening the file
    std::ofstream out("flightData.dat");
    if(!out){
        std::cout << "Error while opening file for writing" << std::endl;
        return 1;
    }

    //Title of file
    const int f_width = 8;
    const int s_width = 10;
    const int a_width = 13;

    out << std::left << std::setw(f_width) << "Flight";
    out << std::left << std::setw(s_width) << "Scheduled";
    out << std::left << std::setw(a_width) << "Actual" << std::endl;

    std::string flight, scheduled, actual;
    int j = 0;
    while(j != 1){
        std::cout << "Enter flight number" << std::endl;
        std::cin >> flight;
        if(flight == "end"){
            j = 1;
        }else{
            std::cout << "Enter scheduled arrival time" << std::endl;
            std::cin >> scheduled;
            std::cout << "Enter actual arival time" << std::endl;
            std::cin >> actual;

            out << std::left << std::setw(f_width) << flight;
            out << std::left << std::setw(s_width) << scheduled;
            out << std::left << std::setw(a_width) << actual << std::endl;
        }

    }

    out.close();
    return 0;
}