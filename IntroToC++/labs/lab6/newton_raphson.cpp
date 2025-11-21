#include <iostream>

double abs(double x){
    if (x < 0.0){
        x = -x;
        return x;
    }else if(x > 0.0){
        x = x;
        return x;
    }
    return 0;
}

double power(double base, int exponent){
    double answer = base;

    for(int i = 1; i < exponent; i++){
        if (exponent == 0){
            return 1.0;
        }   
        answer = answer * base;
    }
    
    return answer;
}

double rootN(double K, int n){
    double root, oldGuess = 1.0, newGuess = 1.0, accuracy = 0.00001;
    int maxIter = 10000, iter = 0;

    if (n == 1){
        return K;
    }
    if (n == 0.0){
        return 0.0;
    }

    oldGuess = K;

    do {
        double root = power(oldGuess, n - 1);
        if (root)
        newGuess = (1.0 / n) * (((n - 1.0) * oldGuess) + (K / root));
        if (abs(newGuess - oldGuess) < accuracy){
            break;
        }
        oldGuess = newGuess;
        ++iter;
        } while (iter < maxIter);

    return newGuess;
}

int main(){
    int K = 0, n = 0;
    double answer;
    bool again = true;

    while (again == true){
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Enter value and root: ";
        std::cin >> K >> n;
        std::cout << "-------------------------------" << std::endl;

        if(K > 0 && n > 1){
            answer = rootN(K, n);
        }else if(K < 0){
            std::cerr << "Error. K must be a non-negative number. Please enter a valid number." << std::endl;
            
        }else if(n < 1){
            std::cerr << "Error. n must be a number greater than 1. Please enter a valid number" << std::endl;

        }
        std::cout << "The approximate " << n << "th root of " << K << " is: " << answer << std::endl;
        std::cout << "Continue?(y/n)" << std::endl;
        char go;

        std::cin >> go;
        if (go == 'y'){
            again = true;
        }else if (go == 'n'){
            again = false;
        }else {
            std::cerr << "Intput not valid. Please enter y or n." << std::endl;
        }
        
    }

    return 0;
}
