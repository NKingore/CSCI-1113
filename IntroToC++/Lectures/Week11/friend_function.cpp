#include <iostream>

class Date {
    private:
    int mo, da, yr;
    public:
        Date(int m, int d, int y) 
        {
            mo = m;
            da = d;
            yr = y;
        }
        friend std::ostream& operator<<(std:ostream& os, const Date& dt) {
            os << dt.mo << '/' << dt.da << '/' << dt.yr;
            return os;
        }
};

int main() 
{
    Date dt(5, 6, 92);
    std::cout << "The date in question is " << dt << ".";
}