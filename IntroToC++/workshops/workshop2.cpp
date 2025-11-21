#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

double func1(char sex, int inputAge, int var){
    ifstream data ("SSA Actuarial Life Table.csv");
    string line;
    
    double table[150][5];
    int age = 0, male_death = 1, male_life = 2, female_death = 3, female_life = 4;
    int line_count = 2;

    if (data.is_open()){
        getline(data, line);

        size_t found;
        size_t prior;

        while ( getline(data, line) ){
            found=line.find(",");
            

            if (found!=std::string::npos){
                table[line_count][age] = stod(line.substr(0, found));

                prior = found + 1;
                found = line.find(",", prior);
                table[line_count][male_death] = stod(line.substr(prior, found - prior));

                prior = found + 1;
                found = line.find(",", prior);
                table[line_count][male_life] = stod(line.substr(prior, found - prior));

                prior = found + 1;
                found = line.find(",", prior);
                table[line_count][female_death] = stod(line.substr(prior, found - prior));

                prior = found + 1;
                found = line.find(",", prior);
                table[line_count][female_life] = stod(line.substr(prior, found - prior));
                line_count++;
            }
        }
    } 
    data.close();

    /*display array for troubleshooting
    for(int i = 0; i < line_count; i++){
        for(int j = 0; j < 5; j++){
            std::cout << std::setw(10) << table[i][j];
        }
        std::cout << std::endl;
    }*/

    double lifeExpect = 0;
    double lifeEst = 0;
    double lifeEstCalc = 0;
    int death = 0;

    switch (sex){
        case 'm':
            if(var == 0){
            lifeExpect = table[inputAge][male_life];
            return lifeExpect;
            }else{
            lifeEst = table[inputAge][male_death];
            return lifeEst;
            }
            
            break;
        case 'f':
            if(var == 0){
            lifeExpect = table[inputAge][female_life];
            return lifeExpect;
            }else{
            lifeEst = table[inputAge][female_death];
            return lifeEst;
            }
            break;
        default:
            return 0;
    }
}

int main(){
//random number
    srand(static_cast<unsigned int>(time(nullptr)));
    char val;
    bool t_OR_f = true;
    int inputAge;
    char sex;
    double lifeExpect = 0;
    double lifeEst = 0;
    double lifeEstCalc = 0;
    int death = 0;
    int var = 0;

    while(t_OR_f == true){
        std::cout << "Enter your age: ";
        cin >> inputAge;
        std::cout << "Enter you sex(f/m): ";
        cin >> sex;
        int age1 = inputAge;

        switch (sex){
            case 'm':
                lifeExpect = func1(sex, inputAge, 0);
                lifeEst = func1(sex, inputAge, 1);
                break;
            case 'f':
                lifeExpect = func1(sex, inputAge, 0);
                lifeEst = func1(sex, inputAge, 1);
                break;
            default:
                std::cout << "Invalid entry, Please enter f/m";
        }
        
        

        while (true){
            lifeEstCalc = rand() / (double)RAND_MAX;
            if (lifeEstCalc > lifeEst){
                inputAge++;
                death = inputAge;
                lifeEst = func1(sex, inputAge, 1);
            }else {
                break;
            }
            
        }

        //output
        std::cout << endl << "--------------------------------------------------------" << endl;
        std::cout << "You are current age is " << age1 << " years old." << endl;
        if(sex == 'm'){
            std::cout << "You are a man." << endl;
        }else if(sex == 'f'){
            std::cout << "You are a woman." << endl;
        }
        std::cout << "--------------------------------------------------------" << endl << endl;
        if(death > lifeExpect){
            std::cout << "According to our calculations, you are expectied to live until you are " << inputAge << " years old." << endl << "This means you will outlive the SSA life expectancy of " << lifeExpect + age1 << " for your current age and sex! :)" << endl;
            t_OR_f = false;
            std::cout << endl << "--------------------------------------------------------" << endl;
        }else{
            std::cout << "Unfortunately, you will die before the SSA life expectancy for your current age and sex. :(" << endl;
            std::cout << "Would you like to try again(y/n)?" << endl;
            std::cout << endl << "--------------------------------------------------------" << endl;
            cin >> val;
        }
        
        if(val != 'y'){
            t_OR_f = false;
        }
    }
}