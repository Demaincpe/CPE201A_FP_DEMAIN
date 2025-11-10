#include "Design.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <thread>
using namespace std;

// Aesthetic Pursposes ===========================================================
void ms250(){ // Delay for 250 millisecond before continuing
	this_thread::sleep_for(chrono::milliseconds(250)); 
}
void ms500(){ // Delay for 500 millisecond before continuing
	this_thread::sleep_for(chrono::milliseconds(500));
}
void s1(){ // Delay for 1 second before continuing
	this_thread::sleep_for(chrono::seconds(1));
}
void s2(){ // Delay for 2 second before continuing
	this_thread::sleep_for(chrono::seconds(2));
}
void loading(){ // Loading animation
	for(int a = 0; a < 2; a++){
		cout << "Loading"; ms250(); cout << "."; ms250(); cout << "."; ms250(); 
		cout << "."; ms250(); system("cls"); ms250();
	}
}
void txtAnimation(string text, int speed){ // Typing effect on texts
    for(char c : text){
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
}
