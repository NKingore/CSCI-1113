#include "Poly.hpp"
#include <iostream>
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
            if (p.b > 0) {
                out << " + ";
            } else { 
                out << " - ";
                out << (p.b > 0 ? p.b : -p.b) << "x";
        } else {
            out << p.b << "x";
        }
        printedSomething = true;
        }
    }

    if (p.c != 0) {
        if (printedSomething) {
            if (p.c > 0) {
                out << " + ";
            } else {
                out << " - ";
                out << (p.c > 0 ? p.c : -p.c);
            } 
        } else {
            out << p.c;
        }
        printedSomething = true;
    }

    if (!printedSomething){
        out << 0;
    }
    return out;
}