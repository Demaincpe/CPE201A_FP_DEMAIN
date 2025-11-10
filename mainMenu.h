#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>
#include <vector>
using namespace std;
// ===== FUNCTION PROTOTYPES =====
void adminMenus();
void localMenu();
void createPost();
void editPost();
void addComment();
void addReaction();
void deletePosts();
string getTimeStamp();
struct Post {
    string name;
    string postedDate;
    string startDate;
    string finishDate;
    string status;
    double taxes;
    double investment;
    string feedback;
    string content;
};
vector<Post> loadPosts();
// ===== FILES USED =====
extern string DATA_FILE;
extern string ARCHIVE_FILE;

#endif
