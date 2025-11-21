
// writing on a text file
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main(){
    
    //ofstream myfile ("app_test.txt", ios::app); //part 2
    //ofstream myfile ("app_test.txt"); //part 1
    ofstream myfile ("lorem.txt");
//ofstream = output file stream
//ifstream = input file stream
//name of the file is lorem.txt. If its not there, it will create a file with that name.

    if (myfile.is_open())
    {
        //myfile << "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Et" << endl;
        
        cout << "WE ARE PRINTING" << endl;
        
        //myfile << "Nullam eget facilisis enim, sit amet euismod massa. Quisque" << endl;

        myfile << "Today is Monday...yeah it is" << endl;

        myfile.close();
    }
    else cout << "Unable to open file";
    return 0;


    string user_in;
    if (myfile.is_open())
    {
        cout << "Enter your first name: " << endl;
        getline(cin, user_in);
        myfile << user_in << endl;
        cout << "Enter your second line: " << endl;
        getline(cin, user_in);

        myfile << user_in << endl;

    }

    int remove_f = 1;
    cout << "Print 0" << endl;
    cin >> remove_f;
    
    const char* filename = "lorem.txt";


    if (remove == 0){
    remove(lorem.txt);
    return 0;
    }
}