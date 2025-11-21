#include <iostream>
using namespace std;

string user_in_string(string msg) {
    string user_in;
    cout << "Enter the " << msg << ": ";
    cin >> user_in;
    return user_in;
}

int user_in_int(string msg) {
    int user_in;
    cout << "Enter the " << msg << ": ";
    cin >> user_in;
    return user_in;
}
void output_line(string msg, string value){
    cout << msg << value << endl;
}

void output_int(string msg, int value, string unit) {
    cout << msg << value << " " << unit << endl;
}

void output(string first_name, string lastName, int a, int height){
    output_line("First name: ", first_name);
    output_line("Last name: ", lastName);
    output_int("Age: ", a, "years");
    output_int("Height: ", height, "inches");
}

int main() {
    string f_name = user_in_string("first name");
    string l_name = user_in_string("last name");
    int age = user_in_int("age");
    int height = user_in_int("height");

    output(f_name, l_name, age, height);
}