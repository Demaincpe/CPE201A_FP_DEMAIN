#include <iostream> 
#include <cctype> 
using namespace std; 
 
int main() { 
   char ch; 
   cout << "Insert a character: "; 
   cin >> ch; 
   if (isalpha (ch)) { 
       cout << ch << " is alphabet" << endl; 
   } 
   else { 
       cout << ch << " is not alphabet" << endl; 
   } 
   if (isalnum (ch)) { 
       cout << ch << " is alphanumeric" << endl; 
   } 
   else { 
       cout << ch << " is not alphanumeric" << endl; 
   } 
   if (isdigit (ch)) { 
       cout << ch << " is digit" << endl; 
   } 
   else { 
       cout << ch << " is not digit" << endl; 
   } 
   if (isblank (ch)) { 
       cout << ch << " is blank" << endl; 
   } 
   else { 
       cout << ch << " is not blank" << endl; 
   } 
   if (isspace (ch)) { 
       cout << ch << " is space" << endl; 
   } 
   else { 
       cout << ch << " is not space" << endl; 
   } 
   if (iscntrl (ch)) { 
       cout << ch << " is control code" << endl; 
   } 
   else { 
       cout << ch << " is not control code" << endl; 
   } 
   if (isprint (ch)) { 
       cout << ch << " is printable character" << endl; 
   } 
   else { 
       cout << ch << " is not printable character" << endl; 
   } 
   if (isxdigit (ch)) { 
       cout << ch << " is hexadecimal Character" << endl; 
   } 
   else { 
       cout << ch << " is not hexadecimal Character" << endl; 
   } 
   if (ispunct (ch)) { 
       cout << ch << " is punctuation mark" << endl; 
   } 
   else { 
       cout << ch << " is not punctuation mark" << endl; 
   } 
   if (islower (ch)) { 
       cout << ch << " is lowercase letter" << endl; 
   } 
   else { 
       cout << ch << " is not lowercase letter" << endl; 
   } 
   if (isupper (ch)) { 
       cout << ch << " is uppercase letter" << endl; 
   } 
   else { 
       cout << ch << " is not uppercase letter" << endl; 
   } 
   cout << ch << " converted to lowercase"; 
   ch = tolower(ch); 
   cout << " is " << ch << endl; 
   cout << ch << " converted to uppercase"; 
   ch = toupper(ch); 
   cout << " is " << ch << endl; 
 
   return 0; 
} 
