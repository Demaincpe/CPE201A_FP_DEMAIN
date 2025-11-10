#include <iostream>
#include <cmath>   // for the pow() function
using namespace std;


// Function to compute the volume of a cube using pow function
double cubeVol(double side) {
   return pow(side, 3);  // pow(base, exponent)
}


int main() {
   double side;
   cout << "Enter the side length of the cube: ";
   cin >> side;
   double volume = cubeVol(side);
   cout << "The volume of the cube is: " << volume << endl;


   return 0;
}

