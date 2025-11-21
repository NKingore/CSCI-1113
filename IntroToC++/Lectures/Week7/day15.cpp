#include <iostream>
using namespace std;

int main() {
    string f_name;
    cout << "Enter the first name:";
    cin >> f_name;

    string l_name;
    cout << "Enter the last name:";
    cin >> l_name;

    int age;
    cout << "Enter the age:";
    cin >> age;

    int height;
    cout << "Enter the height:";
    cin >> height;

    cout << "First name: " << f_name << endl;
    cout << "Last name: " << l_name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;

    return 0;

}