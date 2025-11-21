#include <iostream>
using namespace std;

int main(){
    const int NUM_SIBLINGS_QUERIES = 14;
    
    
    //int student[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //int student[14] = {0};
    //or
    int student[NUM_SIBLINGS_QUERIES];

    for (int i = 0; i < NUM_SIBLINGS_QUERIES; i++){
        cout << i << ":" << student[NUM_SIBLINGS_QUERIES] << endl;
        cin >> student[i];
        student[i]= 0;
    }

    double avg = 0;
    for (int i = 0; i < NUM_SIBLINGS_QUERIES; i++) {
        cout << i << ":" << student[i] << endl;
        avg += student[i];
    }
    
    cout << "Average number: " << avg / NUM_SIBLINGS_QUERIES << endl;
    return 0;
}
