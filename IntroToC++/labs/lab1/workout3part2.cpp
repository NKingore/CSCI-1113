#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

    int input;

    cout << "Enter a integer from 1 to 999: " << endl;
    cin >> input;

    if(input > 0 && input < 1000){

    int romanNum;
    while(input > 0){

        while(input >= 500){

            cout << "d";
            input = input % 500;

        }
        while(input >= 400){

            cout << "cd";
            input = input % 400;

        }
        if(input >= 100){

            cout << "c";
            input = input % 100;

        }
        if(input >= 90){

            cout << "xc";
            input = input % 90;

        }
        if(input >= 50){

            cout << "l";
            input = input % 50;

        }
        if(input >= 40){

            cout << "xl";
            input = input % 40;

        }
        while(input >= 10){

            cout << "x";
            input = input % 10;    

        }
        if(input == 9){

            cout << "ix";
            input = input % 9;

        }
        if(input >=5){

            cout << "v";
            input = input % 5;

        }       
        if(input == 4){

            cout << "iv";

        }
        else{

            romanNum = input / 1;

            while(romanNum > 1){

                cout << "i";
                romanNum = romanNum - 1;

            }
        }
        

    }

    cout << endl;   

    } 
    else{

        cout << "Error: Input must be between 1 and 999." << endl;

    }

}    


