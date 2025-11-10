#include <iostream>
#include <iomanip>   // for setw() function and formatting decimals
using namespace std;


// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
   return (9.0 / 5.0) * celsius + 32;
}


// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
   return (5.0 / 9.0) * (fahrenheit - 32);
}


int main() {
   cout << fixed << setprecision(2);  // Format numbers to 2 decimal places


   cout << "--------------------------------------------------------\n";
   cout << "Celsius to Fahrenheit (0°C to 100°C) and\n";
   cout << "Fahrenheit to Celsius (32°F to 212°F)\n";
   cout << "--------------------------------------------------------\n\n";


   cout << setw(10) << "Celsius"
        << setw(15) << "Fahrenheit"
        << "   ||   "
        << setw(10) << "Fahrenheit"
        << setw(12) << "Celsius" << endl;


   cout << "--------------------------------------------------------\n";


   // Use a single loop to minimize lines of output while code stays readable
   for (int i = 0, j = 32; i <= 100 || j <= 212; i += 10, j += 18) {
       cout << setw(8);
       if (i <= 100)
           cout << i << setw(15) << celsiusToFahrenheit(i);
       else
           cout << setw(8) << " " << setw(15) << " ";


       cout << "     || ";


       if (j <= 212)
           cout << setw(8) << j << setw(15) << fahrenheitToCelsius(j);
       cout << endl;
   }


   cout << "--------------------------------------------------------\n";
   return 0;
}


