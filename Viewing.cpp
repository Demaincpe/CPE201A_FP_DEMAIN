#include "Viewing.h"
#include "mainMenu.h"
#include "Design.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits>

// ===== VIEW POST(FOR LOCAL USERS) =====
void view() {
    ifstream file(DATA_FILE);
	if (!file.is_open()) {
        txtAnimation("No post file found.", 10); cout << "\n"; return;
        txtAnimation("Press enter to return to the menu...", 10); cin.get();
    }
    file.seekg(0, ios::end); // Move file pointer to the end to check if it's empty
    if (file.tellg() == 0) {
        txtAnimation("No post found.", 10); cout << "\n";
        txtAnimation("Press enter to return to the menu...", 10); cin.get();
        file.close(); return;
    }
	file.seekg(0, ios::beg); // Reset pointer to the beginning before reading
    txtAnimation("All Existing Projects:", 10);
    s1(); cout << "\n\n"; string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    int filter; //Filter out by date or investment amount
    do {
        cout << "(0) Return to Main Menu   (1) Filters\n";
        cout << "Enter your choice: "; cin >> filter; cin.ignore();
        switch (filter) {
        	case 0: return;
            case 1: filters(); break;
            default: txtAnimation("Invalid choice. Please try again!", 10); cout << "\n";
        }
    } while (filter != 1);
}
// ===== VIEW POSTS(FOR ADMINS) =====
void viewPosts() {
    ifstream file(DATA_FILE);
    if (!file.is_open()) {
        txtAnimation("No post file found.", 10); cout << "\n"; return;
        txtAnimation("Press enter to return to the menu...", 10); cin.get();
    }
    file.seekg(0, ios::end); // Move file pointer to the end to check if it's empty
    if (file.tellg() == 0) {
        txtAnimation("No post found.", 10); cout << "\n";
        txtAnimation("Press enter to return to the menu...", 10); cin.get();
        file.close(); return;
    }
	file.seekg(0, ios::beg); // Reset pointer to the beginning before reading
    txtAnimation("All Existing Projects:", 10); 
	s1(); cout << "\n"; string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    int filter; //Filter out by date or investment amount
    do {
        cout << "(0) Return to Main Menu   (1) Filters   (2) Edit post\n";
        cout << "Enter your choice: "; cin >> filter; cin.ignore();
        switch (filter) {
        	case 0: return;
            case 1: filters(); break;
            case 2: editPost(); break;
            default: txtAnimation("Invalid choice. Please try again!", 10); cout << "\n";
        }
    } while (filter != 1);
}
// ===== FILTERING MENU FUNCTION =====
void filters() {
	int choice; vector<Post> posts = loadPosts();
  	while (choice != 0){
        system("cls");
        cout << "Filter by:\n";
        cout << "(1) Newest\n(2) Oldest\n";
        cout << "(3) Investment amount\n(4) Main Menu\n";
        cout << "Enter choice: "; cin >> choice; cin.ignore();
		//Filtering process
		switch(choice){
			case 1: 
				sort(posts.begin(), posts.end(), [](const Post &a, const Post &b) {
            		return a.postedDate > b.postedDate;
				}); break;
            case 2: 
				sort(posts.begin(), posts.end(), [](const Post &a, const Post &b) {
                	return a.postedDate < b.postedDate;
            	}); break;
            case 3: 
				sort(posts.begin(), posts.end(), [](const Post &a, const Post &b) {
                	return a.investment > b.investment;
            	}); break;
			case 4: 
				return; break; 
			default: 
				cout << "\n"; txtAnimation("Invalid choice!", 10); cout << "\n"; 
				txtAnimation("Press enter to continue...", 10); cin.get(); continue;
		}
		//Filtered Posts output
        system("cls"); cout << "Filtered results:\n\n";
        for (const auto &p : posts) {
            cout << p.content << endl;
        }
        txtAnimation("Press enter to return to filters...", 10); cin.get();
    } 
}
// ===== VIEW ARCHIVES =====
void viewArchive() {
    ifstream file(ARCHIVE_FILE);
    if (!file.is_open()) {
        txtAnimation("No archives available!", 10); cout << "\n"; return;
        txtAnimation("Press enter to return to the menu...", 10); cin.get();
    }
    file.seekg(0, ios::end);
    if (file.tellg() == 0) {
        txtAnimation("No post found.", 10); cout << "\n";
        txtAnimation("Press enter to return to the menu...", 10); cin.get();
        file.close(); return;
    }
    file.seekg(0, ios::beg); txtAnimation("Archived Posts:", 10); s1();
	cout << "\n\n"; string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close(); txtAnimation("Press enter to return to the menu...", 10); 
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); cin.get();
}
// ===== VIEW POSTS FOR DELETION =====
void viewToDel(){
	ifstream file(DATA_FILE);
	if (!file.is_open()) {
        txtAnimation("No post file found.", 10); cout << "\n"; return;
        txtAnimation("Press enter to return to the menu...", 10); cin.get();
    }
    file.seekg(0, ios::end); // Move file pointer to the end to check if it's empty
    if (file.tellg() == 0) {
        txtAnimation("No post found.", 10); cout << "\n";
        txtAnimation("Press enter to return to the menu...", 10); cin.get();
        file.close(); return;
    }
	file.seekg(0, ios::beg); // Reset pointer to the beginning before reading
    txtAnimation("All Existing Projects:", 10);
    s1(); cout << "\n\n"; string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
