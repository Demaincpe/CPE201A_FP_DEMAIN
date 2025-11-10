#include <iostream> 
#include <cctype> 
using namespace std; 
 
int main() { 
   char ch [] = "pP5!Dd8&u7$L"; 
   //islower 
   cout << "According to islower: " << endl; 
   for (int i = 0; i < 4; i++) { 
       if (islower(ch[i])) { 
           cout << ch[i] << " is a lowercase letter" << endl; 
       } 
       else { 
           cout << ch[i] << " is not a lowercase letter" << endl; 
       } 
   } 
   //isupper 
   cout << "\nAccording to isupper: " << endl; 
   for (int i = 4; i < 8; i++) { 
       if (isupper(ch[i])) { 
           cout << ch[i] << " is an uppercase letter" << endl; 
       } 
       else { 
           cout << ch[i] << " is not an uppercase letter" << endl; 
       } 
   } 
   cout << endl; 
   for (int i = 8; i < 11; i++) { 
       cout << ch[i] << " converted to uppercase"; 
       ch [i] = toupper(ch[i]); 
       cout << " is " << ch[i] << endl; 
   } 
   for (int i = 11; i < 12; i++) { 
       cout << ch[i] << " converted to lowercase"; 
	   ch [i] = tolower(ch[i]); 
	   cout << " is " << ch[i] << endl; 
	} 
	return 0; 
} 
