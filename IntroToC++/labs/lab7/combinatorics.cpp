#include <iostream>
using namespace std;

int choose(int n, int r){
    int combinations = 0;
    if(r == 0 || n == r){
        return 1;
    }
        combinations = choose(n - 1, r - 1) + choose(n - 1, r);
        return combinations;
}

int main(){
    int n, r;
    char cont;

    do {
        cout << "Enter n and r: " << endl;
        cin >> n;
        cin >> r;

        if (n < 0 || 0 > r > n){
            cerr << "Error. Follow directions. n >= 0 and 0 <= r <=n." << endl;
            return 0;
        }
        cout << "Number of combinations: " << choose(n, r) << endl;

        char val;
        cout << "Continue?(y/n): " << endl;
        cin >> cont;
        

    } while (cont == 'y' || cont == 'Y');

    
    return 0;
}
