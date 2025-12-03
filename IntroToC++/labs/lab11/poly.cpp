#include "poly.hpp"
#include "complex.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Poly::Poly() {
    a = 0;
    b = 0;
    c = 0;
}

Poly::Poly(double A, double B, double C) {
    a = A;
    b = B;
    c = C;
}

double Poly::eval(double x) const {
    return a * x * x + b * x + c;
}

void Poly::roots(Complex& r1, Complex& r2) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant >= 0) {
        double root1 = (-b / 2 * a) + (sqrt(discriminant) / (2 * a));
        double root2 = (-b / 2 * a) - (sqrt(discriminant) / (2 * a));
        r1 = Complex(root1, 0);
        r2 = Complex(root2, 0);
    } else {
        double real = -b / (2 * a);
        double imaginary = sqrt(-discriminant) / (2 * a);
        r1 = Complex(real, imaginary);
        r2 = Complex(real, -imaginary);
    }
    
}

Poly Poly::operator+(const Poly& rhs) const {
    return Poly(a + rhs.a, b + rhs.b, c + rhs.c);
}

ostream& operator<<(ostream& out, const Poly& p)
{
    bool printedSomething = false;

    if (p.a != 0) {
        out << p.a << "x^2";
    printedSomething = true;
    }

    if (p.b != 0) {
        if (printedSomething) {
            if (p.b > 0) out << " + ";
            else out << " - ";
            out << (p.b > 0 ? p.b : -p.b) << "x";
        } else {
            out << p.b << "x";
        }
        printedSomething = true;
    }

    if (p.c != 0) {
        if (printedSomething) {
            if (p.c > 0) out << " + ";
            else out << " - ";
            out << (p.c > 0 ? p.c : -p.c);
        } else {
            out << p.c;
        }
    printedSomething = true;
    }

    if (!printedSomething)
        out << 0;

    return out;
}

istream& operator>>(istream& in, Poly& p) {
    char ch;
    in >> ch;
    in >> p.a;
    in >> ch;
    in >> p.b;
    in >> ch;
    in >> p.c;
    return in;
}

int main()
{
    Poly inpoly;

    cout << "Input a quadratic polynomial: "; 
    cin >> inpoly;
    for( int i = 0; i <= 10; i++) {
        cout << "f(" << i << ") is: " << inpoly.eval(i) << endl;
    }
    Complex c1, c2;
    inpoly.roots(c1, c2);
    cout << "The roots are; " << c1 << "\t" << c2 << endl;

    Poly q1(3, 4, -2);
    Poly q2(-4, -4, 10);
    Poly sum = q1 + q2;
    cout << q1 << ": q1\n";
    cout << q2 << ": q2\n";
    cout << sum << ": q1+q2\n";
    return 0;
}