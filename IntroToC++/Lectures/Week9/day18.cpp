#include <iostream>

int main() {
    int a = 1;
    int b = 2;

    //prints the memory adress for a and b
    //std::cout << &a << "|" << &b << std::endl;

    int c = 1, d = 2;

    //std::cout << &c << "|" << &d << std::endl;

    int static_array[10];

    //std::cout << static_array << "|" << &static_array[0] << std::endl;

    for (int i = 0; i < 10; i ++) {
        std::cout << &static_array[i] << " <-- static_array[" << i << "]" << std::endl;
    }

    std::cout << &d << "<-- d" << std::endl << &c << "<-- c" << std::endl;
    std::cout << &b << "<-- b" << std::endl << &a << "<-- a" << std::endl;
    
    std::cout << "---------" << std::endl;


    int * pA = new int;
    int * pB = new int;
    *pA = 1;
    *pB = 2;

    int * pC = new int, * pD = new int;

    std::cout << &(*pA) << " <-- &(*pA)" << std::endl << &(*pB) << " <-- &(*pB)" << std::endl;
    std::cout << &(*pC) << " <-- &(*pC)" << std::endl << &(*pD) << " <-- &(*pD)" << std::endl;

    int dynamic_array[10];

    for (int i = 0; i < 10; i++) {
        std::cout << &dynamic_array[i] << " <-- dynamic_array[" << i << "]" << std::endl;
    }

    delete pA;
    delete pB;
    delete[] dynamic_array;

    return 0;
}