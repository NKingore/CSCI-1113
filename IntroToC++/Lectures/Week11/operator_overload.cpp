#include <string>
#include <iostream>
using namespace std;

class Person {
    public:
        std::string name;
        int age;

        Person(std::string name, int age) : name(name), age(age) {}
            
            bool operator==(const Person& other) const {
                return (name == other.name && age == age.other);
            }

            bool operator==(int x) const {
                return (age == x);
            }
        
};