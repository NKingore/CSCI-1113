#include <iostream>
using namespace std;

struct Circle{
//these variables are called "Member Variables". They are declared in the struct data type.
    double radius;
    double area;
    double x_pos; //x coordinate of the center of the circle 
    double y_pos; //y coordinate of the center of the circle
    double get_radius();
    void set_radius(double);
    //double get_area();
};

void print(Circle c) {
    cout << "Circle at (" << c.x_pos << "," << c.y_pos << ")";
    cout << " with radius " << c.radius << endl;
}

double Circle::get_radius() {
    return radius;
}

void Circle::set_radius(double new_radius) {
    radius = new_radius;
}

int main() {

    /*-------------------------------
    Circle my_circle;

    my_circle.radius = 5;
    my_circle.x_pos = 1;
    my_circle.y_pos = 2;

    print(my_circle);

    my_circle.radius = 10;

    print (my_circle); 
    ---------------------------------*/

    Circle *my_circle_ptr = new Circle();
    my_circle_ptr->radius = 5;

    Circle circles[5] = {
        {5, 1, 2},
        {7, 5, 6},
        {100, 300, 425},
        {1, 0.5, 0.5},
        {10, 10, 20}
    };

    for (int i = 0; i < 5; i++) {
        print (circles[i]);
    }

    return 0;
}