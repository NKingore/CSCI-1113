#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>

using namespace std;

class Complex {
    public:
        Complex();
        Complex(double r, double i);

        bool operator==(const Complex& rhs) const;

        Complex operator+(const Complex& rhs) const;

        Complex operator-() const;

        friend ostream& operator<<(ostream& out, const Complex& c);
        friend istream& operator>>(istream& in, Complex& c);
        
    private:
        double realValue;
        double imaginaryValue;
};

#endif