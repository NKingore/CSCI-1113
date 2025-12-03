#include <iostream>
#include "complex.hpp"

class Poly {
public:
    double a;
    double b;
    double c;

    Poly();
    Poly(double A, double B, double C);

    double eval(double x) const;
    void roots(Complex& r1, Complex& r2);

    Poly operator+(const Poly& rhs) const;

    friend std::ostream& operator<<(std::ostream& out, const Poly& p);
};
