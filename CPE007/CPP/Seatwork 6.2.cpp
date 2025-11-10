#include <iostream> 
using namespace std; 
 
 
int perimComp();  
void greetings(); 
void results (int); 
 
int main() { 
    int result; 
    result = perimComp(); 
    results(result); 
    return 0; 
} 
 
void greetings() { 
    cout << "Welcome to the perimeter computation!\n"; 
} 
void results (int perimeter) { 
    cout << "The perimeter result is " << perimeter; 
} 
int perimComp() { 
    int length, width; 
    greetings(); 
    cout << "Please enter the length: "; 
    cin >> length; 
    cout << "Please enter the width: "; 
    cin >> width; 
    return length * width; 
} 
