#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Animal {
    private:
        string name;
    public:
        virtual void sound() {
            cout << "Animal makes a sound" << endl;
        }
        string getName() {
            return name;
        }
        void setName(string n) {
            name = n;
        }
};

class Dog : public Animal {
    public: 
    void sound() {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
    public:
        void sound() {
            cout << "Cat meows" << endl;
        }

};

class Cow : public Animal {
    public:
        void sound() {
            cout << "Cow moos" << endl;
        }
};

class Horse : public Animal {

};

int main() {

    Dog d;
    d.sound();
    Cat c;
    c.sound();
    Cow cow;
    cow.sound();

    d.setName("Dog");
    c.setName("Whiskers");
    cow.setName("Big Guy");

    Animal animals[3];
    animals[0] = d;
    animals[1] = c;
    animals[2] = cow;

    for (int i = 0, i < 3; i++) {
        animals[i].sound();
    }
}