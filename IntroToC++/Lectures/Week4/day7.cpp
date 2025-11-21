
#include <iostream>
using namespace std;

int main() {
    int input;
    cout << "Enter an integer from 1 to 999: ";
    cin >> input;
    if (input < 1 || input > 999) {
        cout << "Input out of range." << endl;
        return 1;
    }

    cout << "Roman numeral: ";

    int num = input;

    // Hundreds
    int hundreds = num / 100;
    int tens = (num % 100) / 10;
    int ones = num % 10;

    // Hundreds place
    if (hundreds == 9) {
        cout << "CM";
    } else if (hundreds >= 5) {
        cout << "D";
        for (int i = 0; i < hundreds - 5; i++) {
            cout << "C";
        }
    } else if (hundreds == 4) {
        cout << "CD";
    } else if (hundreds >= 1) {
        for (int i = 0; i < hundreds; i++) {
            cout << "C";
        }
    }

    // Tens place
    if (tens == 9) {
        cout << "XC";
    } else if (tens >= 5) {
        cout << "L";
        for (int i = 0; i < tens - 5; i++) {
            cout << "X";
        }
    } else if (tens == 4) {
        cout << "XL";
    } else if (tens >= 1) {
        for (int i = 0; i < tens; i++) {
            cout << "X";
        }
    }

    // Ones place
    if (ones == 9) {
        cout << "IX";
    } else if (ones >= 5) {
        cout << "V";
        for (int i = 0; i < ones - 5; i++) {
            cout << "I";
        }
    } else if (ones == 4) {
        cout << "IV";
    } else if (ones >= 1) {
        for (int i = 0; i < ones; i++) {
            cout << "I";
        }
    }

    cout << endl;
    return 0;
}

