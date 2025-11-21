#include <iostream>
using namespace std;

int main(){

    int ind = 0;

    while (ind < 50) {
        if (ind % 10 == 9){
            cout << ind;
        }
        else {
            cout << ".";
        }
        ind++;
    }
    cout << endl;

    for (int i = 0; i < 50; i++){
        if (i % 10 == 9) {
            cout << i;
        }
        else {
            cout << ".";
        }
    }
    cout << endl;

}