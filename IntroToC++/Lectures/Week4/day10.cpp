#include <iostream>
#include <string>

int main() {


/*
std::string str = "Hello World!";
std::cout << str << std::endl;
std::cout << "The lenghth of the string is " << str.length() << std::endl;

str = "What is happening here.";
std::cout << str << std::endl;
std::cout << "The length of the string is " << str.length() << std::endl;

str = "W\rh\na\tt";
std::cout << str << std::endl;
std::cout << "The length of the string is " << str.length() << std::endl;
    */
    
    std::string str1 = "to be question";
    std::string str2 = "the ";
    std::string str3 = "or not to be";

    str1.insert(6, str2);
    std::cout << str1 << std::endl;

    str1.insert(6, str3, 3, 4);
    std::cout << str1 << std::endl;

    str1.insert(10, "that is cool", 8);
    std::cout << str1 << std::endl;
    
    /*++
    std::string haystack = "There are two needles in this haystack of needles.";
    std::string needleSTR = "needle";

    std::size_t found = haystack.find(needleSTR);
    if (found != std::string::npos) {
        std::cout << "First 'needle' found at: " << found << std::endl;
    }

    found = haystack.find(needleSTR, found+1);
    if (found != std::string::npos) {
        std::cout << "Second 'needle' found at: " << found << std::endl;
    }

    found = haystack.find("haystack");
    if (found != std::string::npos) {
        std::cout << "'haystack' found at: " << found << std::endl;
    }
    */
    /*
    std::string str = "This is an example sentence.";
    std::cout << str << std::endl;

    str.erase(10,8);
    std::cout << str << std::endl;

    str.erase(9,1);
    std::cout << str << std::endl;

    str += " It is an OK sentence.";

    std::cout << str << std::endl;

    std::size_t found = str.find("OK");
    str.erase(found-2, 4);
    std::cout << str << std::endl;
    */
    return 0;
}