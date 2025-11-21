#include <iostream>
#include <string>
using namespace std;

//function nextString
string nextString(string str, int start_index) {
    
    if (start_index < 0 || start_index >= str.length()) {
        return "";
    }

    //find the position of the next comma 
    size_t comma_pos = str.find(',', start_index);

    
    if (comma_pos == string::npos) {
        return str.substr(start_index);
    }

    //return substring between start_index and comma_pos
    return str.substr(start_index, comma_pos - start_index);
}

int split(string str, string a[], int max_size){
    int count = 0, start = 0;

    while (start < str.length() && count < max_size) {
        string value = nextString(str, start);
        a[count] = value;
        count++;

        size_t next_comma = str.find(',', start);
        if (next_comma == string::npos){
            break;
        }
        start = next_comma + 1;
    }

    return count;

}

//main program
int main() {
    const int VALUES = 10;
    string somestring;
    string varray[VALUES];

    cout << "Enter a comma-separated string: ";
    getline(cin, somestring);

    int cnt = split(somestring, varray, VALUES);

    for (int i = 0; i < cnt; i++) {
        cout << varray[i] << endl;
    }

    return 0;
}
