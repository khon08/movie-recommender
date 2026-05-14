#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "User.h"
#include "BaseManager.h"
using namespace std;

class UserManager : public BaseManager {
private:
    vector<User> users;
public:
    void addUser(const User& user);
    void printAll() const;
    User* findById(int id);
    void loadFromFile(const string& filename) override;
    void saveToFile(const string& filename) const override;
    int size() const override { return users.size(); }
};
#endif
