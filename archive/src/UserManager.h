#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <vector>
#include <string>
#include "User.h"

class UserManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& user);
    void printAll() const;

    // 특정 ID로 유저 찾기
    User* findById(int id);

    // 파일 I/O
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
};

#endif