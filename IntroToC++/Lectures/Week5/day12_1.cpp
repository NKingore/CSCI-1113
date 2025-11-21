#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){
    
    ifstream myfile ("company_data.csv");
    string line;
    string emp_id;
    string emp_name;
    string emp_position;
    string emp_class;
    string emp_salary;
    double total_salary;
    double total_bonus;

    if (myfile.is_open())
    {
        std::size_t found;
        std::size_t prior;

        while ( getline(myfile, line) ){
            found=line.find(",");

            if (found!=std::string::npos) {
                emp_id=line.substr(0, found);

                prior=found+1;
                found=line.find(",", prior);
                emp_name=line.substr(prior, found-prior);

                prior=found+1;
                found=line.find(",", prior);
                emp_position=line.substr(prior, found-prior);

                prior=found+1;
                found=line.find(",", prior);
                emp_class=line.substr(prior, found-prior);

                prior=found+1;
                found=line.find(",", prior);
                emp_salary=line.substr(prior, found-prior);

            }

            char classifier = emp_class.at(0);
            double bonus_rate;
            switch(classifier) {
                case 'E': bonus_rate = .3; break;
                case 'S': bonus_rate = .2; break;
                case 'M': bonus_rate = .15; break;
                
                double salary = stod(emp_salary);
                double bonus = salary * bonus_rate;
                total_salary += salary;
                total_bonus += bonus;

                cout << emp_name << "(" << classifier << ")" << endl;
                if (classifier == 'E' || classifier == 'S' || classifier == 'M') {
                    cout << "BONUS: " << bonus << endl;
                }

            }

            cout << std::fixed << setprecision(2);
            cout << "TOTAL SALARY OUTLAY: $" << setfill('0') <<setw(15) << total_salary << endl;
            cout << "TOTAL BONUS OUTLAY:  $" << setfill(' ') <<setw(15) << total_bonus << endl;
            cout << "TOTAL COMP OUTLAY:   $" << setfill('~') <<setw(15) << (total_salary + total_bonus) << endl; 
        }

    }
    else cout << "Unable to open file";

    return 0;
}