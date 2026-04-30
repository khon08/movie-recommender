#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "User.h"
using namespace std;

class UserManager {
private:
    vector<User> users;
public:
    void addUser(const User& user);
    void printAll() const;
    User* findById(int id);
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename) const;
};
#endif
