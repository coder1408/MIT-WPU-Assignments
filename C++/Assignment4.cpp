#define _USE_MATH_DEFINES // required for M_PI to be defined
#include <iostream>
#include <cmath>
using namespace std;

const double pi = acos(-1); // define pi as a constant

// define M_PI if it is not already defined
#ifndef M_PI
  #define M_PI pi
#endif

class Shape {
public:
  virtual double area() = 0; // pure virtual function
};

class Rectangle : public Shape {
private:
  double length;
  double breadth;
public:
  Rectangle(double l=0, double b=0) { length = l; breadth = b; }
  double area() { return length * breadth; }
};

class Square : public Shape {
private:
  double side;
public:
  Square(double s=0) { side = s; }
  double area() { return side * side; }
};

class Circle : public Shape {
private:
  double radius;
public:
  Circle(double r=0) { radius = r; }
  double area() { return M_PI * pow(radius, 2); }
};

int main() {
  Shape* shapes[3]; // array of pointers to Shape objects

  // create Rectangle, Square, and Circle objects
  Rectangle rect(4, 5);
  Square sq(7);
  Circle circle(3);

  // store object addresses in the array
  shapes[0] = &rect;
  shapes[1] = &sq;
  shapes[2] = &circle;

  // calculate and display areas of shapes
  for(int i=0; i<3; i++) {
    cout << "Area of shape " << i+1 << " is " << shapes[i]->area() << endl;
  }

  return 0;
}
