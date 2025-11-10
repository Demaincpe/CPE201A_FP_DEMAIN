#include "LogInSys.h"
#include "Design.h"
#include "mainMenu.h"

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

void registration(){ // Registration Definition
	string username, password;
	cout << "Welcome to the Registration Menu!!" << endl; s1();
	cout << "Please enter your username: "; cin >> username;
	if(checkUser(username)){ // Calls the function to check if the username is already taken
		cout << "Username has already been taken!!" << endl; s2(); return;
	}
	cout << "Please enter your password: "; cin >> password;
	ofstream file("credentials.txt", ios::app);
	if(file.is_open()){
		file << username << ' ' << password << endl; system("cls"); loading();
		txtAnimation("Registration is successful, Thank you for registering!", 10);
		cout << endl; file.close(); s2();
	}
}
bool checkUser(string user){ // Checking Username Definition
	string storedUser, storedPass;
	ifstream file("credentials.txt");
	if(file.is_open()){
		while(file >> storedUser >> storedPass){
			if(storedUser == user){
				file.close(); return true;
			}
		}
		file.close();
	}
	return false;
}
bool login(){ // Login Definition
	string username, password, storedUser, storedPass;
	cout << "Welcome to the Log-in Menu!!" << endl; ms500();
	cout << "Please enter your username: "; cin >> username;
	cout << "Enter your password: "; cin >> password;
	ifstream file("credentials.txt");
	if(file.is_open()){
		while(file >> storedUser >> storedPass){
			if(storedUser == username && storedPass == password){
				system("cls"); loading(); txtAnimation("Log-in successful!", 10);
				file.close(); s2(); return true;
			}
		}
		file.close(); system("cls"); loading();
		txtAnimation("Invalid username or password! Please try again.", 10); s2();
		return false; 
	}
}
bool adminLogin(){ // Admin Log-in Definition
	string username, password, storedUser, storedPass;
	cout << "Welcome to the Admin Log-in Menu!!" << endl; ms500();
	cout << "Please enter your username: "; cin >> username;
	cout << "Enter your password: "; cin >> password;
	ifstream file("credentials.txt");
	if(file.is_open()){
		while(file >> storedUser >> storedPass){
			if(storedUser == username && storedPass == password){
				system("cls"); loading(); txtAnimation("Account identified!", 10);
				file.close(); s2(); return true;
			}
		}
		file.close(); system("cls"); loading();
		txtAnimation("Invaid username or password! Please try again.", 10); s2();
		return false; 
	}
}
bool codeInter(){
	int IDcode, storedCode; cout << "Enter your ID Code: "; 
	cin >> IDcode; ifstream code("IDcode.txt");
	if(code.is_open()){
		while(code >> storedCode){
			if(storedCode == IDcode){
				system("cls"); loading(); 
				txtAnimation("Admin code identified, Admin log-in successful!", 10);
				code.close(); s2(); return true;
			}
		}
		code.close(); system("cls"); loading();
		txtAnimation("Invalid ID code, Log-in terminated!", 10); s2();
		return false;
	}
}
int loginSys() { // Menu definition (Loops)
    int choice;

    do {
        system("cls");
        cout << "What would you like to do?" << endl;
        cout << "(1) Register\n(2) Login\n(3) Admin Log-in\n(4) Exit" << endl;
        cout << "Please input a number: ";

        if (!(cin >> choice)) { // User Input Symbols or Numbers
            cin.clear(); // Clears input if error
            cin.ignore(10000, '\n'); // Ignores Invalid
            cout << "Invalid Main Menu choice! Please enter a number." << endl;
            s2();
            continue; // Loop
        }

        if (choice == 1) {
            system("cls"); loading(); registration();
        } 
        else if (choice == 2) {
            system("cls"); loading();
            if (login()) {
                system("cls"); loading(); localMenu();
            }
        } 
        else if (choice == 3) {
            system("cls"); loading();
            if (adminLogin()) {
                system("cls");
                if (codeInter()) {
                    system("cls"); loading(); adminMenus();
                }
            }
        } 
        else if (choice == 4) {
            system("cls");
            txtAnimation("Thank you for using our system!!", 10); s2();
            system("cls"); txtAnimation(":D", 10);
        } 
        else {
            cout << "Invalid Main Menu choice! Please select between 1 and 4." << endl;
            s2();
        }

    } while (choice != 4);

    return 0;
}

