#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
//declare both arrays.
    const int NROWS = 20;
    const int NCOLS = 20;
    int temp[NROWS][NCOLS];
    int old[NROWS][NCOLS];

//user inputs temp of all sides of the plate.
    float temp_T = 0, temp_B = 0, temp_R = 0, temp_L = 0, temp_I = 0;

    cout << "What is the temperature of the top side of the plate?" << endl;
    cin >> temp_T;
    cout << "What is the temperature of the bottom side of the plate?" << endl;
    cin >> temp_B;
    cout << "What is the temperature of the right side of the plate?" << endl;
    cin >> temp_R;
    cout << "What is the temperature of the left side of the plate?" << endl;
    cin >> temp_L;
    cout << "What is the initial temperature of the center reigion of the plate?" << endl;
    cin >> temp_I;

//setting array to temp inputs given by user
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < NROWS; i++){
        for(int j = 0; j < NROWS; j++){
            temp[i][j] = 1;
            if (i == 0){
                temp[0][j] = temp_T;
            }else
            if (i == NROWS - 1){
                temp[NROWS - 1][j] = temp_B;
            }else
            if (j == 0){
                temp[i][0] = temp_R;
            }else 
            if (j == NCOLS - 1){
                temp[i][NCOLS - 1] = temp_L;
            }else{
                temp[i][j] = temp_I;
            }

            cout << left << setw(3) << temp[i][j];

        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;

//user inputs convergence criterion
    float convergence = 0.0;
    cout << "Enter your convergence criterion: " << endl;
    cin >> convergence;
    cout << "----------------------------------------" << endl;
    
    
    for(int i = 0; i < NROWS; i++)
        for(int j = 0; j < NCOLS; j++)
            old[i][j] = temp[i][j];
        
    

    bool steady;
    do {
        steady = true;
//copy current temp to old temp
        for(int i = 0; i < NROWS; i++)
            for(int j = 0; j < NCOLS; j++)
                old[i][j] = temp[i][j];

        for (int i = 1; i < NROWS - 1; i++){
            for (int j = 1; j < NCOLS - 1; j++){

                temp[i][j] = 0.25 * (old[i + 1][j] + old[i - 1][j] + old[i][j + 1] + old[i][j - 1]);

                if (abs(temp[i][j] - old[i][j]) > convergence){
                    steady = false;
                    
                }
            }
        } 
    } while (!steady);

//Print final array
    for (int i = 0; i < NROWS; i++) {
        for(int j = 0; j < NCOLS; j++){
            cout << left << setw(6) << temp[i][j];
        }
        cout << endl;
    }
    cout << "----------------------------------" << endl;

    return 0;
}