#include "complex.hpp"
#include <iostream>

using namespace std;

Complex::Complex() {
    realValue = 0;
    imaginaryValue = 0;
}

Complex::Complex(double r, double i) {
    realValue = r;
    imaginaryValue = i;
}

bool Complex::operator==(const Complex& rhs) const {
    return (realValue == rhs.realValue &&
        imaginaryValue == rhs.imaginaryValue);
}

Complex Complex::operator+(const Complex& rhs) const {
    return Complex(realValue + rhs.realValue,
        imaginaryValue + rhs.imaginaryValue);
}

Complex Complex::operator-() const {
    return Complex(-realValue, -imaginaryValue);
}

ostream& operator<<(ostream& out, const Complex& c)
{
    if (c.imaginaryValue == 0) {
        out << c.realValue;
    } else if (c.imaginaryValue > 0) {
        out << c.realValue << " + " << c.imaginaryValue << "i";
    } else {
        out << c.realValue << " - " << -c.imaginaryValue << "i";
    }
    return out;
}

istream& operator>>(istream& in, Complex& c)
{
    in >> c.realValue >> c.imaginaryValue;
    return in;
}

