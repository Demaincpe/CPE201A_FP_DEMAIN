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
#include <limits>
using namespace std;

string DATA_FILE = "government_posts.txt";
string ARCHIVE_FILE = "archived_posts.txt";
// ===== ADMIN MENU =====
void adminMenus() {
    int Achoice;
    do {
        system("cls");
        cout << "Welcome to the Admin Main Menu!!\n"; 
        s1();
        cout << "(1) Create Project Post\n(2) View All Posts\n";
        cout << "(3) Add Comment to Latest Post\n";
        cout << "(4) React to Latest Post (Like/Dislike)\n";
        cout << "(5) View Archives\n(6) Delete Posts\n(7) Log-out\n";
        cout << "Enter choice: ";

        if (!(cin >> Achoice)) { // Handle invalid input Symbols and letters 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore everything until user enters
            txtAnimation("Invalid choice! Please enter a number.", 10);
            s2();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear leftover input

        switch (Achoice) {
            case 1: createPost(); break;
            case 2: viewPosts(); break;
            case 3: addComment(); break;
            case 4: addReaction(); break;
            case 5: viewArchive(); break;
            case 6: deletePosts(); break;
            case 7: txtAnimation("Logging out...", 10); break;
            default: txtAnimation("Invalid choice. Please try again!!", 10); s2();
        }
    } while (Achoice != 7);
}
// ===== LOCAL MENU =====
void localMenu() {
    int Lchoice = 0;
    do {
        system("cls");
        cout << "Welcome to the Main Menu!!\n"; 
        s1();
        cout << "(1) View All Posts\n(2) Add Comment to Latest Post\n";
        cout << "(3) React to Latest Post (Like/Dislike)\n";
        cout << "(4) View Archives\n(5) Log-out\n";
        cout << "Enter choice: ";

        if (!(cin >> Lchoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore everything until user enters
            txtAnimation("Invalid choice! Please enter a number.", 10);
            s2();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (Lchoice) {
            case 1: view(); break;
            case 2: addComment(); break;
            case 3: addReaction(); break;
            case 4: viewArchive(); break;
            case 5: txtAnimation("Logging out...", 10); break;
            default: txtAnimation("Invalid choice. Please try again!!", 10); s2();
        }
    } while (Lchoice != 5);
}
// ===== CREATE POST =====
void createPost() {
    system("cls"); loading(); string name, status, feedback, startDate, finishDate;
    double taxes, investment; cout << "Create a new project post!\n";
    cout << "Project Name: "; getline(cin, name);
    cout << "Taxes Used (P): "; cin >> taxes;
    cout << "Amount Invested (P): "; cin >> investment; cin.ignore();
    cout << "Status (Ongoing/Completed): "; getline(cin, status);
    cout << "Official Start Date (YYYY-MM-DD): "; getline(cin, startDate);
    cout << "Official Finish Date (YYYY-MM-DD): "; getline(cin, finishDate);
    cout << "Official Feedback: "; getline(cin, feedback);
    ofstream file(DATA_FILE, ios::app);
    if (!file) {
        txtAnimation("There's an error in opening the file!!", 10);
        return;
    }
    file << fixed << setprecision(2);
    file << "Project: " << name << "\n";
    file << "Posted Date: " << getTimeStamp() << "\n";
    file << "Start Date: " << startDate << "\n";
    file << "Finish Date: " << finishDate << "\n";
    file << "Status: " << status << "\n";
    file << "Taxes Used: P" << taxes << "\n";
    file << "Invested: P" << investment << "\n";
    file << "Official Feedback: " << feedback << "\n";
    file << "Likes: 0\n"; file << "Dislikes: 0\n";
    file << "Comments:\n";
    file << "-----------------------------\n\n";
    file.close(); txtAnimation("Project post saved successfully!", 10); s2();
}
// ===== VIEW POST(FOR LOCAL USERS) =====
void view() {
    system("cls"); loading(); ifstream file(DATA_FILE);
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
    system("cls"); loading(); ifstream file(DATA_FILE);
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
// ==== READS INFORMATION'S POST FOR FILTERING AND EDIT POST ====
vector<Post> loadPosts() {
    ifstream file(DATA_FILE); vector<Post> posts;
    if (!file) {
    	return posts;
	}
    string line, block; Post current;
	while (getline(file, line)) {
        block += line + "\n";
        if (line.find("Project: ") != string::npos)
            current.name = line.substr(9);
        else if (line.find("Posted Date: ") != string::npos)
            current.postedDate = line.substr(13);
        else if (line.find("Start Date: ") != string::npos)
            current.startDate = line.substr(12);
        else if (line.find("Finish Date: ") != string::npos)
            current.finishDate = line.substr(13);
        else if (line.find("Status: ") != string::npos)
            current.status = line.substr(8);
        else if (line.find("Taxes Used: P") != string::npos)
            current.taxes = stod(line.substr(13));
        else if (line.find("Invested: P") != string::npos)
            current.investment = stod(line.substr(11));
        else if (line.find("Official Feedback: ") != string::npos)
            current.feedback = line.substr(19);
        else if (line.find("-----------------------------") != string::npos) {
            current.content = block; posts.push_back(current); block.clear();
        }
    }
    file.close(); s2(); return posts;
}
// ===== FILTERING MENU FUNCTION =====
void filters() {
    int choice = -1; 
    vector<Post> posts;

    while (choice != 0) {
        system("cls");
        cout << "Filter by:\n";
        cout << "(1) Newest\n(2) Oldest\n";
        cout << "(3) Investment amount\n(0) Main Menu\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) { // invalid input check
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            txtAnimation("Invalid input! Please enter a number.", 10);
            s2();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        posts = loadPosts();

        switch (choice) {
            case 1:
                sort(posts.begin(), posts.end(), [](const Post &a, const Post &b) {
                    return a.postedDate > b.postedDate;
                });
                break;
            case 2:
                sort(posts.begin(), posts.end(), [](const Post &a, const Post &b) {
                    return a.postedDate < b.postedDate;
                });
                break;
            case 3:
                sort(posts.begin(), posts.end(), [](const Post &a, const Post &b) {
                    return a.investment > b.investment;
                });
                break;
            case 0:
                return;
            default:
                txtAnimation("Invalid choice! Please try again.", 10);
                s2();
                continue;
        }

        // Display filtered results
        system("cls");
        cout << "Filtered results:\n\n";
        for (const auto &p : posts) {
            cout << p.content << endl;
        }
        txtAnimation("Press enter to return to filters...", 10);
        cin.get();
    }
}
// ===== EDIT POST =====
void editPost() {
	vector<Post> posts = loadPosts(); system("cls"); loading();
    if (posts.empty()) {
        txtAnimation("No posts found!", 10); cout << "\n"; return;
    }
    // Display posts with numbers
    cout << "Select a post to edit: \n";
    for (size_t i = 0; i < posts.size(); ++i) {
        cout << i + 1 << ". " << posts[i].name << " (" << posts[i].status << ")\n";
    }
    int choice; cout << "\nEnter post number to edit(Enter 0 to cancel): ";
    cin >> choice; cin.ignore();
	if (choice == 0 || choice > posts.size()) return;
	Post &p = posts[choice - 1];
	// Show current info
    system("cls");
    cout << "Editing post: " << p.name << "\n";
    cout << "Leave blank to keep existing value.\n\n"; string input;
    cout << "New Project Name (" << p.name << "): "; getline(cin, input);
    if (!input.empty()) p.name = input;
    cout << "New Taxes Used (current: " << p.taxes << "): "; getline(cin, input);
    if (!input.empty()) p.taxes = stod(input);
    cout << "New Investment (current: " << p.investment << "): "; getline(cin, input);
    if (!input.empty()) p.investment = stod(input);
    cout << "New Status (" << p.status << "): "; getline(cin, input);
    if (!input.empty()) p.status = input;
    cout << "New Start Date (" << p.startDate << "): "; getline(cin, input);
    if (!input.empty()) p.startDate = input;
    cout << "New Finish Date (" << p.finishDate << "): "; getline(cin, input);
    if (!input.empty()) p.finishDate = input;
    cout << "New Feedback (" << p.feedback << "): "; getline(cin, input);
    if (!input.empty()) p.feedback = input;
    // Rewrite file
    ofstream file(DATA_FILE, ios::trunc);
    for (const auto &post : posts) {
        file << fixed << setprecision(2);
        file << "Project: " << post.name << "\n";
        file << "Posted Date: " << post.postedDate << "\n";
        file << "Start Date: " << post.startDate << "\n";
        file << "Finish Date: " << post.finishDate << "\n";
        file << "Status: " << post.status << "\n";
        file << "Taxes Used: P" << post.taxes << "\n";
        file << "Invested: P" << post.investment << "\n";
        file << "Official Feedback: " << post.feedback << "\n";
        file << "Likes: 0\n"; file << "Dislikes: 0\n";
        file << "Comments:\n"; file << "-----------------------------\n";
    }
    file.close();
    cout << "\n"; txtAnimation("Post updated successfully!!", 10); cout << "\n"; s2();
}
// ===== ADD COMMENT TO LATEST POST =====
void addComment() {
    system("cls"); loading(); ifstream inFile(DATA_FILE);
    if (!inFile) {
        cout << "No posts available.\n"; return;
    }
    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close(); size_t pos = content.rfind("-----------------------------");
    if (pos == string::npos){
    	txtAnimation("No posts found!", 10); cout << "\n"; return;
    }
    string comment;
    cout << "Enter your comment: "; getline(cin, comment);
    content.insert(pos, "Comment: " + comment + "\n");
    ofstream outFile(DATA_FILE);
    outFile << content;
    outFile.close();
    cout << "\n"; txtAnimation("Comment added successfully", 10); cout << "\n"; s2();
}
// ===== ADD REACTION =====
void addReaction() {
    system("cls"); loading();
    // Open the post file to read
    ifstream inFile(DATA_FILE);
    if (!inFile) {
        txtAnimation("No posts found!", 10); cout << "\n"; return;
    }
    // Read the entire file content into a string
    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();
    // Find the last occurrence of "Likes:" and "Dislikes:"
    size_t likePos = content.rfind("Likes:");
    size_t dislikePos = content.rfind("Dislikes:");
    // If not found, stop
    if (likePos == string::npos || dislikePos == string::npos) {
        txtAnimation("No posts with reaction found!", 10); cout << "\n"; return;
    }
    // Get current like and dislike counts
    int likes = 0, dislikes = 0;
    try {
        likes = stoi(content.substr(likePos + 6)); // extract number after "Likes:"
        dislikes = stoi(content.substr(dislikePos + 9)); // extract number after "Dislikes:"
    } catch (...) {
        txtAnimation("Error reading like/dislike counts!", 10); cout << "\n"; return;
    }
    // Ask user for reaction
    int choice; cout << "React to the latest post/s:\n";
    cout << "(1) Like\n(2) Dislike\nEnter choice: "; cin >> choice;
    if (choice == 1) likes++; else if (choice == 2) dislikes++;
    else {
        txtAnimation("Invalid input!", 10); cout << "\n"; return;
    }
    // Replace the lines in the content string with updated counts
    size_t likeEnd = content.find('\n', likePos);
    size_t dislikeEnd = content.find('\n', dislikePos);
    content.replace(likePos, likeEnd - likePos, "Likes: " + to_string(likes));
    content.replace(dislikePos, dislikeEnd - dislikePos, "Dislikes: " + to_string(dislikes));
    // Save updated content back to the file
    ofstream outFile(DATA_FILE);
    if (!outFile) {
        txtAnimation("There's an error saving reactions!", 10); cout << "\n"; return;
    }
    outFile << content; outFile.close();
    txtAnimation("Reaction recorded successfully!!", 10); cout << "\n"; s2();
}
// ===== VIEW ARCHIVES =====
void viewArchive() {
    system("cls"); loading(); ifstream file(ARCHIVE_FILE);
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
    file.close(); txtAnimation("Press enter to return to the menu...", 10); cin.get();
    system("cls"); loading();
}
// ===== DELETE ALL POSTS =====
void deletePosts(){
	system("cls"); loading(); cout << "Here are the Active Current Projects:\n"; 
	view(); string title, line; bool found = false;
    cout << "\nInput the EXACT Project Title to Delete and Transfer to the Archives\n";
    getline(cin, title); ifstream readFile(DATA_FILE); // READS POST
    ofstream tempFile("TemporaryPosts.txt"); // TEMPORARY SAVE FILE
    ofstream archive(ARCHIVE_FILE, ios::app); // STORES DELETED POSTS
    if (!readFile) {
        txtAnimation("No posts found", 10); cout << "\n"; return;
    }
    string postBlock = ""; string currentTitle = "";
    while (getline(readFile, line)) {
        // Detect start of a new post
        if (line.find("Project: ") != string::npos) {
            // If we already have a previous post, check if it's the one to archive
            if (!postBlock.empty()) {
                if (currentTitle == title) {
                    found = true; archive << postBlock;
                    archive << "Archived On: " << getTimeStamp() << endl;
                    archive << "--------------------------------------" << endl;
                } 
				else {
                    tempFile << postBlock;
                }
            }
            // Start capturing the new post
            currentTitle = line.substr(line.find(":") + 2); postBlock = line + "\n";
        }
		else {
            postBlock += line + "\n";
        }
    }
    // Handle the last post in the file
    if (!postBlock.empty()) {
        if (currentTitle == title) {
            found = true; archive << postBlock;
            archive << "Archived On: " << getTimeStamp() << endl;
            archive << "--------------------------------------" << endl;
        } 
		else {
            tempFile << postBlock;
        }
    }
	readFile.close(); tempFile.close(); archive.close();
    remove("government_posts.txt"); rename("TemporaryPosts.txt", "government_posts.txt");
    if(found){
    	txtAnimation("Post archived successfully!", 10); cout << "\n"; s2();
	}
    else{
    	txtAnimation("Post not found. Make sure your title matches exactly!!", 10); 
		cout << "\n"; s2();	
	}
}
// ===== TIME STAMPS =====
string getTimeStamp(){
	time_t now = time(0);
	tm *ltm = localtime(&now); 
	char buffer[40];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
	return string(buffer);
}
