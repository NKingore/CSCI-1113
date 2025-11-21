#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

int main(){

    //declaring input variables
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double m = 0.0;
    int q = 0;
    double bound_left = 0.0;
    double bound_right = 0.0;

    //asking user for input variable values
    std::cout << "Enter your coefficient for a in polynomial (ax^2 + bx + c): " << std::endl;
    std::cin >> a;
    std::cout << "Enter your coefficient for b in polynomial (ax^2 + bx + c): " << std::endl;
    std::cin >> b;
    std::cout << "Enter your coefficient for c in polynomial (ax^2 + bx + c): " << std::endl;
    std::cin >> c;
    std::cout << "Enter the height of the rectangle: " << std::endl;
    std::cin >> m;
    std::cout << "Enter the number of darts you want to be thrown: " << std::endl;
    std::cin >> q;
    std::cout << "Enter the left boundry for the integral: " << std::endl;
    std::cin >> bound_left;
    std::cout << "Enter the right boundry for the integral: " << std::endl;
    std::cin >> bound_right;

    int p = 0;

    double x = 0.0;
    double y = 0.0;


    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    //Assigning random values
    for(int i = 0; i < q; i++){
        double X = bound_left + (bound_right - bound_left) * (std::rand() / (double)RAND_MAX);
        double Y = m * (std::rand() / (double)RAND_MAX);
        
        double curve = a * X * X + b * X + c;
        if(Y <= curve && Y >= 0 && curve >= 0){
            p++;
        }
    }

    double rect_area = (bound_right - bound_left) * m;
    double area = rect_area * (static_cast<double>(p) / q);

    std::cout << "Estimated area under the curve: " << area << std::endl;

    return 0;

}