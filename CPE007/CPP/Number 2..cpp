#include <iostream>
#include <cmath>  // for sqrt() and pow() functions
using namespace std;


// Function to calculate the hypotenuse of a right triangle
double hypotenuse(double side1, double side2) {
   return sqrt (pow(side1, 2) + pow(side2, 2));
}


int main() {
   double a, b;
   cout << "Enter the length of first side: ";
   cin >> a;
   cout << "Enter the length of second side: ";
   cin >> b;
   double c = hypotenuse(a, b);
   cout << "The length of the hypotenuse is: " << c << endl;


   return 0;
}



