//writing on a text file
#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream myfile ("file_name.txt");
    string part;
    string line;

    if (myfile.is_open())
    {
        std::size_t found;
        std::size_t start;
        int lines = 0;

        while ( getline(myfile,line) ) {
            cout << "LINE: " << line << endl;
            lines++;
            //parse thru the line for EACH COMMA
            cout << "ROW " << lines << ": ";
            start = 0;
            found=line.find(",");

            while (found !=std::string::npos) {
                part = line.substr(start, found-start);
                cout << part << "\t";
                start = found+1;
                found = line.find(",", start);
            }

            cout << line.substr(start, std::string::npos);
            cout << "\n\n";

        }
    }
    
    return 0;
}