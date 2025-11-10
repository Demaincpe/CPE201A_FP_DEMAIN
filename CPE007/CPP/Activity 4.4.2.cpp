#include <iostream> 
#include <cctype> 
using namespace std; 
 
int main() { 
   string l1, l2, l3, l4; 
   int n1, n2, n3, n4, total; 
// Input strings 
   cout << "Enter first number: "; 
   cin >> l1; 
   cout << "Enter second number: "; 
   cin >> l2; 
   cout << "Enter third number: "; 
   cin >> l3; 
   cout << "Enter fourth number: "; 
   cin >> l4; 
 // Convert strings to integers 
   n1 = stoi(l1); 
   n2 = stoi(l2); 
   n3 = stoi(l3); 
   n4 = stoi(l4); 
// Sum integers 
   total = n1 + n2 + n3 + n4; 
// Print total 
   cout << "The total of the 4 values is: " << total << endl; 
   
   return 0; 
} 
